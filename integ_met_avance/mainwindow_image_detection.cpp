#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>

using namespace cv;

void MainWindow::on_pushButton_charger_image_clicked()
{
    // Ouvrir une boîte de dialogue pour sélectionner une image
    QString fileName = QFileDialog::getOpenFileName(this, 
        tr("Ouvrir une image"), "", 
        tr("Images (*.png *.xpm *.jpg *.jpeg *.bmp);;Tous les fichiers (*.*)"));
    
    if (fileName.isEmpty())
        return;
    
    // Charger l'image avec OpenCV
    Mat image = imread(fileName.toStdString());
    
    if (image.empty()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger l'image sélectionnée");
        return;
    }
    
    // Convertir l'image en niveaux de gris pour le traitement
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    
    // Appliquer un flou pour réduire le bruit
    GaussianBlur(grayImage, grayImage, Size(5, 5), 0);
    
    // Détecter les contours avec Canny
    Mat edges;
    Canny(grayImage, edges, 50, 150);
    
    // Trouver les contours
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(edges, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    
    // Dessiner les contours sur l'image originale
    Mat result = image.clone();
    drawContours(result, contours, -1, Scalar(0, 255, 0), 2);
    
    // Afficher le nombre d'objets détectés
    QString infoText = QString("Objets détectés: %1").arg(contours.size());
    ui->label_info_detection->setText(infoText);
    
    // Convertir l'image OpenCV en QImage pour l'affichage
    QImage qImage = MatToQImage(result);
    
    // Afficher l'image dans le QLabel
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(ui->label_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_image->setPixmap(pixmap);
    
    // Sauvegarder l'image de résultat
    currentProcessedImage = result.clone();
}

void MainWindow::on_pushButton_detecter_formes_clicked()
{
    if (currentProcessedImage.empty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez d'abord charger une image");
        return;
    }
    
    // Convertir en niveaux de gris
    Mat grayImage;
    cvtColor(currentProcessedImage, grayImage, COLOR_BGR2GRAY);
    
    // Seuillage pour binariser l'image
    Mat thresh;
    threshold(grayImage, thresh, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);
    
    // Trouver les contours
    std::vector<std::vector<Point>> contours;
    findContours(thresh, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
    
    // Copie de l'image pour le dessin
    Mat result = currentProcessedImage.clone();
    
    // Dictionnaire pour compter les formes
    std::map<std::string, int> shapeCount;
    shapeCount["Cercle"] = 0;
    shapeCount["Triangle"] = 0;
    shapeCount["Carré"] = 0;
    shapeCount["Rectangle"] = 0;
    shapeCount["Polygone"] = 0;
    
    // Analyser chaque contour
    for (size_t i = 0; i < contours.size(); i++) {
        // Ignorer les petits contours
        double area = contourArea(contours[i]);
        if (area < 1000) continue;
        
        // Approximation du contour
        double peri = arcLength(contours[i], true);
        std::vector<Point> approx;
        approxPolyDP(contours[i], approx, 0.04 * peri, true);
        
        // Déterminer la forme
        std::string shape = "Inconnu";
        
        if (approx.size() == 3) {
            shape = "Triangle";
        }
        else if (approx.size() == 4) {
            // Vérifier si c'est un carré ou un rectangle
            Rect rect = boundingRect(approx);
            float aspectRatio = (float)rect.width / (float)rect.height;
            
            if (aspectRatio >= 0.95 && aspectRatio <= 1.05) {
                shape = "Carré";
            }
            else {
                shape = "Rectangle";
            }
        }
        else if (approx.size() > 4) {
            // Vérifier si c'est un cercle
            double area = contourArea(contours[i]);
            Rect rect = boundingRect(contours[i]);
            int radius = rect.width / 2;
            
            if (std::abs(1 - ((double)rect.width / (2 * radius))) <= 0.2 &&
                std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2) {
                shape = "Cercle";
            }
            else {
                shape = "Polygone";
            }
        }
        
        // Dessiner le contour et le nom de la forme
        drawContours(result, contours, static_cast<int>(i), Scalar(0, 255, 0), 2);
        
        // Calculer le centre pour placer le texte
        Moments M = moments(contours[i]);
        if (M.m00 != 0) {
            int x = static_cast<int>(M.m10 / M.m00);
            int y = static_cast<int>(M.m01 / M.m00);
            
            // Dessiner le nom de la forme
            putText(result, shape, Point(x - 30, y), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 2);
            
            // Compter les formes
            if (shapeCount.find(shape) != shapeCount.end()) {
                shapeCount[shape]++;
            }
        }
    }
    
    // Afficher les statistiques des formes détectées
    QString stats = "Détection des formes :\n";
    for (const auto& pair : shapeCount) {
        if (pair.second > 0) {
            stats += QString("%1: %2\n").arg(QString::fromStdString(pair.first)).arg(pair.second);
        }
    }
    
    ui->textEdit_resultats->setText(stats);
    
    // Mettre à jour l'image affichée
    QImage qImage = MatToQImage(result);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(ui->label_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_image->setPixmap(pixmap);
}

void MainWindow::on_pushButton_reconnaissance_visage_clicked()
{
    if (currentProcessedImage.empty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez d'abord charger une image");
        return;
    }
    
    // Charger le classificateur en cascade pour la détection des visages
    QString cascadePath = QCoreApplication::applicationDirPath() + "/haarcascade_frontalface_default.xml";
    CascadeClassifier faceCascade;
    
    if (!faceCascade.load(cascadePath.toStdString())) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger le fichier de détection de visage");
        return;
    }
    
    // Convertir en niveaux de gris
    Mat grayImage;
    cvtColor(currentProcessedImage, grayImage, COLOR_BGR2GRAY);
    equalizeHist(grayImage, grayImage);
    
    // Détecter les visages
    std::vector<Rect> faces;
    faceCascade.detectMultiScale(grayImage, faces, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
    
    // Dessiner des rectangles autour des visages détectés
    Mat result = currentProcessedImage.clone();
    for (const auto& face : faces) {
        rectangle(result, face, Scalar(0, 255, 0), 2);
    }
    
    // Afficher le nombre de visages détectés
    QString infoText = QString("Visages détectés: %1").arg(faces.size());
    ui->label_info_detection->setText(infoText);
    
    // Mettre à jour l'image affichée
    QImage qImage = MatToQImage(result);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(ui->label_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_image->setPixmap(pixmap);
}

void MainWindow::on_pushButton_enregistrer_image_clicked()
{
    if (currentProcessedImage.empty()) {
        QMessageBox::warning(this, "Avertissement", "Aucune image à enregistrer");
        return;
    }
    
    // Demander à l'utilisateur où enregistrer l'image
    QString fileName = QFileDialog::getSaveFileName(this, 
        "Enregistrer l'image", 
        "", 
        "Images (*.png *.xpm *.jpg *.jpeg *.bmp);;Tous les fichiers (*.*)");
    
    if (fileName.isEmpty())
        return;
    
    // Enregistrer l'image
    if (!imwrite(fileName.toStdString(), currentProcessedImage)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'enregistrer l'image");
        return;
    }
    
    QMessageBox::information(this, "Succès", "L'image a été enregistrée avec succès");
}

// Fonction utilitaire pour convertir une image OpenCV en QImage
QImage MainWindow::MatToQImage(const Mat& mat)
{
    // Convertir le format de l'image selon le nombre de canaux
    switch (mat.type()) {
    // Format 8-bit, 4 canaux
    case CV_8UC4:
    {
        QImage image(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_ARGB32);
        return image.copy();
    }
    // Format 8-bit, 3 canaux
    case CV_8UC3:
    {
        QImage image(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    // Format 8-bit, 1 canal
    case CV_8UC1:
    {
        QImage image(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_Grayscale8);
        return image.copy();
    }
    default:
        qWarning() << "Format d'image non pris en charge";
        return QImage();
    }
}
