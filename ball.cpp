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
    rebound(getCollideSide(object));
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
