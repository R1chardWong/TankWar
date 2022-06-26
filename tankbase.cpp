#include "tankbase.h"
#include <QDebug>

void tankbase::shot()
{

    if(bullet.getFlight()==1)//如果子弹已经射出
        return;
    bullet.setFlight(1);//如果没有射出子弹，就此时射出
    bullet.setDir(dir);

    //设置偏移量——坦克边缘到子弹边缘的距离
    int offset=(SIZE-bullet.w)/2;

    //不同方向射出bullet
    if(dir==direct::up)
    {
        bullet.rect.setRect(rect.x()+offset,rect.y(),bullet.w,bullet.h);
    }
    else if(dir == direct::down)
    {
        bullet.rect.setRect(rect.x()+offset,rect.bottom()-bullet.h,bullet.w,bullet.h);
    }
    else if(dir == direct::left)
    {
        bullet.rect.setRect(rect.left(),rect.y()+offset,bullet.h,bullet.w);
    }
    else if(dir == direct::right)
    {
        bullet.rect.setRect(rect.right()-bullet.h,rect.y()+offset,bullet.h,bullet.w);
    }
}

void tankbase::move()
{
    //获取坦克的坐标
    int x=rect.x();
    int y=rect.y();
    if(dir==direct::up)
        y-=speed;
    else if(dir==direct::down)
        y+=speed;
    else if(dir==direct::left)
        x-=speed;
    else if(dir==direct::right)
        x+=speed;
    if(Reach(x,y,this->dir))//如果能到达x,y
    {
        rect.moveTo(x,y);
    }
}

void tankbase::setDir(direct dir)
{
    this->dir=dir;
}

tankbase::tankbase()
{

}
