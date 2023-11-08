#include "gameObject.h"

gameObject::gameObject(int w, int h)
{
    this->w = w;
    this->h = h;
    x = 0;
    y = 0;
    shapeType = NoShape;
    orientationX = 0;
    orientationY = 0;
    Color m_color = Color::White;

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


gameObject::gameObject(int r)
{
    x = 0;
    y = 0;
    this->r = r;
    orientationX = 0;
    orientationY = 0;
    shapeType = Circle;
    Color m_color = Color::White;

    shape = new CircleShape(r);
    shape->setPosition(x, y);
    shape->setFillColor(m_color);
}


//void Init() 
//{
//    w = 0;
//    h = 0;
//    x = 0;
//    y = 0;
//}


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

int gameObject::getRadius()
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

void gameObject::setOrientation(float x, float y)
{
    this->orientationX = x;
    this->orientationY = y;

}

void gameObject::moveBall(float elapsedTimeF)
{
    setPosition(x + (elapsedTimeF * orientationX), y + (elapsedTimeF * orientationY));
}

void gameObject::rebound(CollideSide side)
{
    if (side == CollideSide::Bottom || side == CollideSide::Top)
    {
        this->orientationY = orientationY * -1;
    }
    else if (side == CollideSide::Right || side == CollideSide::Left)
    {
        this->orientationX = orientationX * -1;
    }

}

CollideSide gameObject::getCollideSide(gameObject objectTest) {
    // xmin = x et xmax = x + size
    // ymin = y et ymax = y + size
    bool collid = false;
    if (getShapeType() == ShapeType::Circle) {
  
        float x = getX();
        float y = getY();

        // On calcule un point au milieu de chaque longueur du carré 
        float lpointX = this->x;
        float lpointY = this->y + w / 2;

        float rpointX = this->x + w;
        float rpointY = this->y + w / 2;

        float tpointX = this->x + h / 2;
        float tpointY = this->y;

        float bpointX = this->x + h / 2;
        float bpointY = this->y + h;

        // Pareil pour les objets 

        float olpointX = objectTest.x;
        float olpointY = objectTest.y + objectTest.w / 2;

        float orpointX = objectTest.x + objectTest.w;
        float orpointY = objectTest.y + objectTest.w / 2;

        float otpointX = objectTest.x + objectTest.h / 2;
        float otpointY = objectTest.y;

        float obpointX = objectTest.x + objectTest.h / 2;
        float obpointY = objectTest.y + objectTest.h;

        if (getShapeType() == ShapeType::Circle) {
            // On calcule un point au milieu de chaque longueur du carré 
            float lpointX = this->x;
            float lpointY = this->y + r / 2;

            float rpointX = this->x + r;
            float rpointY = this->y + r / 2;

            float tpointX = this->x + r / 2;
            float tpointY = this->y;

            float bpointX = this->x + r / 2;
            float bpointY = this->y + r;
        }

        if (
            /*verif pour x*/(x <= (objectTest.x + objectTest.w) || x + w <= objectTest.x)
            &&
            /*verif pour y*/ (y <= (objectTest.y + objectTest.h) || y + h <= objectTest.y)
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
        
    }
    return CollideSide::None;
}

