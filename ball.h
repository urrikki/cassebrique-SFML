#pragma once
#include "gameObject.h"

class Ball : public gameObject
{
public:
    Ball();

    float orientationX;
    float orientationY;

    void setOrientation(float x, float y);

    void initBall();

    void moveBall(float elapsedTimeF);

    void rebound(CollideSide side);
};