#include "Point.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace ariel;


Point Point::moveTowards(Point src, Point dst, double distance)
        {
            if(distance < 0){
                throw std::invalid_argument("distance must be positive");
            }
            double d = src.distance(dst);

            // If the distance between src and dst is less than or equal to the given distance,
            // the dst point is reached.
            if (d <= distance)
            {
                return dst;
            }

            // Calculate the ratio to move along the line connecting src and dst
            double ratio = distance / d;

            // Calculate the new point coordinates
            double newX = src.getX() + (dst.getX() - src.getX()) * ratio;
            double newY = src.getY() + (dst.getY() - src.getY()) * ratio;

            // Create and return the new Point object
            return Point(newX, newY);
        };