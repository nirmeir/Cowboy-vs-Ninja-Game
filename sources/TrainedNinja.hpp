#pragma once
#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

namespace ariel
{
    class TrainedNinja : public Character
    {
    private:
        static const int MAX_HEALTH = 120;
        static const int MAX_SPEED = 12;
        int speed;

    public:
        TrainedNinja(string name, ariel::Point location) : Character(std::move(name), location, MAX_HEALTH),speed(MAX_SPEED)
        {
        }


        void move(Character *other);        
        void slash(Character *other);  
        bool is_close(Character *other);
        
     
    };
}
