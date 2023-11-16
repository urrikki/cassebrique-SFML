#define _USE_MATH_DEFINES

#include "gameManager.h"
#include<iostream>
#include <cmath>

GameManager::GameManager() : window(sf::VideoMode(1280, 720), "SFML works!")
{
    score = 0;
    nbrShoot = 0;
    myCanon.rotateTowardOrigin(0.5, 0.5);
    myLevel.loadLevel();
    myText.addText(" Score : " + std::to_string(score), 1150, 630, sf::Color::White, 25);
    myText.addText(" Shoot " + std::to_string(nbrShoot) + "/" + std::to_string(myLevel.numBall), 1150, 660, sf::Color::White, 25);
    myLevel.loadBall();
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
        if (levelFinish())
        {
            ++myLevel.nbrLevel;
            myLevel.loadLevel();
            nbrShoot = 0;
            myText.setContent(1, " Shoot " + std::to_string(nbrShoot) + "/" + std::to_string(myLevel.numBall));
        }
    }
}

bool GameManager::levelFinish()
{
    if (nbrShoot == myLevel.numBall)
    {
        for (int k = 0; k < myLevel.numBall; ++k)
        {
            if (myLevel.ballGrid[k].isActive)
            {
                return false;
            }
        }
        return true;   
    }
    return false;
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
                    if (nbrShoot < myLevel.numBall)
                    {
                        if (shot)
                        {
                            click = true;
                            myLevel.ballGrid[nbrShoot].isActive = true;
                        }    
                    }
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
        std::cout << myLevel.ballGrid[nbrShoot - 1].x + myLevel.ballGrid[nbrShoot - 1].r << std::endl;
        std::cout << myLevel.ballGrid[nbrShoot - 1].y << std::endl;
        print = false;
    }

    if (myCanon.angle <= 0)
    {
        myCanon.setRotation(myCanon.angle);
    }


    if (click == true)
    {
        if (shot)
        {
            ++nbrShoot;
            myText.setContent(1, " Shoot " + std::to_string(nbrShoot) + "/" + std::to_string(myLevel.numBall));


            myLevel.ballGrid[nbrShoot - 1].setPosition(myCanon.x, myCanon.y);
            myLevel.ballGrid[nbrShoot - 1].setOrientation(dx, dy);

            // Normalisation de l'orientation
            float orientationDistance = std::sqrt(myLevel.ballGrid[nbrShoot - 1].orientationX * myLevel.ballGrid[nbrShoot - 1].orientationX + myLevel.ballGrid[nbrShoot - 1].orientationY * myLevel.ballGrid[nbrShoot - 1].orientationY);
            if (orientationDistance != 0)
            {
                myLevel.ballGrid[nbrShoot - 1].orientationX /= orientationDistance;
                myLevel.ballGrid[nbrShoot - 1].orientationY /= orientationDistance;
            }
            click = false;
            if (myLevel.nbrLevel == 2)
            {
                shot = false;
            }
        }    
    }

    for (int k = 0; k < myLevel.numBall; ++k)
    {
        if (myLevel.ballGrid[k].isActive)
        {
            myLevel.ballGrid[k].move(elapsedTime);


            for (int i = 0; i < myLevel.numColBrick; ++i)
            {
                for (int j = 0; j < myLevel.numLigneBrick; ++j) {

                    myLevel.brickGrid[i][j].OnCollisionEnter(&myLevel.ballGrid[k]);
                    myLevel.ballGrid[k].OnCollisionEnter(&myLevel.brickGrid[i][j]);

                    if (myLevel.brickGrid[i][j].Collide == CollideType::Stay)
                    {
                        score = score + (20 / nbrShoot);
                        myText.setContent(0, " Score : " + std::to_string(score));
                    }

                    myLevel.brickGrid[i][j].OnCollisionStay();
                    myLevel.ballGrid[k].OnCollisionStay();
                    if (myLevel.brickGrid[i][j].Collide == CollideType::Exit)
                    {
                        if (myLevel.brickGrid[i][j].life == 0)
                        {
                            score = score + (100 / nbrShoot);
                            myText.setContent(0, " Score : " + std::to_string(score));
                        }
                    }


                    myLevel.brickGrid[i][j].OnCollisionExit();
                    myLevel.ballGrid[k].OnCollisionExit();
                }
            }


            for (int i = 0; i < myLevel.numBorder; ++i)
            {
                myLevel.ballGrid[k].OnCollisionEnter(&myLevel.borderGrid[i]);
                myLevel.ballGrid[k].OnCollisionStay();
                myLevel.ballGrid[k].OnCollisionExit();
            }


            if (myLevel.ballGrid[k].isShapeOnScreen(window) == false)
            {
                myLevel.ballGrid[k].setPosition(myCanon.x, myCanon.y);
                click = false;
                myLevel.ballGrid[k].isActive = false;
                if (myLevel.nbrLevel == 2)
                {
                    shot = true;
                }
            }
        }
    }
}

void GameManager::draw()
{
    window.clear();

    myLevel.drawLevel(window);
    for (int i = 0; i < myLevel.numBall; ++i)
    {
        myLevel.ballGrid[i].drawShape(window);
    }
    myCanon.drawShape(window);
    myText.draw(window);

    window.display();
}

