#include "levelManager.h"

#include "brick.h"

#include <iostream>
#include <vector>

LevelManager::LevelManager()
{ 
	std::vector<std::vector<Brick>> brickGrid;
	row = 0;
	col = 0;
}


void LevelManager::loadLevel(int level)
{
	if (level == 1) {
		this->row = 9;
		this->col = 8;
	}

	brickGrid.resize(row, std::vector<Brick>(col));

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			brickGrid[i][j] = Brick();
			brickGrid[i][j].setPosition(200 + i * 100, 50 + j * 40);
			brickGrid[i][j].setColor(sf::Color::Cyan);
		}
	}
}

void LevelManager::drawLevel(sf::RenderWindow& window)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			brickGrid[i][j].drawShape(window);
		}
	}
}

void LevelManager::clearGrid() 
{
	brickGrid.clear();
}

//void LevelManager::initLevel(int row, int col) {
//    this->row = row;
//    this->col = col;
//
//    brickGrid.resize(row, std::vector<int>(col, 0));

//void LevelManager::resizebrickGrid(int sizeX, int sizeY)
//{
//	brickGrid.resize(sizeX, sizeY)
//}

//void LevelManager::getbrickGridSize()
//{
//	int tailleDuVecteur = brickGrid.size();
//}



