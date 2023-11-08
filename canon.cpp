#include "canon.h"
#include <vector>

using namespace sf;

Canon::Canon() : gameObject(60,40,640,650)
{
    setPosition(640, 700);
    setColor(Color::Magenta);
};

void Canon:: initCanon()
{
    setColor(Color::Magenta);
};
