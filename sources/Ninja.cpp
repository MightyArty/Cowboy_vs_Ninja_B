#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int speed, int health) : Character(name, location, health), speed(speed) {}

string Ninja::print() const
{
    string s = "";
    s = s + "Ninja " + this->name + ", Health: " + to_string(this->health) + ", Location (" + to_string(this->location.getX()) + "," + to_string(this->location.getY()) + ")";
    return s;
}

void Ninja::move(Character *other)
{
    this->location = Point::moveTowards(this->location, other->getLocation(), this->speed);
}

void Ninja::slash(Character *other)
{
    if (!(this->isAlive()) || !(other->isAlive()))
    {
        throw runtime_error("The Ninja or the Enemy are not alive!");
    }

    if (this->distance(other) <= 1)
    {
        other->hit(40);
    }
}

int Ninja::getHealth()
{
    return this->health;
}