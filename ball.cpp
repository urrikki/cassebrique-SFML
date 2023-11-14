#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4, 1300, 600, Color::Yellow)
{};

void Ball::initBall()
{
    setSpeed(190);
};


void Ball::OnCollisionEnter(gameObject* object)
{
    CollideSide side = getCollideSide(object);
    if (Collide == CollideType::Enter)
    {
        
        rebound(side);
        
        
        Collide = Stay;
    }
    
}

void Ball::OnCollisionStay()
{
    while (Collide == CollideType::Stay)
    {
        if (true)
        {
            Collide = Exit;
        }
    }
}

void Ball::OnCollisionExit()
{
    if (Collide == CollideType::Exit)
    {
        Collide = NoCollide;
    }
}

void Ball::rebound(CollideSide side)
{
    if (side == CollideSide::Bottom || side == CollideSide::Top)
    {
        this->orientationY = orientationY * -1;
    }
    else if (side == CollideSide::Right || side == CollideSide::Left)
    {
        this->orientationX = orientationX * -1;
    }
}
