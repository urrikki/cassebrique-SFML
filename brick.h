#pragma once
#include "gameObject.h"

class Brick : public gameObject
{
public:
    int life;

    Brick();

    void OnCollisionEnter(gameObject* objectTest) override;
    void OnCollisionExit(gameObject* objectTest) override;

    void lifeBrick();
    void setLife(int life);

};