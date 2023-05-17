#pragma once
#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

namespace ariel
{

    class Cowboy : public Character
    {

    private:
        int bullets;

    public:
        Cowboy(string name, ariel::Point location) : Character(name, location, 110), bullets(6)
        {
        }

        void shoot( Character *other) ;
        bool hasboolets();
        void reload() ;
       
    };

}
