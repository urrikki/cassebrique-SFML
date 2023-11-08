#include <SFML/Graphics.hpp>
#include <iostream>
#include "brick.h"
#include "ball.h"

using namespace sf;

Brick myBrick;
Ball myBall;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    myBrick.initBrick();
    myBall.initBall();
    Time frameTime = seconds(1.0f / 60.0f);

    float elaspedTimeF = 0.f;
    Clock clock;
    myBall.setOrientation(0.0, -75.0);
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
        
        myBall.moveBall(elaspedTimeF);
        myBall.rebound(myBall.getCollideSide(myBrick));
   
        window.display();


        Time elapsedTime = clock.restart();
        elaspedTimeF = elapsedTime.asSeconds();
    }

    return 0;
}