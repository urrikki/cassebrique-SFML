#pragma once
#include "gameObject.h"

class Brick : public gameObject
{
public:
    Brick();

    int life;

    void oneBrick();
};