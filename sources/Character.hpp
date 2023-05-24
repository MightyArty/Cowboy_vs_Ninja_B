#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        Point location; // location of the Carachter on the board
        int health;
        string name;
        bool assigned;

    public:
        Character(string name, Point &location, int health);
        virtual ~Character() = default;

        /**
         * @brief Virtual function to overide
         * @return the name of the Player
         */
        string getName();

        /**
         * @brief Virtual function to overide
         * @return the location of the Player
         */
        Point getLocation() const;

        /**
         * @brief Virtual function to override
         * @return the amount of health
         */
        int getHealth();

        /**
         * @return true if the given Character is alive, false otherwise
         */
        virtual bool isAlive();

        /**
         * @return the distance between the two Characters
         * @param other the second Character to compare
         */
        virtual double distance(Character *other);

        /**
         * @brief reduces the given points from the health of the Character
         * @param points the amount of health to take
         */
        virtual void hit(int points_to_take);

        /**
         * @brief Function to check if the Character is already in Team
         * @return true if the Characer is assigned, false otherwise
         */
        virtual bool isAssigned();

        /**
         * @brief Assigning Character to a team by raising the flag
         */
        virtual void assign(bool flag);

        virtual string print() const = 0;
    };
}

#endif
