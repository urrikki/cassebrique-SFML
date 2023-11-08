#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(50,50)
{
    life = 100;
};

void Brick::initBrick()
{
    setPosition(640, 360);
    setColor(Color::Cyan);
};
