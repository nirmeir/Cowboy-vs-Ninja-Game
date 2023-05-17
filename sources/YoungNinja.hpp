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
        int speed;

    public:
        YoungNinja(string name, ariel::Point location) : Character(name, location, 100),speed(14)
        {
        }

        void move (Character &other);         
        void slash(Character &other);        
    

        
    };
}
