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
        bool captain;
        bool isChoose;


        public:
        Character() :name("def"), location(0,0), health(0), captain(false), isChoose(false){
        
        }
        Character(string name, ariel::Point location, int health) : name(std::move(name)), location(location), health(health), captain(false), isChoose(false){
        }


        virtual ~Character() = default;
        Character(const Character&) = default;
        Character& operator=(const Character&) = default;
        Character(Character&&) = default;
        Character& operator=(Character&&) = default;

        string getName() const{
            return this->name;
        }
        ariel::Point getLocation() const{
            return this->location;
        }
        void setLocation(const ariel::Point location){
            this->location = location;
        }
        bool isCaptain()const {
            return this->captain ;
        }
        void setCaptain(){
            this->captain = true;
        }
        bool getIsChoose() const {
            return this->isChoose;
        }
        void setIsChoose(){
            this->isChoose = true;
        }

        int getHealth() const;
        bool isAlive() const; 
        double distance(const Character *other)  ;
        void hit(int health);
        string print();
           
    

       
    
    };
    
}