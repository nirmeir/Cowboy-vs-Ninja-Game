#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>
#include <typeinfo>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;
using namespace ariel;


        int Character::getHealth() {
            return this->health;
        }

        bool Character::isAlive(){
            return this->health > 0;
        }
        
        //function that calculate the distance between two points
        double Character::distance(const ariel::Character *other){
            return this->location.distance(other->location);
        }

        void Character::hit(int hp){
        if (hp<0){
            throw invalid_argument("hp must be positive");
        }
            this->health -= hp;
        }
        

        std::string Character::print() {

            if(this->isAlive() == false) {
                if (typeid(*this) == typeid(Cowboy)){
                    return "C (" + this->name + ")" + " at " + this->location.print() ;
                }
                else if (typeid(*this) == typeid(YoungNinja)){
                    return "N (" + this->name + ")" + " at " + this->location.print() ;
                }
                else if (typeid(*this) == typeid(TrainedNinja)){
                    return "N (" + this->name + ")" + " at " + this->location.print() ;
                }
                else if (typeid(*this) == typeid(OldNinja)){
                    return "N (" + this->name + ")" + " at " + this->location.print() ;
                }
            } 
            
            return this->name + " is at " + this->location.print() + " with " + to_string(this->health) + " health";
             
        }
