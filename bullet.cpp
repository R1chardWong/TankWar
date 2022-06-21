#include "bullet.h"
#include <QDebug>
Bullet::Bullet()
{
    w = 8;
    h = 12;
    speed = BASESIZE*2 / 3;
    flight = 0;
    bump = 0;
    //加载图片
    leftpic.load((ROOT+"\\pic\\bullet-0.gif").c_str());
    leftpic = resizePic(leftpic,h,w);
    //
    uppic.load((ROOT+"\\pic\\bullet-1.gif").c_str());
    uppic = resizePic(uppic,w,h);

    rightpic.load((ROOT+"\\pic\\bullet-2.gif").c_str());
    rightpic = resizePic(rightpic,h,w);

    downpic.load((ROOT+"\\pic\\bullet-3.gif").c_str());
    downpic = resizePic(downpic,w,h);
    bump3.load((ROOT+"\\pic\\bump3.gif").c_str());
    bump3 = resizePic(bump3,BASESIZE,BASESIZE);
    rect.setRect(-1,-1,0,0);
}

Bullet::Bullet(const Bullet &last)
{
    *this=last;
}

void Bullet::setDir(direct direction)
{
    this->dir=direction;
}

void Bullet::setFlight(bool a)//飞行状态
{
    flight = a;//获取飞行状态
    if(flight==0)
    {
        //设置偏移量
        int x = rect.x();//左上角坐标
        int y = rect.y();

        bump = 1;

        //上下方向
        if(dir==direct::up||dir ==direct::down)
        {
            x-=(BASESIZE-w)/2;//偏移量，从枪口射出
        }
        //左右方向
        else if(dir ==direct::left||dir == direct::right)
        {
            y-=(BASESIZE-w)/2;
        }
        bumpx = x;
        bumpy = y;
        rect.setRect(-1,-1,0,0);//设置初值
    }
}

bool Bullet::getFlight()//获取飞行状态
{
    return flight;
}

bool Bullet::Reach(int x, int y, direct dir)
{
    int tmpx(0);
    int tmpy(0);
    //转换map坐标
    x /= BASESIZE;
    y /= BASESIZE;
    if(dir==direct::up)//向上走
    {
        tmpx = x + 1;
        tmpy = y;
    }
    else if (dir==direct::down)
    {
        tmpy = y;
        tmpx = x + 1;
    }
    else if(dir==direct::left)
    {
        tmpx = x;
        tmpy = y+1;
    }
    else if(dir==direct::right)
    {
        tmpx = x;
        tmpy = y + 1;
    }
    //判断是否越界
    if(x<0 || tmpy<0 || x>25 || tmpx>25 || y<0 || tmpy<0 || y>25 || tmpy>25)
    {
        return false;
    }
    //判断是否有障碍物
    else if((map[y][x]<='2'||map[y][x]=='4')&&(map[tmpy][tmpx]<='2'||map[tmpy][tmpx]=='4'))
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
        //砖块碎了
        if(map[tmpy][tmpx]=='3')
        {
            map[tmpy][tmpx]='0';
        }
        if(map[y][x]=='5'||map[tmpy][tmpx]=='5')
        {
            QSound::play((ROOT+"sound\\bin.wav").c_str());
        }
        return false;
    }
}

void Bullet::move()
{
    if(getFlight()==0)
        return;
    int x = rect.x();
    int y = rect.y();
    //行进
    if(dir == direct::up)
    {
        y -= speed;//行进
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

    //判断能否射到，如果能，更新坐标
    if(Reach(x, y,dir))
    {
        rect.moveTo(x,y);
    }
    else
    {
        setFlight(0);
    }
}

void Bullet::show(QPainter &paint)
{
    if(!getFlight())//未发射 return
    {
        return;
    }
    if(dir==direct::up)
    {
        paint.drawPixmap(rect.x(),rect.y(),uppic);
    }
    else if(dir==direct::down)
    {
        paint.drawPixmap(rect.x(),rect.y(),downpic);
    }
    else if(dir==direct::left)
    {
        paint.drawPixmap(rect.x(),rect.y(),leftpic);
    }
    else if(dir==direct::right)
    {
        paint.drawPixmap(rect.x(),rect.y(),rightpic);
    }
}

void Bullet::Explosion(QPainter& paint)
{
    paint.drawPixmap(bumpx,bumpy,bump3);
}

Bullet &Bullet::operator=(const Bullet &other)
{
    if(this==&other)return *this;
    speed=other.speed;
    flight=other.flight;
    bump = other.bump;
    bumpx = other.bumpx;
    bumpy = other.bumpy;
    w=other.w;
    h=other.h;
    dir=other.dir;
    uppic=other.uppic;
    downpic=other.downpic;
    leftpic=other.leftpic;
    rightpic=other.rightpic;
    bump3=other.bump3;
    rect=other.rect;
    return *this;
}


Bullet::~Bullet()
{

}
