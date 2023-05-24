#pragma once
#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

namespace ariel
{
    class OldNinja : public Character
    {
    private:
        static const int MAX_HEALTH = 150;
        static const int MAX_SPEED = 8;
        int speed;

    public:
        OldNinja(string name,Point location) : Character(std::move(name), location, MAX_HEALTH),speed(MAX_SPEED)
        {
        }

        void move (Character *other);        
        void slash(Character *other);         
        bool is_close(Character *other);
  

        
    };
}
