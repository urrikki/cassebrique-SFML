#include "brick.h"
#include <vector>
#include<iostream>

using namespace sf;

Brick::Brick() : gameObject(80, 30, 640, 360, Color::Cyan)
{
    life = 4;
    isGhost = false;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    getCollideSide(object);
    if (Collide == CollideType::Enter)
    {
        this->life = life - 1;
        if (life == 3) {
            setColor(sf::Color(60, 250, 0)); // Green
        }
        else if (life == 2) {
            setColor(sf::Color(120,90,210)); //Purple
        }
        else if (life == 1) {
            setColor(sf::Color::Yellow); // Yellow
        }
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
