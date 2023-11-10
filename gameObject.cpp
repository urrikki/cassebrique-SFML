#define _USE_MATH_DEFINES

#include "gameObject.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>


using namespace sf;

gameObject::gameObject(int w, int h, float x, float y, sf::Color color)
{
    this->w = w;
    this->h = h;
    this->x = x;
    this->y = y;
    m_color = color;
    speed = 0;
    shapeType = NoShape;
    orientationX = 0;
    orientationY = 0;

    shape = new RectangleShape(sf::Vector2f(w, h));
    if (w == h)
    {
        shapeType = Square;
    }
    else
    {
        shapeType = Rectangle;
    }
    shape->setPosition(x, y);
    shape->setFillColor(m_color);
}


gameObject::gameObject(float r, float x, float y, sf::Color color)
{
    this->x = x;
    this->y = y;
    this->r = r;
    m_color = color;
    speed = 0;
    orientationX = 0;
    orientationY = 0;
    shapeType = Circle;

    shape = new CircleShape(r);
    shape->setPosition(x, y);
    shape->setFillColor(m_color);
}


void gameObject::setSpeed(float speed)
{
    this->speed = speed;
}

void gameObject::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    shape->setPosition(x, y);
};

float gameObject::getX()
{
    return x;
}

float gameObject::getY()
{
    return y;
}

void gameObject::setColor(Color color)
{
    m_color = color;
    shape->setFillColor(color);
};

Color gameObject::getColor()
{
    return m_color;
}


int gameObject::getWidth()
{
    return w;
};

int gameObject::getHeight()
{
    return h;
};

float gameObject::getRadius()
{
    return r;
};


void gameObject::drawShape(RenderWindow& window)
{ 
    window.draw(*shape);
};

ShapeType gameObject::getShapeType()
{
    return shapeType;
}

struct distanceResult {
    std::string name;
    float value;

    distanceResult(const std::string& n, float v) : name(n), value(v) {}
};

void gameObject::setOrientation(float x, float y)
{
    this->orientationX = x;
    this->orientationY = y;
}

float gameObject::getOrientationX()
{
    return orientationX;
}

float gameObject::getOrientationY()
{
    return orientationY;
}

void gameObject::move(float elapsedTimeF)
{
    float newX = x + (speed * (elapsedTimeF * orientationX));
    float newY = y + (speed * (elapsedTimeF * orientationY));
    setPosition(newX , newY );
}


CollideSide gameObject::getCollideSide(gameObject* objectTest) {
    // xmin = x et xmax = x + size
    // ymin = y et ymax = y + size
    if (getShapeType() == ShapeType::Circle)
    {
        w = r;
        h = r;
    }

    if (objectTest->getShapeType() == ShapeType::Circle)
    {
        objectTest->w = objectTest->r;
        objectTest->h = objectTest->r;
    }

    
    if (
        /*verif pour x*/(x > objectTest->x && x < (objectTest->x + objectTest->w) || x + w > objectTest->x && x + w < (objectTest->x + objectTest->w))
        &&
        /*verif pour y*/ (y > objectTest->y && y < (objectTest->y + objectTest->h) || y + h > objectTest->y && y + h < (objectTest->y + objectTest->h))
        ||
        /*verif pour x*/(objectTest->x > x && objectTest->x < (x + w) || objectTest->x + objectTest->w > x && objectTest->x + objectTest->w < (x + w))
        &&
        /*verif pour y*/ (objectTest->y > y && objectTest->y < (y + h) || objectTest->y + objectTest->h > y && objectTest->y + objectTest->h < (y + h))
        )
    {
        
        // Stock résultats dans la structure       
        distanceResult results[] = {
            distanceResult("rtol", std::abs(x + w - objectTest->x)),
            distanceResult("ltor", std::abs(x - objectTest->x - objectTest->w)),
            distanceResult("ttob", std::abs(y - objectTest->y - objectTest->h)),
            distanceResult("btot", std::abs(y + h - objectTest->y))
        };

        // petite distance
        float minDistance = results[0].value;
        std::string testDistance = results[0].name;

        for (int i = 1; i < 4; i++) {
            if (results[i].value < minDistance) {
                minDistance = results[i].value;
                testDistance = results[i].name;
            }
        }

        if (testDistance == "rtol") {
            std::cout << "Right";
            return Right;
        }
        else if (testDistance == "ltor") {
            std::cout << "Left";
            return Left;
        }
        else if (testDistance == "ttob") {
            std::cout << "Top";
            return Top;
        }
        else if (testDistance == "btot") {
            std::cout << "Bot";
            return Bottom;
        }
    }

    return CollideSide::None;
}

// Rotation
void gameObject::rotateTowardOrigin(float x, float y)
{
    x = w * x;
    y = h * y;
    shape->setOrigin(x, y);
    shape->setRotation(angle);
};

void gameObject::setRotation(float angle)
{
    this->angle = angle;
    shape->setRotation(angle);
};

void gameObject::OnCollisionEnter(gameObject* object)
{
    
}

void gameObject::OnCollisionStay()
{

}

void gameObject::OnCollisionExit()
{

}

bool gameObject::isShapeOnScreen(sf::RenderWindow& window)
{
    // Obtenez les dimensions de la fenêtre
    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);

    // Obtenez les coordonnées de la shape
    float shapeLeft = shape->getPosition().x;
    float shapeTop = shape->getPosition().y;
    float shapeRight = shapeLeft + shape->getGlobalBounds().width;
    float shapeBottom = shapeTop + shape->getGlobalBounds().height;

    // Vérifiez si la shape est entièrement à l'intérieur de l'écran
    if (shapeLeft >= 0 && shapeTop >= 0 && shapeRight <= windowWidth && shapeBottom <= windowHeight)
    {
        std::cout << "miaou";
        return true;
    }
    else
    {
        std::cout << "waf";
        return false;
    }
}