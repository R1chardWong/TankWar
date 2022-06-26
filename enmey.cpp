#include "enemy.h"

enemy::enemy()
{
    //设初速度和初始方向
    speed=20;
    dir=down;
    rect.setRect(0*BASESIZE,0*BASESIZE,SIZE,SIZE);
    
    //加载
    upimg1.load((ROOT+"\\pic\\gray-tank\\1-2-1.gif").c_str());
    upimg1 = resizePic(upimg1,SIZE,SIZE);
    upimg2.load((ROOT+"\\pic\\gray-tank\\1-2-2.gif").c_str());
    upimg2 = resizePic(upimg2,SIZE,SIZE);

    leftimg1.load((ROOT+"\\pic\\gray-tank\\1-1-1.gif").c_str());
    leftimg1 = resizePic(leftimg1,SIZE,SIZE);
    leftimg2.load((ROOT+"\\pic\\gray-tank\\1-1-2.gif").c_str());
    leftimg2 = resizePic(leftimg2,SIZE,SIZE);

    rightimg1.load((ROOT+"\\pic\\gray-tank\\1-3-1.gif").c_str());
    rightimg1 = resizePic(rightimg1,SIZE,SIZE);
    rightimg2.load((ROOT+"\\pic\\gray-tank\\1-3-2.gif").c_str());
    rightimg2 = resizePic(rightimg2,SIZE,SIZE);

    downimg1.load((ROOT+"\\pic\\gray-tank\\1-4-1.gif").c_str());
    downimg1 = resizePic(downimg1,SIZE,SIZE);
    downimg2.load((ROOT+"\\pic\\gray-tank\\1-4-2.gif").c_str());
    downimg2 = resizePic(downimg2,SIZE,SIZE);
}

//赋值重定义
bool enemy::operator==(const enemy &last)
{
    if(this->rect==last.rect)
        return true;
    return false;
}

enemy::~enemy()
{

}
