#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4, 640, 600)
{};

void Ball::initBall()
{
    setSpeed(2);
    setColor(Color::Cyan);
};

