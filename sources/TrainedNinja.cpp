#include "TrainedNinja.hpp"


using namespace std;
using namespace ariel;


void TrainedNinja::move (Character *other){
    this->setLocation(Point::moveTowards(this->getLocation(), other->getLocation(), this->speed)) ;
}        

void TrainedNinja::slash(Character *other){
    if(this->isAlive() == false || other->isAlive() == false || other == this){
       throw runtime_error("the character are dead 1");
        return;
    }
     else if (other->isAlive() == false ){
        throw runtime_error("the character are dead 2");
        return;
    }

    else if(this->getLocation().distance(other->getLocation()) < 1){
        other->hit(40);
    }
    else{
        cout << "Target is too far away" << endl;
    }
}

bool TrainedNinja::is_close(Character *other)
{
    return (this->getLocation().distance(other->getLocation()) < 1);
}          