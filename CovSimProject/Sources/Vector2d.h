//---------------------------------------------------------------------------

#ifndef Vector2dH
#define Vector2dH

class Vector2d
{
private:
    int x;
    int y;

public:
    Vector2d(const int x = 0, const int y = 0);

    void setX(int x) { this->x = x; }
    int getX() { return x; }

    void setY(int y) { this->y = y; }
    int getY() { return y; }

    bool equals(Vector2d other);
    Vector2d add(Vector2d other);

    static Vector2d getUnitMotion();
};

#endif
