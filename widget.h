#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QIcon>

#define resizePic(p,w,h) p.scaled(w,h,Qt::AspectRatioMode::IgnoreAspectRatio,Qt::TransformationMode::SmoothTransformation)
#define WIDTH 600
#define HEIGHT 600
#define BASESIZE 20
#define SIZE 40

class Widget : public QWidget
{
private:
    int map[26][27];
    QPixmap brick;
    QPixmap iron;
    QPixmap camp;
    QPixmap bg_gray;
    QRect campRect;
    QPainter paint;

protected:
    void paintEvent(QPaintEvent *) override;//重载paintEvent
    void drawMap();//画地图
    void drawFrame();//画边框

public:
    Widget(QWidget *parent = nullptr);





};
#endif // WIDGET_H
