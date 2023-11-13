#pragma once

#include "brick.h"

#include <vector>

class LevelManager
{
public:
	LevelManager();
	int row;
	int col;

	std::vector<std::vector<Brick>> brickGrid;

	void loadLevel(int level);
	void drawLevel(sf::RenderWindow& window);
	void clearGrid();

private :
	Brick myBrick;
};