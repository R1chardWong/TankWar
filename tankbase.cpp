#include "tankbase.h"
#include <QDebug>

void tankBase::shot()
{
    //子弹已经射出就 return
    if(bullet.getActive() == true)
        return;
    
    bullet.setActive(true);//如果没有射出子弹，就此时射出
    bullet.setDir(dir);
    
    //设置偏移量——坦克边缘到子弹边缘的距离
    int deviation = (SIZE-bullet.w)/2;

    //不同方向射出bullet
    if(dir == direct::up)
    {
        bullet.rect.setRect(rect.x()+deviation,rect.y(),bullet.w,bullet.h);
    }
    else if(dir == direct::down)
    {
        bullet.rect.setRect(rect.x()+deviation,rect.bottom()-bullet.h,bullet.w,bullet.h);
    }
    else if(dir == direct::left)
    {
        bullet.rect.setRect(rect.left(),rect.y()+deviation,bullet.h,bullet.w);
    }
    else if(dir == direct::right)
    {
        bullet.rect.setRect(rect.right()-bullet.h,rect.y()+deviation,bullet.h,bullet.w);
    }
}

void tankBase::move()
{
    //获取坦克的坐标
    int x = rect.x();
    int y = rect.y();
    if(dir == direct::up)
    {
        y -= speed;
    }
    else if(dir == direct::down)
    {
        y += speed;
    }
    else if(dir == direct::left)
    {
        x -= speed;
    }
    else if(dir == direct::right)
    {
        x += speed;
    }
    if(canReachable(x,y,this->dir))//如果能到达x,y
    {
        rect.moveTo(x,y);
    }
}

void tankBase::setDir(direct dir)
{
    this->dir=dir;
}

void tankBase::display(QPainter &paint,bool state)
{
    //state两个状态切换实现履带转动效果
    if(state)
    {
        if(dir==direct::up)
        {
            paint.drawPixmap(rect.x(),rect.y(),upimg1);
        }
        else if(dir==direct::down)
        {

            paint.drawPixmap(rect.x(),rect.y(),downimg1);
        }
        else if(dir==direct::left)
        {
            paint.drawPixmap(rect.x(),rect.y(),leftimg1);
        }
        else if(dir==direct::right)
        {
            paint.drawPixmap(rect.x(),rect.y(),rightimg1);
        }
    }
    else
    {
        if(dir==direct::up)
        {
            paint.drawPixmap(rect.x(),rect.y(),upimg2);
        }
        else if(dir==direct::down)
        {
            paint.drawPixmap(rect.x(),rect.y(),downimg2);
        }
        else if(dir==direct::left)
        {
            paint.drawPixmap(rect.x(),rect.y(),leftimg2);
        }
        else if(dir==direct::right)
        {
            paint.drawPixmap(rect.x(),rect.y(),rightimg2);
        }
    }
}

bool tankBase::canReachable(int x, int y,direct dir)
{
    //转换map坐标
    x /= BASESIZE;
    y /= BASESIZE;
    int x1(0);
    int y1(0);
    //偏移量的设置
    if(dir==direct::up)//上的方向的话，
    {
        x1 = x + 1;
        y1 = y;
    }
    else if (dir==direct::down)
    {
        y += 1;
        y1 = y;
        x1 = x + 1;
    }
    else if(dir==direct::left)
    {
        x1 = x;
        y1 = y+1;
    }
    else if(dir==direct::right)
    {
        x += 1;
        x1 = x;
        y1 = y + 1;
    }
    //判断是否越界
    if(x<0 || x1<0 || x>25 || x1>25 || y<0 || y1<0 || y>25 || y1>25)
    {
        return false;
    }
    //判断是否有障碍物
    else if(map[y][x]<='2'&&map[y1][x1]<='2')//注意行和列与x,y的关系
    {
        return true;
    }
    else
    {
        return false;
    }
}

tankBase::tankBase()
{
}

tankBase &tankBase::operator=(const tankBase &other)
{
    if(this==&other)return *this;
    upimg1=other.upimg1;
    upimg2=other.upimg2;
    downimg1=other.downimg1;
    downimg2=other.downimg2;
    leftimg1=other.leftimg1;
    leftimg2=other.leftimg2;
    rightimg1=other.rightimg1;
    rightimg2=other.rightimg2;
    speed=other.speed;
    rect=other.rect;
    dir=other.dir;
    bullet = other.bullet;
    return *this;
}

tankBase::tankBase(const tankBase &other)
{
    *this=other;
}

tankBase::~tankBase()
{

}
