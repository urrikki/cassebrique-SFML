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

    Color m_color;

    int setPosition(int x, int y);
    int getX();
    int getY();

    void setColor(Color color);

    Color getColor();

    void draw();

    bool AABB(const gameObject object);

    CollideSide getCollideSide(const gameObject object);

};