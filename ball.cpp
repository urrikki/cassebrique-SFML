#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4, 1300, 600, Color(220,150,30))
{};

void Ball::initBall()
{
    setSpeed(190);
};


void Ball::OnCollisionEnter()
{
    if (Collide == CollideType::Enter)
    {
        rebound(sideForRebound);
        Collide = Stay;
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
    side = None;
}
