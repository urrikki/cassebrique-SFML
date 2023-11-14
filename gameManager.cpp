#define _USE_MATH_DEFINES

#include "gameManager.h"
#include<iostream>
#include <cmath>

GameManager::GameManager() : window(sf::VideoMode(1280, 720), "SFML works!")
{
    myBall.initBall();
    myCanon.rotateTowardOrigin(0.5, 0.5);
    myLevel.loadLevel(1);
    if (!buffer.loadFromFile("audio/background.mp3"))
    {
        std::cout << "miaouu" << std::endl;
    }
     
}


void GameManager::runGame()
{
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

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
                if (myCanon.angle <= 0)
                {
                    click = true;
                }    
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

    myCanon.angle = std::atan2(dy, dx) * 180 / M_PI;

    if (print == true)
    {
        std::cout << myBall.x + myBall.r << std::endl;
        std::cout << myBall.y << std::endl;
        print = false;
    }

    if (myCanon.angle <= 0)
    {
        myCanon.setRotation(myCanon.angle);
    }
    

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

        
        for (int i = 0; i < myLevel.numColBrick; ++i) {
            for (int j = 0; j < myLevel.numLigneBrick; ++j) {

                myLevel.brickGrid[i][j].OnCollisionEnter(&myBall);
                myBall.OnCollisionEnter(&myLevel.brickGrid[i][j]);
                
                myLevel.brickGrid[i][j].OnCollisionStay();
                myBall.OnCollisionStay();
                
                myLevel.brickGrid[i][j].OnCollisionExit();
                myBall.OnCollisionExit();

            }
        }

        for (int i = 0; i < myLevel.numBorder; ++i)
        {
            myBall.OnCollisionEnter(&myLevel.borderGrid[i]);
            myBall.OnCollisionStay();
            myBall.OnCollisionExit();
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