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
private: 
    const float PI = 3.14159265358979323846f;
    float dx;
    float dy;

public:
    gameObject(int w, int h);
    gameObject(int r);

    int w;
    int h;
    int r;
    float x;
    float y;
    float angle;

    Shape* shape;

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

    float orientationX;
    float orientationY;

    void setOrientation(float x, float y);
    void moveBall(float elapsedTimeF);
    void rebound(CollideSide side);

    void rotateTowardsMouse(sf::RenderWindow& window);
    void setRotation(float angle);

};
