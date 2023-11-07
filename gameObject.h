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
    float x;
    float y;
    int size;

    RectangleShape square;

    Color m_color;

    void setPosition(float x, float y);
    int getX();
    int getY();

    void setSize(int size);
    int getSize();

    void setColor(Color color);
    Color getColor();

    void drawSquare(RenderWindow& window);

    CollideSide getCollideSide(gameObject object);

};