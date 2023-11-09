#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(80,30,640,360,Color::Cyan)
{
    life = 100;
};

