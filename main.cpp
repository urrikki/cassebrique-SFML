#include <SFML/Graphics.hpp>
#include "brick.h"
#include "ball.h"

using namespace sf;

Brick myBrick;
Ball myBall;

int main()
{
    {
        int i = 0;
    }
    
    int* pi = new int;
    *pi = 0;
    delete pi;

    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    myBrick.initBrick();
    myBall.initBall();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        myBrick.drawShape(window);
        myBall.drawShape(window);
        window.display();
    }

    return 0;
}