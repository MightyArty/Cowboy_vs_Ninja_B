#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        // Constructor and empty constructor
        Point(double x_dot, double y_dot);
        Point();

        // getters for Point
        double getX() const;
        double getY() const;

        void setX(double new_x);
        void setY(double new_y);

        void print();

        /**
         * @brief computes the distance of two points
         * @return the distance
         * @param other the second point to compare
         */
        double distance(Point &other);

        /**
         * @param first the source point
         * @param second the destination point
         * @param distance the max distance between the two points
         * @return the closest point to the destination point
         */
        Point moveTowards(Point &first, Point &second, double distance);
    };
}

#endif