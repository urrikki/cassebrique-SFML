#pragma once
#include <SFML/Graphics.hpp>

#include "levelManager.h"
#include "textManager.h"
#include "brick.h" 
#include "ball.h"
#include "canon.h"
#include "test.h"

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

    int score;

    Brick myBrick;
    Ball myBall;
    Canon myCanon;
    LevelManager myLevel;
    TextManager myText;
};