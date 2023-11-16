#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "brick.h"
#include "border.h"
#include "ball.h"

class LevelManager {
public:
    LevelManager();
    ~LevelManager();

    void loadLevel();
    void drawLevel(sf::RenderWindow& window);

    void loadBorder();
    void drawBorder(sf::RenderWindow& window);

    void loadBall();

    std::vector<std::vector<Brick>> brickGrid;
    int numColBrick;
    int numLigneBrick;

    std::vector<Border> borderGrid;
    int numBorder;

    std::vector<Ball> ballGrid;
    int numBall;

    int nbrLevel;
};