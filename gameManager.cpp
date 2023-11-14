#define _USE_MATH_DEFINES

#include "gameManager.h"
#include<iostream>
#include <cmath>

GameManager::GameManager() : window(sf::VideoMode(1280, 720), "SFML works!")
{
    score = 0;
    nbrShoot = 0; 
    myBall.initBall();
    myCanon.rotateTowardOrigin(0.5, 0.5);
    myLevel.loadLevel(1);
    myText.addText(" Score : " + std::to_string(score), 1150, 630, sf::Color::White, 25);
    myText.addText(" Shoot " + std::to_string(nbrShoot) +"/10", 1150, 660, sf::Color::White, 25);

    if (!buffer.loadFromFile("audio/background.mp3"))
    {
        std::cout << "Erreur lors du chargement du son." << std::endl;
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
            ++nbrShoot;
            myText.setContent(1, " Shoot " + std::to_string(nbrShoot) + "/10");
            
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

                if (myLevel.brickGrid[i][j].Collide == CollideType::Stay)
                {
                    score = score + (10 / nbrShoot);
                    myText.setContent(0, " Score : " + std::to_string(score));
                }

                myLevel.brickGrid[i][j].OnCollisionStay();
                myBall.OnCollisionStay();
                if (myLevel.brickGrid[i][j].Collide == CollideType::Exit)
                {
                    if (myLevel.brickGrid[i][j].life == 0)
                    {
                        score = score + (100/nbrShoot);
                        myText.setContent(0, " Score : " + std::to_string(score));
                    }
                }
                

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
    myText.draw(window);

    window.display();
}

