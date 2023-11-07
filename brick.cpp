#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick()
{
    life = 100;
};

void Brick::initBrick()
{
    setPosition(640, 360);
    setColor(Color::Cyan);
    setSize(25);
};