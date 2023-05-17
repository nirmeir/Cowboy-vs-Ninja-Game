#pragma once
#include <string>
using namespace std;

namespace ariel
{
    class Point
    {

    private:
        double x;
        double y;

    public:
        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        }
        double distance(Point other)
        {
            return 0;
        }
        double getX()
        {
            return this->x;
        }
        double getY()
        {
            return this->y;
        }
        void setX(double x)
        {
            this->x = x;
        }
        void setY(double y)
        {
            this->y = y;
        }
        void move(Point other)
        {
            this->x = other.getX();
            this->y = other.getY();
        }
        string print()
        {
            return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
        }
        Point moveTowards(Point src,Point dst, double distance)
        {
            return Point(0, 0);
        }
    };
}

