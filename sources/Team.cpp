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
#include "Team2.hpp"


using namespace std;
using namespace ariel;



void Team::add(Character *other)
{
    if(team.size() == 10) {
        throw runtime_error("Team is full");
    }
    else if(other -> getIsChoose() == true){
        throw runtime_error("Character is already in a team");
    }
    else{

    team.push_back(other);
    other->setIsChoose();
    }
}


// Character* Team::get_target(Team *other) {

//     Character *target1 = new Character();
//     Character *target2 = new Character();

//     double closet = std::numeric_limits<double>::max();

//     for (Character* c : other->get_team())
//     {
//         if (c->isAlive() && typeid(*c) == typeid(Cowboy) )
//         {
//             double temp = this->leader->distance(c);
//             if (closet > temp)
//             {
//                 closet = temp;
//                 target1 = c;
//             }
//         }
//     }

//     double closet2 = std::numeric_limits<double>::max();
//     for (Character* c : other->get_team()) {

//         if (c->isAlive() && typeid(*c) != typeid(Cowboy) )
//         {
//             double temp = this->leader->distance(c);
//             if (closet2 > temp)
//             {
//                 closet2 = temp;
//                 target2 = c;
//             }
//         }
//     }

//     if(this->get_leader()->distance(target1) < this->get_leader()->distance(target2)  ){
//         return target1;
//     }
//     else{
//         return target2;
//     }
    
// }

Character* Team::get_target(Team *other) {

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



void Team::attack(Team *other)

{

    if(other == nullptr ) {
        throw invalid_argument("Team is null");  
    }

    if(other->stillAlive() == 0 ) {
       throw runtime_error("Team is dead");
    }


    else if (this->leader->isAlive() == false)
    {
        Character *new_leader = new Character();
        double location = std::numeric_limits<double>::max();

        for (Character* c : this->team)
        {
            if (c -> isAlive())
            {
                
                double temp = this->leader->distance(c);
                if (location > temp)
                {
                    location = temp;
                    new_leader = c;
                }
            }
            
        }
        
        this->set_leader(new_leader);
    }

    Character *target = this->get_target(other);



    for (Character *c : this->team)
    {
        
        if (this ->stillAlive() == 0 || other->stillAlive() == 0)
        {
            cout << "The game is over" << endl;
            return;
        }

        if (target->isAlive() == false)
        {
            target = this->get_target(other);
            
        }

        if (typeid(*c) == typeid(Cowboy) && c->isAlive() && target->isAlive()) {
           
            Cowboy& cowboy = dynamic_cast<Cowboy&>(*c);
            
        
             cowboy.shoot(target);
        }

        else if (typeid(*c) == typeid(YoungNinja)) {
          
            YoungNinja& youngNinja = dynamic_cast<YoungNinja&>(*c);
            if(c->isAlive() == false) {
                break;;
            }
            if(youngNinja.is_close(target)) {
                youngNinja.slash(target);
            }
            else {
                youngNinja.move(target);
            }
        }
        else if(typeid(*c) == typeid(TrainedNinja)) {
           
            TrainedNinja& trainedNinja = dynamic_cast<TrainedNinja&>(*c);
            if(c->isAlive() == false) {
                break;;
            }
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



int Team::stillAlive()
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

void Team::print()
{

    for (Character* c : this->team)
    {
        if(typeid(*c) == typeid(Cowboy)){
 
            cout<< c->print()<< endl;
        }
    }
    for (Character* c : this->team)
    {

        if(typeid(*c) != typeid(Cowboy)){
         
            cout<< c->print()<< endl;

    }

    }
}
