#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

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
    std::string gameScore();
    void draw();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::SoundBuffer buffer;

    bool click = false;
    bool shot = false;
    float elapsedTime = 0.0;
    bool print = false;

    int score; // ???? init à 0 ici ????
    int nbrShoot;

    Brick myBrick;
    Ball myBall;
    Canon myCanon;
    LevelManager myLevel;
    TextManager myText;
};