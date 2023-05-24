#include "Team2.hpp"
#include "Team.hpp"

#include <string>
#include <iostream>
#include <stdbool.h>
#include <vector>
#include "Character.hpp"
#include "Point.hpp"
#include <limits>
#include <typeinfo>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


using namespace std;
using namespace ariel;

void Team2::add(Character *other)
{
    if(this->_team.size() == 10) {
        throw runtime_error("Team is full");
    }
    else if(other -> getIsChoose() == true){
        throw runtime_error("Character is already in a team");
    }
    else{

    this->_team.push_back(other);
    other->setIsChoose();
    }
}





Character* Team2::get_target(Team *other) {

    Character *target = new Character();
    double closet = std::numeric_limits<double>::max();

    for (Character* c : other->get_team())
    {

        if (c->isAlive())
        {
            double temp = this->get_leader()->distance(c);
            if (closet > temp)
            {
                closet = temp;
                target = c;
            }
        }
    }

    return target;
}




void Team2::attack(Team *other)

{

    if(other == nullptr ) {
        throw invalid_argument("Team is null");  
    }

    if(other->stillAlive() == 0 ) {
       throw runtime_error("Team is dead");
    }


    else if (this->get_leader()->isAlive() == false)
    {
        Character *new_leader = new Character();
        double location = std::numeric_limits<double>::max();

        for (Character* c : this->get_team())
        {
            if (c -> isAlive())
            {
                double temp = this->get_leader()->distance(c);
                if (location > temp)
                {
                    location = temp;
                    new_leader = c;
                }
            }

        }
            this->set_leader( new_leader);

    }
    
    Character *target = this->get_target(other);


    for (Character *c : this->get_team())
    {
        
        if (this ->stillAlive() == 0 || other->stillAlive() == 0)
        {
            cout << "The game is over" << endl;
            return;
        }

        if (target->isAlive() == false)
        {
            target = this->get_target(other);
            // other -> set_leader(target);
        }

        if (typeid(*c) == typeid(Cowboy) && c->isAlive()) {
            Cowboy& cowboy = dynamic_cast<Cowboy&>(*c);
            
        
             cowboy.shoot(target);
        }

        else if (typeid(*c) == typeid(YoungNinja)) {
            
            if(c->isAlive() == false) {
                break;;
            }
            YoungNinja& youngNinja = dynamic_cast<YoungNinja&>(*c);
            if(youngNinja.is_close(target)) {
                youngNinja.slash(target);
            }
            else {
                youngNinja.move(target);
            }
        }
        else if(typeid(*c) == typeid(TrainedNinja)) {
            if(c->isAlive() == false) {
                break;;
            }
            TrainedNinja& trainedNinja = dynamic_cast<TrainedNinja&>(*c);
            if(trainedNinja.is_close(target)) {
                trainedNinja.slash(target);
            }
            else {
                trainedNinja.move(target);
            }
        }
        else if(typeid(*c) == typeid(OldNinja)) {
            if(c->isAlive() == false) {
                break;;
            }
            OldNinja& oldNinja = dynamic_cast<OldNinja&>(*c);
            if(oldNinja.is_close(target)) {
                oldNinja.slash(target);
            }
            else {
                oldNinja.move(target);
            }
        }
        else {


            cout << "error" << endl;
        }
              
    }
}



int Team2::stillAlive()
{
    int count = 0;
    
    for (Character* c : this->get_team())
    {
        if (c->isAlive())
        {
            count++;
        }
    }
    return count;
}

void Team2::print()
{

    for (Character* c : this->get_team())
    {
      
        cout<< c->print()<< endl;

        }

}




