#include "brick.h"

#include <vector>
#include<iostream>

using namespace sf;

Brick::Brick() : gameObject(70, 20, 640, 360, Color::Cyan)
{
    life = 4;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    getCollideSide(object);
    if (Collide == CollideType::Enter)
    {
        this->life = life - 1;
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
        lifeBrick();
        Collide = NoCollide;
    }
}

void Brick::lifeBrick()
{
    if (life == 4)
    {
        setColor(sf::Color::Cyan); // Cyan
    }
    else if (life == 3) {
        setColor(sf::Color(60, 250, 0)); // Green
    }
    else if (life == 2) {
        setColor(sf::Color(120, 90, 210)); //Purple
    }
    else if (life == 1) {
        setColor(sf::Color::Yellow); // Yellow
    }
    else if (life <= 0)
    {
        isActive = false;
        setPosition(3000, 0);
    }    
}

void Brick::setLife(int life) {
    this->life = life;
}