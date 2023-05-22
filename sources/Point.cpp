#include "Point.hpp"

using namespace std;
using namespace ariel;
#include <iostream>

Point::Point(double x, double y) : _x(x), _y(y){};

Point::Point()
{
    this->_x = 0;
    this->_y = 0;
}

double Point::getX() const
{
    return this->_x;
}

double Point::getY() const
{
    return this->_y;
}

void Point::setX(double new_x)
{
    this->_x = new_x;
}

void Point::setY(double new_y)
{
    this->_y = new_y;
}

void Point::print() const
{
    cout << "(" << this->getX() << "," << this->getY() << ")" << endl;
}

double Point::distance(const Point &other) const
{
    double result = sqrt(pow((this->_x - other.getX()), 2) + pow((this->_y - other.getY()), 2));
    return result;
}

Point Point::moveTowards(Point &first, Point &second, double distance)
{
    if (distance < 0)
    {
        throw invalid_argument("Distance between two points should be positive!");
    }

    // if the points are the same, just return one of them
    if ((first.getX() == second.getX()) && (first.getY() == second.getY()))
    {
        return first;
    }

    double current_d = first.distance(second);

    if (current_d <= distance)
    {
        return first;
    }

    // calculate the factor to move from the source point
    // towards the dest point by the given distance
    double scaleFactor = distance / current_d;

    double new_x = first.getX() + (scaleFactor * (second.getX() - first.getX()));
    double new_y = first.getY() + (scaleFactor * (second.getY() - first.getY()));

    Point newPoint;
    newPoint.setX(new_x);
    newPoint.setY(new_y);
    return newPoint;
}