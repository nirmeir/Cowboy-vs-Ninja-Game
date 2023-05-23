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
        //default constructor
        virtual ~Character() {} // Virtual destructor
        Character() :name("def"), location(0,0), health(0), captain(false), isChoose(false){
        
        }

        Character(string name, ariel::Point location, int health) :name(name), location(location), health(health), captain(false), isChoose(false){
           
        }

        string getName(){
            return this->name;
        }
        ariel::Point getLocation(){
            return this->location;
        }
        void setLocation(ariel::Point location){
            this->location = location;
        }
        bool isCaptain(){
            return this->captain ;
        }
        void setCaptain(){
            this->captain = true;
        }
        bool getIsChoose(){
            return this->isChoose;
        }
        void setIsChoose(){
            this->isChoose = true;
        }


        int getHealth();
        bool isAlive(); 
        double distance(const Character *other) ;
        void hit(int hp);
        string print();
           
    

       
    
    };
    
}