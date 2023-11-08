#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(80,30,640,360)
{
    life = 100;
};

void Brick::initBrick()
{
    setColor(Color::Cyan);
};
