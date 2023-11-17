#pragma once
#include "levelManager.h"
#include "textManager.h"
#include "brick.h" 
#include "ball.h"
#include "canon.h"
#include "test.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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
    std::vector<Border> borderGrid;
    int numBorder = 3;

    void loadBorder();
    void drawBorder(sf::RenderWindow& window);

    bool click = false;
    bool shot = true;
    float elapsedTime = 0.0;
    bool print = false;

    int score; // ???? init à 0 ici ????
    int nbrShoot;

    bool levelFinish();

    Brick myBrick;
    Ball myBall;
    Canon myCanon;
    LevelManager myLevel;
    TextManager myText;
};