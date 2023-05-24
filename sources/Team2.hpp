#ifndef TEAM_2_HPP
#define TEAM_2_HPP

#include <vector>

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        /**
         * @brief Main constructor
         */
        Team2(Character *member);

        /**
         * @brief De-Constructor
         */
        ~Team2() override = default;

        void attack(Team *other_team) override;
    };
}

#endif