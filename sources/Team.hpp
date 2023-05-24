#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"

#include <vector>

constexpr int NUM_WARRIORS = 10;

namespace ariel
{
    class Team
    {
    private:
        Character *team_leader;
        vector<Character *> warriors_group{NUM_WARRIORS};

    public:
        /**
         * @brief Main Constructor
         */
        Team(Character *other);

        /**
         * @brief De-Constructor
         */
        virtual ~Team();

        /**
         * @brief Getter for the current team leader
         */
        Character *get_team_leader();

        /**
         * @brief Getter for the vector of warriors
         * @return the team vector of warriors
         */
        vector<Character *> &getWarriorsGroup();

        /**
         * @brief Set a new Team Leader from the left warriors
         */
        void set_team_leader(Character *new_team_leader);

        /**
         * @brief Searching for the next leader in the team
         * @param team the given team of warriors
         * @param current the current leader
         * @return the closest member to the leader
         */
        Character *nextLeader(Team *team, Character *current);

        /**
         * @brief adding new member to the team
         * @param member the new Character that would be added
         */
        void add(Character *member);

        virtual void attack(Team *other_team);

        /**
         * @brief Checking if the team is alive
         * @return the number of members that are still alive
         */
        virtual int stillAlive();

        /**
         * @brief Iterate through the Warriors vector and print each warrior
         */
        virtual void print();
    };
}

#endif