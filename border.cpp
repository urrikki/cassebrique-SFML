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
    if (getCollideSide(object) != CollideSide::None)
    {
        setColor(Color::Green);
    }
}

