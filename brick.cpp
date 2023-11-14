#include "brick.h"

#include <vector>
#include<iostream>
#include <string>

using namespace sf;

Brick::Brick() : gameObject(80, 20, 640, 360, Color::Cyan)
{
    life = 3;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    getCollideSide(object);
    if (Collide == CollideType::Enter)
    {
        life - 3;
        setColor(sf::Color::Color(88,50,168));
        std::cout << "color" << std::endl;
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
