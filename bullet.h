#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QPainter>


class Bullet
{
private:
    int speed;//子弹速度
    bool active;//子弹是否在空中

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
    explicit Bullet();//不允许隐式类型转换
    Bullet(const Bullet&);//新子弹射出
    
    
    void setActive(bool);
    bool getActive();//获取状态
    void move();//子弹移动
    void setDir(direct);//设置子弹方向
    
    
    void display(QPainter&);//显示子弹
    bool canReachable(int,int,direct);//子弹能否到达目标
    Bullet& operator=(const Bullet&);
    
    void showExplosion(QPainter&);//展示爆炸效果
    ~Bullet();
};

#endif // BULLET_H
