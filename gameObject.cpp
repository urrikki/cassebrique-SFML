#include "gameObject.h"

gameObject::gameObject()
{
    w = 0;
    h = 0;
    x = 0;
    y = 0;
    size = 10;
    Color m_color = Color::White;
    square.setSize(sf::Vector2f(size, size));
}

void gameObject::setPosition(int x, int y)
{
    x,y = x, y;
    square.setPosition(x, y);
};

int gameObject::getX()
{
    return x;
}

int gameObject::getY()
{
    return y;
}

void gameObject::setColor(Color color)
{
    m_color = color;
    square.setFillColor(color);
};

Color gameObject::getColor()
{
    return m_color;
}



void gameObject::drawSquare(RenderWindow& window)
{ 
    window.draw(square);
};


float distance(float pointX, float pointY, float opointX, float opointY)
{
    float dx = pointX - opointX;
    float dy = pointY - opointY;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance;
};

struct distanceResult {
    std::string name;
    float value;

    distanceResult(const std::string& n, float v) : name(n), value(v) {}
};


CollideSide gameObject::getCollideSide(const gameObject object) {
    // xmin = x et xmax = x + size
    // ymin = y et ymax = y + size

    // On calcule un point au milieu de chaque longueur du carré 
    float lpointX = x;
    float lpointY = y + size / 2;

    float rpointX = x + size;
    float rpointY = y + size / 2;

    float tpointX = x + size / 2;
    float tpointY = y;

    float bpointX = x + size / 2;
    float bpointY = y + size;

    // Pareil pour les objets 

    float olpointX = x;
    float olpointY = y + size / 2;

    float orpointX = x + size;
    float orpointY = y + size / 2;

    float otpointX = x + size / 2;
    float otpointY = y;

    float obpointX = x + size / 2;
    float obpointY = y + size;

    if (
        /*verif pour x*/(x <= (object.x + object.size) && x <= (object.x) || x + size >= (object.x + object.size) && x + size <= (object.x))
        &&
        /*verif pour y*/ (y <= (object.y + object.size) && y <= (object.y) || y + size >= (object.y + object.size) && x + size <= (object.y))
        )
    {

        // Stock résultats dans la structure
        distanceResult results[] = {
            distanceResult("rtol", distance(rpointX , rpointY , olpointX , olpointY)),
            distanceResult("ltor", distance(lpointX , lpointY , orpointX , orpointY)),
            distanceResult("ttob", distance(tpointX ,tpointY , obpointX , obpointY)),
            distanceResult("btot", distance(bpointX , bpointY , otpointX , otpointY))
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
            return Right;
        }
        else if (testDistance == "ltor") {
            return Left;
        }
        else if (testDistance == "ttob") {
            return Top;
        }
        else if (testDistance == "btot") {
            return Bottom;
        }
    }
    return None;
}

