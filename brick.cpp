#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(80,30)
{
    life = 100;
};

void Brick::initBrick()
{
    setPosition(640, 360);
    setColor(Color::Cyan);
};
