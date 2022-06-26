#include "player.h"
#include <QDebug>

player::player()
{
    //设置初始方向和初速度
    dir=up;
    move=0;
    speed=20;
    
    upimg1.load((ROOT+"pic\\0Player\\m0-1-1.gif").c_str());
    upimg1 = resizePic(upimg1,SIZE,SIZE);
    upimg2.load((ROOT+"pic\\0Player\\m0-1-2.gif").c_str());
    upimg2 = resizePic(upimg2,SIZE,SIZE);

    leftimg1.load((ROOT+"pic\\0Player\\m0-0-1.gif").c_str());
    leftimg1 = resizePic(leftimg1,SIZE,SIZE);
    leftimg2.load((ROOT+"pic\\0Player\\m0-0-2.gif").c_str());
    leftimg2 = resizePic(leftimg2,SIZE,SIZE);

    rightimg1.load((ROOT+"pic\\0Player\\m0-2-1.gif").c_str());
    rightimg1 = resizePic(rightimg1,SIZE,SIZE);
    rightimg2.load((ROOT+"pic\\0Player\\m0-2-2.gif").c_str());
    rightimg2 = resizePic(rightimg2,SIZE,SIZE);

    downimg1.load((ROOT+"pic\\0Player\\m0-3-1.gif").c_str());
    downimg1 = resizePic(downimg1,SIZE,SIZE);
    downimg2.load((ROOT+"pic\\0Player\\m0-3-2.gif").c_str());
    downimg2 = resizePic(downimg2,SIZE,SIZE);
}

void player::setDir(direct direction)
{
    this->dir=dir;
    move=1;
}
