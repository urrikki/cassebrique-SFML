#pragma once
#include "gameObject.h"

class Brick : public gameObject
{
public:
    int life;

    Brick();

    void OnCollisionEnter() override;
    void OnCollisionExit() override;

    void lifeBrick();
    void setLife(int life);

};