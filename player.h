#ifndef PLAYER_H
#define PLAYER_H
#include "tankbase.h"

class player:public tankbase
{
public:
    bool move;
    player();
    void setDir(direct) override;
};


#endif // PLAYER_H
