#include "levelManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

LevelManager::LevelManager(){

    std::vector<std::vector<Brick>> brickGrid;
    numColBrick = 0;
    numLigneBrick = 0;
    

    std::vector<Border> borderGrid;
    numBorder = 3;
     
    std::vector<Ball> ballGrid;
    numBall = 15;
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

void LevelManager::loadLevel(int levelNumber) {
    // Construire le chemin du dossier des niveaux
    std::string levelFolderPath = "level/";

    // Construire le nom du fichier texte du niveau
    std::string levelFileName = levelFolderPath + "level" + std::to_string(levelNumber) + ".txt";

    // Ouvrir le fichier texte du niveau
    std::ifstream levelFile(levelFileName);

    if (!levelFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier du niveau : " << levelFileName << std::endl;
        return;
    }

    // Déterminer le nombre de colonnes et de lignes en fonction du fichier
    numColBrick = 0;
    numLigneBrick = 0;
    std::string line;

    while (std::getline(levelFile, line)) {
        // Incrementer le nombre de lignes pour chaque ligne lue
        ++numLigneBrick;

        // Mettre à jour le nombre de colonnes si la ligne est plus longue que numColBrick actuel
        if (line.length() > static_cast<size_t>(numColBrick)) {
            numColBrick = static_cast<int>(line.length());
        }
    }

    // Réinitialiser la position du curseur de fichier pour lire à partir du début
    levelFile.clear();
    levelFile.seekg(0, std::ios::beg);

    // Allouer de l'espace pour la grille en fonction du nombre de colonnes et de lignes déterminé
    brickGrid.resize(numColBrick, std::vector<Brick>(numLigneBrick));

    // Lire les données du fichier et initialiser la grille
    for (int j = 0; j < numLigneBrick; ++j) {
        std::getline(levelFile, line);

        for (int i = 0; i < numColBrick; ++i) {
            if (i < static_cast<int>(line.length())) {
                int life = line[i] - '0';  // Convertir le caractère en entier
                brickGrid[i][j] = Brick();
                brickGrid[i][j].setPosition(200.0 + (i * 90.0), 60.0 + (j * 40.0));
                brickGrid[i][j].setLife(life);
                brickGrid[i][j].lifeBrick();
            }
        }
    }

    // Fermer le fichier du niveau
    levelFile.close();

    loadBorder();
}

void LevelManager::loadBall()
{
    ballGrid.resize(numBall);
    for (int i = 0; i < numBall; ++i) {
        ballGrid[i] = Ball();
        ballGrid[i].isActive = false;
        ballGrid[i].initBall();
    }
}

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
