#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
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

typedef enum ShapeType
{
    NoShape,
    Rectangle,
    Square,
    Circle,
};

class gameObject
{

public:
    gameObject(int w, int h);
    gameObject(int r);

    int w;
    int h;
    int r;
    float x;
    float y;
    int size;
    int radius;

    Shape* shape;
    ShapeType shapeType;
    Color m_color;

    void setPosition(float x, float y);
    float getX();
    float getY();

    int getWidth();
    int getHeight();
    int getRadius();

    void setColor(Color color);
    Color getColor();

    void drawShape(RenderWindow& window);

    CollideSide getCollideSide(gameObject object);

    ShapeType getShapeType();


    float orientationX;
    float orientationY;

    void setOrientation(float x, float y);
    void moveBall(float elapsedTimeF);
    void rebound(CollideSide side);

};
