#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(20)
{};

void Ball::initBall()
{
    setPosition(640, 600);
    setColor(Color::Blue);
    float orientationX = 0.0;
    float orientationY = 0.0;
};

void Ball::setOrientation(float x, float y)
{
    this->orientationX = x;
    this->orientationY = y;

}

void Ball::moveBall(float elapsedTimeF)
{
    setPosition(x + (elapsedTimeF * orientationX), y + (elapsedTimeF * orientationY));
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