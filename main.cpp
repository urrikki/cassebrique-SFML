#include <SFML/Graphics.hpp>
#include "brick.h"

using namespace sf;

Brick myBrick;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    myBrick.oneBrick();

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
        window.display();
    }

    return 0;
}