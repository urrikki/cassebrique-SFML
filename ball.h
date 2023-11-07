#pragma once
#include "gameObject.h"

class Ball : public gameObject
{
public:
    Ball();

    void initBall();

    void moveBall(float elapsedTime , CollideSide side);
};