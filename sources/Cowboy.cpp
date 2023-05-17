#include "Cowboy.hpp"
#include <stdbool.h>

using namespace std;
using namespace ariel;


     void Cowboy::shoot( Character *other) 
        {
        }

        bool Cowboy::hasboolets()
        {
            return true;
        }

        void Cowboy::reload() 
        {
            this->bullets = 6;
        }
