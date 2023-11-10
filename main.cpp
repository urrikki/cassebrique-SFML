#define _USE_MATH_DEFINES

#include "brick.h"
#include "ball.h"
#include "canon.h"
#include "test.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


using namespace sf;

Brick myBrick;
Ball myBall;
Canon myCanon;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    myBall.initBall();
    Time frameTime = seconds(1.0f / 60.0f);

    float elaspedTimeF = 0.f;
    Clock clock;
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
                if (event.mouseButton.button == Mouse::Left)
                {
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
                myBall.setPosition(myCanon.x , myCanon.y - myCanon.h / 2);
                myBall.setOrientation(std::cos(myCanon.angle * M_PI / 180.0f) , std::sin(myCanon.angle * M_PI / 180.0f));
                shot = true;
            }
            myBall.drawShape(window);
            myBall.move(elaspedTimeF);
            myBrick.OnCollisionEnter(&myBall);
            myBall.OnCollisionEnter(&myBrick);
              
        }
        myCanon.drawShape(window);
        
        window.display();


        Time elapsedTime = clock.restart();
        elaspedTimeF = elapsedTime.asSeconds();
    }

    return 0;
}



//Test myTest;
//
//int main()
//{
//    RenderWindow window(VideoMode(1280, 720), "SFML works!");
//    myBall.initBall();
//    myTest.initTest();
//    Time frameTime = seconds(1.0f / 60.0f);
//
//    float elaspedTimeF = 0.f;
//    Clock clock;
//    bool click = false;
//    bool shot = false;
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//            else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased)
//            {
//                if (event.key.code == Keyboard::Z)
//                {
//                    myTest.orientationY = (event.type == Event::KeyPressed) ? -1.0f : 0.0f;
//                }
//                else if (event.key.code == Keyboard::S)
//                {
//                    myTest.orientationY = (event.type == Event::KeyPressed) ? 1.0f : 0.0f;
//                }
//                else if (event.key.code == Keyboard::Q)
//                {
//                    myTest.orientationX = (event.type == Event::KeyPressed) ? -1.0f : 0.0f;
//                }
//                else if (event.key.code == Keyboard::D)
//                {
//                    myTest.orientationX = (event.type == Event::KeyPressed) ? 1.0f : 0.0f;
//                }
//            }
//            else if (event.type == Event::MouseButtonPressed)
//            {
//                if (event.mouseButton.button == Mouse::Left)
//                {
//                    click = true;
//                }
//
//            }
//
//        }
//
//
//        window.clear();
//        myBrick.drawShape(window);
//        myCanon.rotateTowardsMouse(window);
//
//        if (click == true)
//        {
//            if (shot == false)
//            {
//                myBall.setPosition(myCanon.x, myCanon.y - myCanon.h / 2);
//                myBall.setOrientation(std::cos(myCanon.angle * M_PI / 180.0f), std::sin(myCanon.angle * M_PI / 180.0f));
//                shot = true;
//            }
//            myBall.drawShape(window);
//            myBall.move(elaspedTimeF);
//            myBrick.OnCollisionEnter(&myBall);
//            myBall.OnCollisionEnter(&myBrick);
//
//        }
//        myTest.move(elaspedTimeF);
//        myTest.OnCollisionEnter(&myBrick);
//        myTest.drawShape(window);
//        myCanon.drawShape(window);
//
//        window.display();
//
//
//        Time elapsedTime = clock.restart();
//        elaspedTimeF = elapsedTime.asSeconds();
//    }
//
//    return 0;
//}