#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "levelManager.h"
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
    sf::SoundBuffer buffer;

    bool click = false;
    bool shot = false;
    float elapsedTime = 0.0;
    bool print = false;

    Brick myBrick;
    Ball myBall;
    Canon myCanon;
    LevelManager myLevel;
};