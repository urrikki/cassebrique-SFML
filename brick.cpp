#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(80,30)
{
    life = 100;
};

void Brick::oneBrick()
{
    setPosition(640, 360);
    setColor(Color::Blue);
    setSize(25);
};