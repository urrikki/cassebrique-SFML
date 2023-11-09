#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "brick.h"
#include "ball.h"
#include "canon.h"


using namespace sf;

Brick myBrick;
Ball myBall;
Canon myCanon;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    myBrick.initBrick();
    myBall.initBall();
    myCanon.initCanon();
    Time frameTime = seconds(1.0f / 60.0f);

    float elaspedTimeF = 0.f;
    Clock clock;
    myBall.setOrientation(10.0, -75.0);
    bool click = false;
    bool shot = false;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button ==Mouse::Left)
                {
                    std::cout << "miaouuu";
                    click = true;
                }
            }
        }
        

        window.clear();
        myBrick.drawShape(window);
        myCanon.rotateTowardsMouse(window);

        if (click == true)
        {
            if (shot == false)
            {
                myBall.setPosition(myCanon.x - myCanon.w / 2, myCanon.y - myCanon.h);
                myBall.setOrientation(std::cos(myCanon.angle * M_PI / 180.0f) , std::sin(myCanon.angle * M_PI / 180.0f));
                shot = true;
            }
            myBall.drawShape(window);
            myBall.moveBall(elaspedTimeF);
            myBall.rebound(myBall.getCollideSide(myBrick));
        }
        myCanon.drawShape(window);
        window.display();


        Time elapsedTime = clock.restart();
        elaspedTimeF = elapsedTime.asSeconds();
    }

    return 0;
}