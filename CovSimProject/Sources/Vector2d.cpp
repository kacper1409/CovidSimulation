//---------------------------------------------------------------------------

#pragma hdrstop

#include "Vector2d.h"
#include <iostream>
#include <random>

using namespace std;

Vector2d::Vector2d(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

Vector2d Vector2d::getUnitMotion()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-1,1);

    int unitX = dist(gen);
    int unitY = dist(gen);

    return Vector2d(unitX, unitY);
}

Vector2d Vector2d::add(Vector2d other)
{
    int tmpX = this->x + other.getX();
    int tmpY = this->y + other.getY();

    return Vector2d(tmpX, tmpY);
}

bool Vector2d::equals(Vector2d other)
{
    return (this->x == other.getX()) && (this->y == other.getY());
}

#pragma package(smart_init)
