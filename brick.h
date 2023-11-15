#pragma once
#include "gameObject.h"

class Brick : public gameObject
{
public:
    int life;

    Brick();

    void OnCollisionEnter(gameObject* object) override;
    void OnCollisionStay() override;
    void OnCollisionExit() override;

    void lifeBrick();
    void setLife(int life);

};