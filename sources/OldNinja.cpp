#include "OldNinja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>

using namespace std;
using namespace ariel;


void OldNinja::move (Character *other){
    this->setLocation(Point::moveTowards(this->getLocation(), other->getLocation(), this->speed)) ;
}        

void OldNinja::slash(Character *other){
    if(this->isAlive() == false || other->isAlive() == false){
        throw runtime_error("the character are dead 5");
        return;
    }
     else if (other->isAlive() == false || other == this){
        throw runtime_error("the character are dead 6");
        return;
    }

    else if(this->getLocation().distance(other->getLocation()) < 1){
        other->hit(40);
    }
    else{
        cout << "Target is too far away" << endl;
    }
}    
bool OldNinja::is_close(Character *other)
{
    return (this->getLocation().distance(other->getLocation()) < 1);
} 