#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    protected:
        int speed;

    public:
        /**
         * @brief Constructor of new Ninja
         * @param name the Ninja name
         * @param location the location of the Ninja on the board
         * @return new object of Ninja
         */
        Ninja(string name, Point location, int speed, int health);

        /**
         * Overriding the Character function of print
         */
        string print() const override;

        /**
         * @brief Moves towards the enemy Character
         */
        void move(Character *other);

        /**
         * @brief Taking points from other Character object by slashing him
         */
        void slash(Character *other);
    };
}

#endif