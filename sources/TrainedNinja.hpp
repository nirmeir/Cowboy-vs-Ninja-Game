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
        int speed;

    public:
        TrainedNinja(string name, ariel::Point location) : Character(name, location, 120),speed(12)
        {
        }


        void move(Character &other);        
        void slash(Character &other);          
     
    };
}
