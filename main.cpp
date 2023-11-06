#include <SFML/Graphics.hpp>
#include "brick.h"
#include "ball.h"

using namespace sf;

Brick myBrick;
Ball myBall;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    myBrick.oneBrick();
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
        myBrick.drawSquare(window);
        myBall.drawSquare(window);
        window.display();
    }

    return 0;
}