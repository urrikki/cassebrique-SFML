#include "canon.h"
#include <vector>

using namespace sf;

Canon::Canon() : gameObject(60,40)
{
    setPosition(640, 700);
    setColor(Color::Magenta);
};

void Canon:: initCanon()
{
    setPosition(640, 650);
    setColor(Color::Magenta);
};
