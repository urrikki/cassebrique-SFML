#include "brick.h"
#include <vector>
#include<iostream>

using namespace sf;

Brick::Brick() : gameObject(80,30,640,360,Color::Cyan)
{
    life = 3;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    if (getCollideSide(object) != CollideSide::None)
    {
        setColor(Color::Green);
    }   
}

void Brick::OnCollisionStay()
{

}

void Brick::OnCollisionExit()
{
    
}
