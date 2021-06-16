//---------------------------------------------------------------------------

#ifndef PersonH
#define PersonH

#include "Vector2d.h"
#include "Status.h"
#include "Parameters.h"

class Person
{
private:
    Vector2d position;
    Status status;
    int daysToRecovery;

public:
    explicit Person(Status status);
    Person(Vector2d position, Status status);

    Vector2d getPosition() { return position; }
    void setPosition(Vector2d position);

    Status getStatus() { return status; }
    void setStatus(Status status) { this->status = status; }

    void updateRecovering();
    void move(Vector2d unitMotion);
};

#endif
