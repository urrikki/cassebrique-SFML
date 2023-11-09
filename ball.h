#pragma once
#include "gameObject.h"

class Ball : public gameObject
{
public:
    Ball();

    void initBall();
    virtual void OnCollisionEnter(gameObject object);
    virtual void OnCollisionStory();
    virtual void OnCollisionExit();
 
};