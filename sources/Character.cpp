#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

using namespace std;
using namespace ariel;


        int Character::getHealth() {
            return this->health;
        }
        bool Character::isAlive(){
            return this->health > 0;
        }
        //function that calculate the distance between two points
        double Character::distance(ariel::Point &other){
            return this->location.distance(other);
        }
        void Character::hit(Character *other){
            other->health -= 10;
        
        }

        string Character::print(){
            if(this->health <= 0){
                return this->name + "is dead" + " at " + this->location.print();
            }
            return this->name + " is at " + this->location.print() + " with " + to_string(this->health) + " health";
        }
