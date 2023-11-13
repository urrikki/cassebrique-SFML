#pragma once
#include "gameObject.h"

class Ball : public gameObject
{
public:
    Ball();

    void initBall();

    void OnCollisionEnter(gameObject* object) override;
    void OnCollisionStay() override;
    void OnCollisionExit() override;

    void rebound(CollideSide side);

};