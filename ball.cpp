#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4)
{};

void Ball::initBall()
{
    setPosition(640, 600);
    setColor(Color::Cyan);
};

