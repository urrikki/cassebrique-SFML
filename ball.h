#pragma once
#include "gameObject.h"

class Ball : public gameObject
{
public:
    Ball();

    void initBall();
    /*virtual void OnCollisionEnter(CollideSide);
    virtual void OnCollisionStory();
    virtual void OnCollisionExit();*/
 
};