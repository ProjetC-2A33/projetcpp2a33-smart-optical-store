#ifndef SALIARE_H
#define SALIARE_H

#include <QKeySequenceEdit>

class saliare : public QKeySequenceEdit
{
    Q_OBJECT

public:
    explicit saliare(QWidget *parent = nullptr);
    ~saliare();
};

#endif // SALIARE_H

