#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QPainter>
#include <QSound>

class Bullet
{
private:
    int speed;//子弹速度
    bool flight;//子弹是否在空中

public:
    QPixmap uppic;
    QPixmap downpic;
    QPixmap leftpic;
    QPixmap rightpic;
    QPixmap bump3;
    int w;
    int h;
    bool bump;
    int bumpx;
    int bumpy;
    direct dir;
    QRect rect;
    explicit Bullet();//不允许隐式类型转换
    Bullet(const Bullet&);//新子弹射出

    void setFlight(bool);//子弹是否在空中
    bool getFlight();//获取状态
    void move();//子弹移动
    void setDir(direct);//设置子弹方向
    void show(QPainter&);//显示子弹
    bool Reach(int,int,direct);//子弹能否到达目标
    Bullet& operator=(const Bullet&);
    void Explosion(QPainter&);//展示爆炸效果
    ~Bullet();
};

#endif // BULLET_H
