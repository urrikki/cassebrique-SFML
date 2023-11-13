#pragma once
#include "brick.h" 
#include "ball.h"
#include "canon.h"
#include "test.h"
#include "levelManager.h"

#include <SFML/Graphics.hpp>

class GameManager
{
public:
    GameManager();

    void runGame();

private:
    void processEvents();
    void update(float elapsedTime);
    void draw();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    bool click = false;
    bool shot = false;
    float elapsedTime = 0.0;
    bool print = false;

    Brick myBrick;
    Ball myBall;
    Canon myCanon;
    LevelManager myLevel;
};