#include "levelManager.h"

#include <fstream>
#include <iostream>
#include <sstream>


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

    //Repopulez les borders
    borderGrid[0] = Border();
    borderGrid[0].setPosition(145, 0);
    borderGrid[0].setSizeRec(995, 15);
    borderGrid[0].setColor(sf::Color(180,180,200));

    borderGrid[1] = Border();
    borderGrid[1].setPosition(145, 15);
    borderGrid[1].setSizeRec(20, 700);
    borderGrid[1].setColor(sf::Color(180, 180, 200));

    borderGrid[2] = Border();
    borderGrid[2].setPosition(1120, 15);
    borderGrid[2].setSizeRec(20, 700);
    borderGrid[2].setColor(sf::Color(180, 180, 200));

}

//void LevelManager::loadLevel(int levelNumber) {
//    if (levelNumber == 1) {
//        // Réinitialisez ou ajustez la taille de votre grille pour le niveau 1
//        this->numColBrick = 10;
//        this->numLigneBrick = 6;
//    }
//
//    brickGrid.resize(numColBrick, std::vector<Brick>(numLigneBrick));
//
//    // Repopulez la grille avec les briques
//    for (int i = 0; i < numColBrick; ++i) {
//        for (int j = 0; j < numLigneBrick; ++j) {
//            brickGrid[i][j] = Brick();
//            brickGrid[i][j].setPosition(200.0 + (i * 90.0), 60.0 + (j * 40));
//            brickGrid[i][j].setColor(sf::Color::Cyan);
//        }
//    }  
//    
//    loadBorder();
//}

void LevelManager:: initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        int numRow, numCol;
        int numLine = 0;
        std::string line;

        while (std::getline(file, line))
        {
            ++numLine;
            if (numLine == 0) {
                numCol = line.length();
                brickGrid.resize(numCol, std::vector<Brick>(0));
            }
            std::cout << line << std::endl;
            brickGrid.resize(numCol, std::vector<Brick>(numLine + 1));

        }
        for (int i = 0; i < line.length(); ++i)
        {
            std::getline(file, line);
            brickGrid[i][numLine] = Brick();
            brickGrid[i][numLine].setLife(line[i]);
            brickGrid[i][numLine].setPosition(200.0 + (i * 90.0), 60.0 + (numLine * 40));
        }
        /*
        std::cout << "Open file: " << filename << std::endl;
        int numRows, numCols;
        file >> numRows >> numCols;


        brickGrid.resize(numRows, std::vector<Brick>(numCols, Brick()));

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                file >> brickGrid[i][j].life;
                brickGrid[i][j].setPosition(200.0 + (i * 90.0), 60.0 + (j * 40));
            }
        }
        */
        file.close();
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
    loadBorder();
};

void LevelManager::drawLevel(sf::RenderWindow& window) {
    
    drawBorder(window);
    for (int i = 0; i < numColBrick; ++i) {
        for (int j = 0; j < numLigneBrick; ++j) {
            brickGrid[i][j].drawShape(window);     
        }
    }

}

void LevelManager::drawBorder(sf::RenderWindow& window)
{
    for (int i = 0; i < numBorder; ++i) {
        borderGrid[i].drawShape(window);
    }
}


