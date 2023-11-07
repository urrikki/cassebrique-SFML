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
    int r;
    int x;
    int y;
    int size;
    int radius;

    Shape* shape;

    bool isRectangle;

    Color m_color;

    void setPosition(float x, float y);
    int getX();
    int getY();

    void setSize(int w, int h);
    int getSize();

    void setColor(Color color);
    Color getColor();

    void drawShape(RenderWindow& window);

    CollideSide getCollideSide(gameObject object);

};