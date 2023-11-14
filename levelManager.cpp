#include "levelManager.h"


LevelManager::LevelManager(){

    std::vector<std::vector<Brick>> brickGrid;
    numColBrick = 0;
    numLigneBrick = 0;
    

    std::vector<Border> borderGrid;
    numBorder = 3;
      
}

void LevelManager::loadBorder()
{
    borderGrid.resize(numBorder);
    //repopulez les borders

    borderGrid[0] = Border();
    borderGrid[0].setPosition(0, 0);
    borderGrid[0].setSizeRec(1280, 30);
    borderGrid[0].setColor(sf::Color::White);

    borderGrid[1] = Border();
    borderGrid[1].setPosition(0, 30);
    borderGrid[1].setSizeRec(30, 690);
    borderGrid[1].setColor(sf::Color::White);

    borderGrid[2] = Border();
    borderGrid[2].setPosition(1250, 30);
    borderGrid[2].setSizeRec(30, 690);
    borderGrid[2].setColor(sf::Color::White);

}

void LevelManager::loadLevel(int levelNumber) {
    if (levelNumber == 1) {
        // Réinitialisez ou ajustez la taille de votre grille pour le niveau 1
        this->numColBrick = 10;
        this->numLigneBrick = 6;
    }

    brickGrid.resize(numColBrick, std::vector<Brick>(numLigneBrick));

    // Repopulez la grille avec les briques
    for (int i = 0; i < numColBrick; ++i) {
        for (int j = 0; j < numLigneBrick; ++j) {
            brickGrid[i][j] = Brick();
            brickGrid[i][j].setPosition(200 + (i * 90), 60 + (j * 40));
            brickGrid[i][j].setColor(sf::Color::Cyan);
        }
    }  
    
    loadBorder();
}

void LevelManager::drawLevel(sf::RenderWindow& window) {
    
    DrawBorder(window);
    for (int i = 0; i < numColBrick; ++i) {
        for (int j = 0; j < numLigneBrick; ++j) {
            brickGrid[i][j].drawShape(window);     
        }
    }
    
}

void LevelManager::DrawBorder(sf::RenderWindow& window)
{
    for (int i = 0; i < numBorder; ++i) {
        borderGrid[i].drawShape(window);
    }
}
