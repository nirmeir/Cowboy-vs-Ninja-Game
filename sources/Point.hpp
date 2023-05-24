#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

namespace ariel
{
    class Point
    {

    private:
        double x_cordinate;
        double y_cordinate;

    public:
        Point(double _xcordinate, double _ycordinate): x_cordinate(_xcordinate), y_cordinate(_ycordinate) //NOLINT
        {
    
        }

        double distance(Point other) const
        {
            double distx = x_cordinate - other.x_cordinate;
            double disty = y_cordinate - other.y_cordinate;
            return std::sqrt(distx * distx + disty * disty);
        }
      
        double getX() const
        {
            return this->x_cordinate;
        }
        double getY() const
        {
            return this->y_cordinate;
        }
        void setX(double _x_cordinate)
        {
            this->x_cordinate = _x_cordinate;
        }
        void setY(double _y_cordinate)
        {
            this->y_cordinate = _y_cordinate;
        }

        string print() const
        {
            return "(" + to_string(this->x_cordinate) + "," + to_string(this->y_cordinate) + ")";
        }

        static Point moveTowards(Point src, Point dst, double distance);
        
    };

}
