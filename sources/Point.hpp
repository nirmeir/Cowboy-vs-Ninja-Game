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
            double dx = x - other.x;
            double dy = y - other.y;
            return std::sqrt(dx * dx + dy * dy);
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

        string print()
        {
            return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
        }

        static Point moveTowards(Point src, Point dst, double distance);
        
    };

}
