#include "test.h"

#include <vector>
#include<iostream>

using namespace sf;

Test::Test() : gameObject(80, 30, 100, 100, Color::Magenta)
{

};

void Test::initTest()
{
	setSpeed(100);
};

void Test::OnCollisionEnter(gameObject* objectTest)
{
}
