#include "scalablepixmap.h"

ScalablePixmap::ScalablePixmap(QWidget *parent)
    : QWidget(parent){}

void ScalablePixmap::setPixmap(const QPixmap &p)
{
    pixmap = p;
    update();
}

void ScalablePixmap::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    painter.drawPixmap(pe->rect(), pixmap);

    QWidget::paintEvent(pe);
}

QSize ScalablePixmap::sizeHint() const
{
    return pixmap.size();
}
