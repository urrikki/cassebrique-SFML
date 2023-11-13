#include "border.h"
#include <vector>
#include<iostream>

using namespace sf;

Border::Border() : gameObject(20, 100, 0, 0, Color::Cyan)
{
    life = 3;
};

void Border::OnCollisionEnter(gameObject* object)
{
    if (Collide == CollideType::Enter)
    {
        life - 3;
        setColor(sf::Color::Color(250, 0, 0));
        Collide = Stay;
    }
}

void Border::OnCollisionStay()
{
    while (Collide == CollideType::Stay)
    {
        if (true)
        {
            Collide = Exit;
        }
    }
}

void Border::OnCollisionExit()
{
    if (Collide == CollideType::Exit)
    {
        Collide = NoCollide;
    }
}

