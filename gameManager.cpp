#define _USE_MATH_DEFINES

#include "gameManager.h"

#include<iostream>
#include <cmath>

GameManager::GameManager() : window(sf::VideoMode(1280, 720), "SFML works!")
{
    myBall.initBall();
    myLevel.loadLevel(1);
    myCanon.rotateTowardOrigin(0.5, 0.5);
}


void GameManager::runGame()
{
    while (window.isOpen())
    {
        processEvents();
        elapsedTime = clock.restart().asSeconds();
        update(elapsedTime);
        draw();
    }
}

void GameManager::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                click = true;
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                print = true;
            }
        }
    }
}

void GameManager::update(float elapsedTime)
{

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    float dx = mousePosition.x - myCanon.x;
    float dy = mousePosition.y - myCanon.y;

    float angle = std::atan2(dy, dx) * 180 / M_PI;

    if (print == true)
    {
        std::cout << angle << std::endl;
        print = false;
    }


    myCanon.setRotation(angle);


    if (click == true)
    {
        if (shot == false)
        {
            myBall.setPosition(myCanon.x, myCanon.y);
            myBall.setOrientation(dx, dy);
            shot = true;
        }

        // Normalisation de l'orientation
        float orientationDistance = std::sqrt(myBall.orientationX * myBall.orientationX + myBall.orientationY * myBall.orientationY);
        if (orientationDistance != 0)
        {
            myBall.orientationX /= orientationDistance;
            myBall.orientationY /= orientationDistance;
        }

        myBall.move(elapsedTime);

        for (int i = 0; i < myLevel.row; ++i) {
            for (int j = 0; j < myLevel.col; ++j) {
                myLevel.brickGrid[i][j].OnCollisionEnter(&myBall);
                myLevel.brickGrid[i][j].OnCollisionStay();
                myLevel.brickGrid[i][j].OnCollisionExit();
                myBall.OnCollisionEnter(&myLevel.brickGrid[i][j]);
                myBall.OnCollisionStay();
                myBall.OnCollisionExit();
            }
        }

        

        if (myBall.isShapeOnScreen(window) == false)
        {
            myBall.setPosition(myCanon.x, myCanon.y);
            shot = false;
            click = false;
        }
    }

}

void GameManager::draw()
{
    window.clear();
    myLevel.drawLevel(window);
    myBall.drawShape(window);
    myCanon.drawShape(window);

    window.display();
}