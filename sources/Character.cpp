#include "Character.hpp"
using namespace std;
using namespace ariel;

Character::Character(string name, Point &location, int health) : name(name), location(location), health(health)
{
    this->assigned = false;
}

string Character::getName()
{
    return this->name;
}

Point Character::getLocation() const
{
    return this->location;
}

int Character::getHealth()
{
    return this->health;
}

bool Character::isAlive()
{
    if (this->health > 0)
    {
        return true;
    }
    else
        return false;
}

double Character::distance(Character *other)
{
    return getLocation().distance(other->getLocation());
}

void Character::hit(int points_to_take)
{
    if (points_to_take == 0)
    {
        throw invalid_argument("Can't reduce 0 amount of health!");
    }

    if (points_to_take < 0)
    {
        throw invalid_argument("Can't reduce negative amount of health");
    }

    this->health = this->health - points_to_take;
}

bool Character::isAssigned()
{
    return this->assigned;
}

void Character::assign(bool flag)
{
    this->assigned = flag;
}
