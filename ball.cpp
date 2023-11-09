#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4, 640, 600,Color::Blue)
{};

void Ball::initBall()
{
    setSpeed(100);
};

