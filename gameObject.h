#pragma once
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <cmath>
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
private: 
    const float PI = 3.14159265358979323846f;
    float dx;
    float dy;

public:
    gameObject(int w, int h, int x, int y);
    gameObject(int r, int x, int y);

    int w;
    int h;
    int r;
    float x;
    float y;
    float angle;

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

    void rotateTowardsMouse(sf::RenderWindow& window);
    void setRotation(float angle);

};
