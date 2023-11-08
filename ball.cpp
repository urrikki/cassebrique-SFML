#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4, 640, 600)
{};

void Ball::initBall()
{
    setSpeed(100);
    setColor(Color::Cyan);
};

