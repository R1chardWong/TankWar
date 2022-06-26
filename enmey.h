#ifndef ENEMY_H
#define ENEMY_H
#include "tankbase.h"
#include "config.h"

class enemy:public tankbase
{
public:
    enemy();
    bool operator==(const enemy& last);//赋值重载
    virtual ~enemy();
};

#endif // ENEMY_H
