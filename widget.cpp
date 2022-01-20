#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    scalPix = new ScalablePixmap;

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(slider_min, slider_max);

    open = new QPushButton("Open");

    QVBoxLayout* vbl = new QVBoxLayout;

    vbl->addWidget(scalPix);
    vbl->addWidget(slider);
    vbl->addWidget(open);

    setLayout(vbl);

    QObject::connect(open, &QPushButton::clicked, this, &Widget::openFile);

    QObject::connect(slider, &QSlider::valueChanged, this, &Widget::bluring);

    resize(200, 200);
}

void Widget::openFile()
{
    path = QFileDialog::getOpenFileName(nullptr, "Open a file");
    scalPix->setPixmap(QPixmap(path));
}
void Widget::bluring(int blurRadius)
{
    scalPix->setPixmap(QPixmap::fromImage(blurImage(QImage(path), blurRadius)));
}

QImage Widget::blurImage(QImage source, int blurRadius)
{
    if (source.isNull()) return QImage();

    QGraphicsScene scene;

    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);

    item.setGraphicsEffect(blur);
    scene.addItem(&item);

    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);

    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));

    return result;
}
