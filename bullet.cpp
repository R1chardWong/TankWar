#include "bullet.h"
#include <QDebug>
Bullet::Bullet()
{
    w = 8;
    h = 12;
    speed = 12;
    active = false;
    bump = false;
    leftimg.load((rootdir+"\\pic\\bullet-0.gif").c_str());
    leftimg = resizePic(leftimg,h,w);

    upimg.load((rootdir+"\\pic\\bullet-1.gif").c_str());
    upimg = resizePic(upimg,w,h);

    rightimg.load((rootdir+"\\pic\\bullet-2.gif").c_str());
    rightimg = resizePic(rightimg,h,w);

    downimg.load((rootdir+"\\pic\\bullet-3.gif").c_str());
    downimg = resizePic(downimg,w,h);

    bumpPic.load((rootdir+"\\pic\\bump.gif").c_str());
    bumpPic = resizePic(bumpPic,BASESIZE,BASESIZE);
    rect.setRect(-1,-1,0,0);
}

Bullet::Bullet(const Bullet &other)
{
    *this=other;
}

void Bullet::setActive(bool a)
{
    active = a;
    if(active==false)
    {
        bump = true;
        //这里设置偏移量
        int x = rect.x();
        int y = rect.y();
        if(dir==direct::up||dir ==direct::down)
        {
            x-=(BASESIZE-w)/2;
        }
        else if(dir ==direct::left||dir == direct::right)
        {
            y-=(BASESIZE-w)/2;
        }
        bumpx = x;
        bumpy = y;
        rect.setRect(-1,-1,0,0);
    }
}

bool Bullet::getActive()
{
    return active;
}

void Bullet::move()
{
    if(getActive()==false)
        return;
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

    //更新坐标
    if(canReachable(x, y,dir))
    {
        rect.moveTo(x,y);
    }
    else
    {
        setActive(false);
    }
}

void Bullet::setDir(direct dir)
{
    this->dir=dir;
}

void Bullet::display(QPainter &paint)
{
    if(!getActive())//未发射 return
    {
        return;
    }
    if(dir==direct::up)
    {
        paint.drawPixmap(rect.x(),rect.y(),upimg);
    }
    else if(dir==direct::down)
    {
        paint.drawPixmap(rect.x(),rect.y(),downimg);
    }
    else if(dir==direct::left)
    {
        paint.drawPixmap(rect.x(),rect.y(),leftimg);
    }
    else if(dir==direct::right)
    {
        paint.drawPixmap(rect.x(),rect.y(),rightimg);
    }
}

bool Bullet::canReachable(int x, int y, direct dir)
{
    //转换map坐标
    x /= BASESIZE;
    y /= BASESIZE;
    int x1(0);
    int y1(0);
    if(dir==direct::up)
    {
        x1 = x + 1;
        y1 = y;
    }
    else if (dir==direct::down)
    {
//        y += 1;
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
//        x += 1;
        x1 = x;
        y1 = y + 1;
    }
    //判断是否越界
    if(x<0 || x1<0 || x>25 || x1>25 || y<0 || y1<0 || y>25 || y1>25)
    {
//        qDebug()<<"子弹越界";
        return false;
    }
    //判断是否有障碍物
    else if((map[y][x]<='2'||map[y][x]=='4'||map[y][x]=='6')&&(map[y1][x1]<='2'||map[y1][x1]=='4'||map[y1][x1]=='6'))//注意行和列与x,y的关系
    {
        return true;
    }
    else
    {
        //打砖块
        if(map[y][x]=='3')
        {
            map[y][x]='0';
        }
        if(map[y1][x1]=='3')
        {
            map[y1][x1]='0';
        }
        return false;
    }
}

Bullet &Bullet::operator=(const Bullet &other)
{
    if(this==&other)return *this;
    speed=other.speed;
    active=other.active;
    bump = other.bump;
    bumpx = other.bumpx;
    bumpy = other.bumpy;
    w=other.w;
    h=other.h;
    dir=other.dir;
    upimg=other.upimg;
    downimg=other.downimg;
    leftimg=other.leftimg;
    rightimg=other.rightimg;
    bumpPic=other.bumpPic;
    rect=other.rect;
    return *this;
}

void Bullet::showExplosion(QPainter& paint)
{
    bump=false;
    paint.drawPixmap(bumpx,bumpy,bumpPic);
}

Bullet::~Bullet()
{

}

