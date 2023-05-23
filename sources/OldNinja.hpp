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
        int speed;

    public:
        OldNinja(string name,Point location) : Character(name, location, 150),speed(8)
        {
        }

        void move (Character *other);        
        void slash(Character *other);         
        bool is_close(Character *other);
  

        
    };
}
