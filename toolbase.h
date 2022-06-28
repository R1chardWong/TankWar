#ifndef TOOLBASE_H
#define TOOLBASE_H

#include <QPixmap>
#include <QPainter>
#include <config.h>

class toolBase//道具基类
{
public:
    QPixmap toolLook;//道具外观
    QRect rect;//道具矩形变量

    toolBase();
};

#endif // TOOLBASE_H
