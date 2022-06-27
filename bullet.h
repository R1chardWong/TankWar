#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QPainter>


class Bullet
{
private:
    int speed;
    bool active;

public:
    bool bump;
    int bumpx;
    int bumpy;
    int w;
    int h;
    direct dir;
    QPixmap upimg;
    QPixmap downimg;
    QPixmap leftimg;
    QPixmap rightimg;
    QPixmap bumpPic;
    QRect rect;
    explicit Bullet();
    Bullet(const Bullet&);
    void setActive(bool);
    bool getActive();
    void move();
    void setDir(direct);
    void display(QPainter&);
    bool canReachable(int,int,direct);
    Bullet& operator=(const Bullet&);
    void showExplosion(QPainter&);
    ~Bullet();
};

#endif // BULLET_H
