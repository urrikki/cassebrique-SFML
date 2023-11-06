#include <SFML/Graphics.hpp>
#include "gameObject.h"

using namespace sf;

gameObject mygame;

int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        mygame.drawSquare(window);
        window.display();
    }

    return 0;
}