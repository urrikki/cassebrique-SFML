#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball()
{

};

void Ball::initBall()
{
    setPosition(640, 600);
    setColor(Color::Blue);
    setSize(25);
};