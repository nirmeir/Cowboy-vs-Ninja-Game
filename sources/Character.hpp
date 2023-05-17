#pragma once
#include "Point.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

using namespace std;


namespace ariel {

    class Character{
        
        private:
        ariel::Point location;
        int health;
        string name;


        public:

        Character(string name, ariel::Point location, int health) :name(name), location(location), health(health){
           
        }

        string getName(){
            return this->name;
        }
        ariel::Point getLocation(){
            return this->location;
        }


        int getHealth();
        bool isAlive(); 
        double distance(ariel::Point &other);
        void hit(Character *other);
        string print();
           
    

       
    
    };
    
}