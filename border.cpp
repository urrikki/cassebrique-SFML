#include "border.h"
#include <vector>
#include<iostream>

using namespace sf;

Border::Border() : gameObject(20, 100, 0, 0, Color::Cyan)
{
};

void Border::OnCollisionEnter(gameObject* object)
{
    if (Collide == CollideType::Enter)
    {
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

