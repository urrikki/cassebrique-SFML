#include "brick.h"
#include <vector>
#include<iostream>

using namespace sf;

Brick::Brick() : gameObject(80, 30, 640, 360, Color::Cyan)
{
    life = 3;
    isGhost = false;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    getCollideSide(object);
    if (Collide == CollideType::Enter)
    {
        this->life = life - 4;
        Collide = Stay;
    }
}

void Brick::OnCollisionStay()
{
    while (Collide == CollideType::Stay)
    {
        if (true)
        {
            Collide = Exit;
        }
    }
}

void Brick::OnCollisionExit()
{
    if (Collide == CollideType::Exit)
    {
        destroyBrick();
        Collide = NoCollide;
    }
}

void Brick::destroyBrick()
{
    if (life <= 0)
    {
        isGhost = true;
        setPosition(3000, 0);
    }    
}
