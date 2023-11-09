#include "ball.h"
#include <vector>

using namespace sf;

Ball::Ball() : gameObject(4, 640, 600,Color::Yellow)
{};

void Ball::initBall()
{
    setSpeed(100);
};

void Ball::OnCollisionEnter(gameObject object)
{
    rebound(getCollideSide(object));
}

void Ball::OnCollisionStory()
{

}

void Ball::OnCollisionExit()
{

}
