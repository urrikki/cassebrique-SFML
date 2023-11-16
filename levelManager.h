#pragma once

#include "brick.h"
#include "border.h"
#include "ball.h"

#include <SFML/Graphics.hpp>
#include <vector>
class LevelManager {
public:
    LevelManager();
    ~LevelManager();

    void loadLevel();
    void drawLevel(sf::RenderWindow& window);

    void loadBall();

    std::vector<std::vector<Brick>> brickGrid;
    int numColBrick;
    int numLigneBrick;

    std::vector<Ball> ballGrid;
    int numBall;

    int nbrLevel;
};