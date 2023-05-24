#pragma once
#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

namespace ariel
{
    class YoungNinja : public Character
    {
    private:
        static const int MAX_HEALTH = 100;
        static const int MAX_SPEED = 14;
        int speed;

    public:
        YoungNinja(string name, ariel::Point location) : Character(std::move(name), location, MAX_HEALTH), speed(MAX_SPEED)
        {
        }

        void move(Character *other);

        void slash(Character *other);
        bool is_close(Character *other);
    };
}
