#pragma once
#include "gameObject.h"

class Brick : public gameObject
{
public:
    int life;

    Brick();

    virtual void OnCollisionEnter(gameObject* object);
    virtual void OnCollisionStay();
    virtual void OnCollisionExit();
};