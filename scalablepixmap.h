#ifndef SCALABLEPIXMAP_H
#define SCALABLEPIXMAP_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class ScalablePixmap : public QWidget
{
    Q_OBJECT

public:
    ScalablePixmap(QWidget* parent = nullptr);
    void setPixmap(const QPixmap&);
    QSize sizeHint() const;

private:
    QPixmap pixmap;

protected slots:
    void paintEvent(QPaintEvent *pe);
};

#endif // SCALABLEPIXMAP_H
