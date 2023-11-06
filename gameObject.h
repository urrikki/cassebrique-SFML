#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace sf;

typedef enum CollideSide
{
    None,
    Right,
    Left,
    Top,
    Bottom,
};

class gameObject
{

public:
    gameObject();

    int w;
    int h;
    int x;
    int y;
    int size;

    RectangleShape square;

    Color m_color;

    void setPosition(int x, int y);
    int getX();
    int getY();

    void setColor(Color color);

    Color getColor();

    void drawSquare(RenderWindow& window);

    CollideSide getCollideSide(const gameObject object);

};