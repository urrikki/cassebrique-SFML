#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "brick.h"
#include "border.h"

class LevelManager {
public:
    LevelManager();

    void loadLevel(int levelNumber);
    void drawLevel(sf::RenderWindow& window);

    std::vector<std::vector<Brick>> brickGrid;
    int numColBrick;
    int numLigneBrick;

    void loadBorder();
    std::vector<Border> borderGrid;
    int numBorder;
    void DrawBorder(sf::RenderWindow& window);
    
};