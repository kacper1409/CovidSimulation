//---------------------------------------------------------------------------

#pragma hdrstop

#include "Person.h"

Person::Person(Status status)
{
    this->status = status;
    this->daysToRecovery = -1;
}

Person::Person(Vector2d position, Status status)
{
    this->position = position;
    this->status = Healthy;
    this->daysToRecovery = -1;
}

void Person::move(Vector2d unitMotion)
{
    position = position.add(unitMotion);
}

void Person::setPosition(Vector2d position)
{
    /// normalizacja pozycji na rozmiar mapy

    this->position.setX( (position.getX() + Parameters::width) % Parameters::width );
    this->position.setY( (position.getY() + Parameters::height) % Parameters::height );
}

void Person::updateRecovering()
{
    if (status == Infected)
    {
        if (this->daysToRecovery == -1)
        {
            this->daysToRecovery = Parameters::infectionDuration;
        }
        else if (this->daysToRecovery == 0)
        {
            this->status = Recovered;
        }
        else
        {
            this->daysToRecovery--;
        }
    }
}

#pragma package(smart_init)
