#include "Team2.hpp"
using namespace std;
using namespace ariel;

Team2::Team2(Character *member) : Team(member) {}

void Team2::attack(Team *other)
{
    if (other == nullptr)
    {
        throw std::invalid_argument("The attacked team does not have warriors!");
    }

    if (this->stillAlive() == 0)
    {
        throw invalid_argument("The team has no warriors");
    }

    if (this == other)
    {
        throw invalid_argument("Can't attack members of the same team!");
    }

    if (other->stillAlive() == 0)
    {
        throw runtime_error("The enemy team has no warriors");
    }

    if (!(other->get_team_leader()->isAlive()))
    {
        other->get_team_leader()->assign(false);
        other->set_team_leader(nextLeader(other, other->get_team_leader()));
    }

    if (!(this->get_team_leader()->isAlive()))
    {
        this->get_team_leader()->assign(false);
        this->set_team_leader(nextLeader(this, this->get_team_leader()));
    }

    if ((this->get_team_leader() == nullptr) || (other->get_team_leader() == nullptr))
    {
        return;
    }

    Character *enemy = nextLeader(other, this->get_team_leader());
    if (enemy != nullptr)
    {
        for (auto i : this->getWarriorsGroup())
        {
            if (!(enemy->isAlive()))
            {
                enemy = nextLeader(other, enemy);
            }

            if ((this->stillAlive() == 0) || (other->stillAlive() == 0))
            {
                return;
            }

            if (!(i->isAlive()))
                continue;

            Ninja *ninja = dynamic_cast<Ninja *>(i);
            if (ninja != nullptr)
            {
                if (ninja->distance(enemy) <= 1)
                {
                    ninja->slash(enemy);
                }
                else
                {
                    ninja->move(enemy);
                }
            }

            Cowboy *cowboy = dynamic_cast<Cowboy *>(i);
            if (cowboy != nullptr)
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(enemy);
                }
                else
                {
                    cowboy->reload();
                }
            }
        }
    }
    else if (enemy == nullptr)
        return;
}
