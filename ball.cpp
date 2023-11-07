#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball(){};

void Ball::initBall()
{
    setPosition(640, 600);
    setColor(Color::Cyan);
    setSize(25);
};

void Ball::moveBall(float elapsedTimeF , CollideSide side)
{
    float movement = 50.f * elapsedTimeF;
    if (side == CollideSide::None || side == CollideSide::Bottom)
    {
        setPosition(x, y - movement);
    }
    else if (side == CollideSide::Top )
    {
        setPosition(x, y + movement);
    }
    else if (side == CollideSide::Right )
    {
        setPosition(x + movement, y);
    }
    else if (side == CollideSide::Left )
    {
        setPosition(x - movement , y);
    }
    
}


