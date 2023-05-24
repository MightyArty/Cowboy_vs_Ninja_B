#include "Team.hpp"

#include <limits>

using namespace std;
using namespace ariel;

Team::Team(Character *other) : team_leader(other)
{
    this->getWarriorsGroup().clear();
    if (team_leader->isAssigned())
    {
        throw runtime_error("The given Character is already assigned to another team!");
    }

    this->warriors_group.push_back(team_leader);
    team_leader->assign(true);
}

Team::~Team()
{
    for (size_t i = 0; i < getWarriorsGroup().size(); i++)
    {
        delete warriors_group.at(i);
    }
}

void Team::set_team_leader(Character *leader)
{
    this->team_leader = leader;
}

Character *Team::get_team_leader()
{
    return this->team_leader;
}

vector<Character *> &Team::getWarriorsGroup()
{
    return this->warriors_group;
}

Character *Team::nextLeader(Team *team, Character *current)
{
    if (team == nullptr)
    {
        throw runtime_error("The team does not have any warriors!");
    }

    if (current == nullptr)
    {
        throw runtime_error("The current team leader is dead!");
    }

    double distance = 0;
    double inf = numeric_limits<double>::max();
    Character *newLeader = nullptr;

    for (auto i : team->getWarriorsGroup())
    {
        if ((i->isAlive()) && (i != current))
        {
            distance = current->distance(i);
            if (inf > distance)
            {
                newLeader = i;
                inf = distance;
            }
        }
    }
    return newLeader;
}

void Team::add(Character *member)
{
    if (member == nullptr)
    {
        throw runtime_error("You are trying to add null pointer!");
    }

    if (this->getWarriorsGroup().size() >= 10)
    {
        throw runtime_error("The team already have 10 warriors");
    }

    if (member->isAssigned())
    {
        throw runtime_error("The given Character is already assigned to another team");
    }

    this->getWarriorsGroup().push_back(member);
    member->assign(true);
}

/**
 * @brief Function to attak the other team by the rules that was given.
 * First go through the Cowboy's and then go through the Ninja's
 * @param other_team the enemy team to attak
 */
void Team::attack(Team *other_team)
{
    if (other_team == nullptr)
    {
        throw invalid_argument("The attacked team does not have warriors");
    }

    if (this->stillAlive() == 0)
    {
        throw invalid_argument("The attacking or attacked team has no warriors");
    }

    if (other_team->stillAlive() == 0)
    {
        throw runtime_error("The attacked team does not have warriors!");
    }

    if (this == other_team)
    {
        throw invalid_argument("Can't attack members of the same team");
    }

    // check for leader
    if (!(this->team_leader->isAlive()))
    {
        this->team_leader->assign(false);
        this->set_team_leader(nextLeader(this, this->team_leader));
    }

    // check for enemy team leader
    if (!(other_team->get_team_leader()->isAlive()))
    {
        other_team->get_team_leader()->assign(false);
        other_team->set_team_leader(nextLeader(other_team, other_team->get_team_leader()));
    }

    // if the assigment of new leader failed -> exit
    if ((this->get_team_leader() == nullptr) || (other_team->get_team_leader() == nullptr))
    {
        return;
    }

    // find the enemy to attack
    Character *enemy = nextLeader(other_team, this->get_team_leader());
    if (enemy != nullptr)
    {
        // Iterate through the Cowboy's
        for (auto i : this->getWarriorsGroup())
        {
            // check if there still members in both teams
            if ((this->stillAlive() == 0) || (other_team->stillAlive() == 0))
            {
                return;
            }
            // if the enemy team leader is dead, find new one to attack
            if (!(enemy->isAlive()))
            {
                enemy = nextLeader(other_team, enemy);
            }

            // if the warrior is dead continue to search for new one
            if (!(i->isAlive()))
            {
                continue;
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

        // Iterate through the Ninja's
        for (auto i : this->getWarriorsGroup())
        {
            // check if there still members in both teams
            if ((this->stillAlive() == 0) || (other_team->stillAlive() == 0))
            {
                return;
            }
            // if the enemy team leader is dead, find new one to attack
            if (!(enemy->isAlive()))
            {
                enemy = nextLeader(other_team, enemy);
            }

            // if the warrior is dead continue to search for new one
            if (!(i->isAlive()))
            {
                continue;
            }

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
        }
    }
    else if (enemy == nullptr)
        return;
}

/**
 * @brief Check if the members of the given team is still alive
 * @return the number of live members
 */
int Team::stillAlive()
{
    int counter = 0;

    for (auto i : getWarriorsGroup())
    {
        if (i && i->getHealth() > 0)
        {
            counter++;
        }
    }
    return counter;
}

/**
 * @brief Iterate through the warrior vector and print each warrior
 */
void Team::print()
{
    for (auto i : getWarriorsGroup())
    {
        cout << i->print() << endl;
    }
}
