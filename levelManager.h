#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "brick.h"
#include "border.h"
#include "ball.h"

class LevelManager {
public:
    LevelManager();

    void loadLevel();
    void drawLevel(sf::RenderWindow& window);

    std::vector<std::vector<Brick>> brickGrid;
    int numColBrick;
    int numLigneBrick;

    void loadBorder();
    std::vector<Border> borderGrid;
    int numBorder;
    void drawBorder(sf::RenderWindow& window);

    std::vector<Ball> ballGrid;
    int numBall;
    void loadBall();

    int nbrLevel;
};