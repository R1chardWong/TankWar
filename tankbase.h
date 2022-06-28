#ifndef TANKBASE_H
#define TANKBASE_H
#include "bullet.h"
#include <QPixmap>
#include <QPainter>

class tankBase
{
public:
    //加载坦克各个方向的图片
    QPixmap upimg1;
    QPixmap upimg2;
    QPixmap downimg1;
    QPixmap downimg2;
    QPixmap leftimg1;
    QPixmap leftimg2;
    QPixmap rightimg1;
    QPixmap rightimg2;
    int speed;//坦克速度（可改变-道具）
    QRect rect;//位置（矩形）
    direct dir;//坦克行进方向
    
    void shot();//坦克的射击函数
    Bullet bullet;
    virtual void move();
    //利用虚函数，分别在enemy和player里面实现
    virtual void setDir(direct);
    //设置坦克的方向
    virtual void display(QPainter&,bool);
    //展示坦克
    
    bool canReachable(int,int,direct);
    tankBase();//默认构造函数
    tankBase& operator=(const tankBase&);
    //坦克赋值重定义
    
    tankBase(const tankBase&);//含参构造
    ~tankBase();
};

#endif // TANKBASE_H
