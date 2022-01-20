#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>

#include <QFileDialog>

#include "scalablepixmap.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private:
    ScalablePixmap* scalPix;
    QSlider* slider;
    QPushButton* open;

    const int slider_min = 0;
    const int slider_max = 10;

    QVBoxLayout* vbl;
    QImage blurImage(QImage, int);

    QString path;

private slots:
    void openFile();
    void bluring(int);
};

#endif // WIDGET_H
