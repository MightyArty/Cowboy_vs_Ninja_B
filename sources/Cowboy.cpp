#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bullets(6){};

void Cowboy::shoot(Character *other)
{
    if (!(this->isAlive()) || !(other->isAlive()))
    {
        throw runtime_error("Can't shoot if the cowboy or the enemy is dead");
    }

    if (this->hasBoolets())
    {
        other->hit(10);
        reduceBoolets();
    }
}

void Cowboy::reduceBoolets()
{
    this->bullets = this->bullets - 1;
}

bool Cowboy::hasBoolets()
{
    if (this->bullets > 0)
    {
        return true;
    }
    else
        return false;
}

void Cowboy::reload()
{
    if (this->isAlive())
    {
        setBullets();
    }
    else
    {
        throw runtime_error("The cowboy is dead so can't reload the gun!");
    }
}

void Cowboy::setBullets()
{
    this->bullets = 6;
}

string Cowboy::print() const
{
    string s = "";
    s = s + "Cowboy " + this->name + ", Health: " + to_string(this->health) + ", Location: (" + to_string(this->location.getX()) + "," + to_string(this->location.getY()) + ")";
    return s;
}