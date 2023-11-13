#include "brick.h"
#include <vector>
#include<iostream>

using namespace sf;

Brick::Brick() : gameObject(80, 30, 640, 360, Color::Cyan)
{
    life = 3;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    getCollideSide(object);
    if (Collide == CollideType::Enter)
    {
        life - 3;
        setColor(sf::Color::Color(250,0,0));
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
        Collide = NoCollide;
    }
}
