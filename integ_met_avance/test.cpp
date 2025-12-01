#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    CascadeClassifier glassesCascade;
    if(!glassesCascade.load("haarcascade_eye_tree_eyeglasses.xml")) {
        printf("Impossible de charger le cascade\n");
        return -1;
    }

    Mat img = imread("image.jpg");
    if(img.empty()) return -1;

    std::vector<Rect> glasses;
    glassesCascade.detectMultiScale(img, glasses, 1.1, 3);

    for(auto &g : glasses) {
        rectangle(img, g, Scalar(0, 255, 0), 2);
    }

    imshow("Detection Lunettes", img);
    waitKey(0);
    return 0;
}
