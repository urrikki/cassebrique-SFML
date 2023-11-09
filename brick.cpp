#include "brick.h"
#include <vector>

using namespace sf;

Brick::Brick() : gameObject(80,30,640,360,Color::Cyan)
{
    life = 3;
};

void Brick::OnCollisionEnter(gameObject* object)
{
    setColor(Color::Green);
}

void Brick::OnCollisionStay()
{

}

void Brick::OnCollisionExit()
{
    
}
