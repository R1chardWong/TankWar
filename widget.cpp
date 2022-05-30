#include "widget.h"
#include <QDebug>
#include <memory.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(WIDTH,HEIGHT);
    setWindowTitle("TANK WAR");
    setWindowIcon(QIcon(":/pic/icon.png"));//左上角图标
    setStyleSheet("background-color:black;");//背景颜色

    //画地图
    memset(map,0,sizeof(map));
    for (int i=2;i<=11;i++)
        map[i][2]=map[i][3]=1;
    for (int i=2;i<=11;i++)
        map[i][6]=map[i][7]=1;
    for (int i=2;i<=8;i++)
        map[i][10]=map[i][11]=1;
    for (int i=2;i<=8;i++)
        map[i][14]=map[i][15]=1;
    for (int i=2;i<=11;i++)
        map[i][18]=map[i][19]=1;
    for (int i=2;i<=11;i++)
        map[i][22]=map[i][23]=1;
    map[6][12]=map[6][13]=map[7][12]=map[7][13]=2;
    map[23][11]=map[24][11]=map[25][11]=1;
    map[23][14]=map[24][14]=map[25][14]=1;
    map[23][12]=map[23][13]=map[23][14]=1;
    for (int j=2;j<=9;j++)
        map[15][j]=2;
    for (int j=16;j<=23;j++)
        map[15][j]=2;
    for (int i=17;i<=23;i++)
        map[i][4]=map[i][5]=1;
    for (int i=17;i<=23;i++)
        map[i][20]=map[i][21]=1;
    map[11][10]=map[11][11]=map[12][10]=map[12][11]=1;
    map[11][14]=map[11][15]=map[12][14]=map[12][15]=1;
    for (int i=18;i<=21;i++)
        map[i][8]=1;
    for (int i=18;i<=21;i++)
        map[i][17]=1;
    for (int j=9;j<=16;j++)
        map[18][j]=map[19][j]=1;
    map[20][11]=map[20][12]=map[20][13]=map[20][14]=2;
    map[19][0]=map[19][1]=2;
    map[19][24]=map[19][25]=2;


    campRect.setRect(12*BASESIZE,24*BASESIZE,SIZE,SIZE);//初始化大本营矩形变量
    //加载图像
    camp.load(":/pic/camp0.gif");
    camp = resizePic(camp,SIZE,SIZE);
    brick.load(":/pic/wall.gif");
    brick = resizePic(brick,BASESIZE,BASESIZE);
    iron.load(":/pic/stone.gif");
    iron = resizePic(iron,BASESIZE,BASESIZE);
    bg_gray.load(":/pic/bg_gray.gif");
    bg_gray=resizePic(bg_gray,SIZE,SIZE);


}


void Widget::drawMap()
{
    for (int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(map[i][j]==1)
            {
                paint.drawPixmap(j*BASESIZE,i*BASESIZE,brick);
            }
            else if(map[i][j]==2)
            {
                paint.drawPixmap(j*BASESIZE,i*BASESIZE,iron);
            }
        }
    }
    paint.drawPixmap(campRect.x(),campRect.y(),camp);
}


void Widget::drawFrame()
{
    //画边框
    for(int i=0;i<15;i++)
    {
        paint.drawPixmap(0,i*SIZE,bg_gray);
        paint.drawPixmap(14*SIZE,i*SIZE,bg_gray);
        paint.drawPixmap(i*SIZE,0,bg_gray);
        paint.drawPixmap(i*SIZE,14*SIZE,bg_gray);
    }
}


void Widget::paintEvent(QPaintEvent *)
{

    paint.begin(this);
    //转换坐标系统
    paint.save();
    paint.translate(SIZE,SIZE);
    //画地图
    drawMap();

    //重置坐标系统
    paint.restore();

    //画边框
    drawFrame();

    paint.end();

}
