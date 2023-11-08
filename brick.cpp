#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(0,0)
{
    life = 100;
};

void Brick::initBrick()
{
    setPosition(640, 360);
    setColor(Color::Cyan);
};
