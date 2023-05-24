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
        static const int MAX_HEALTH = 110;
        static const int MAX_BULLETS = 6;
        int bullets;

    public:
        Cowboy(string name, ariel::Point location) : Character(std::move(name), location, MAX_HEALTH), bullets(MAX_BULLETS)
        {
        }

        void shoot( Character *other) ;
        bool hasboolets();
        void reload() ;
       
    };

}
