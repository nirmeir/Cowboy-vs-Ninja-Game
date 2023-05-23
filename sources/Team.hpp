#pragma once
#include "Character.hpp"
#include <vector>
#include <string>
#include <iostream>


#include <stdbool.h>


using namespace std;

namespace ariel
{

    class Team 
    {

    protected:
        vector<Character*> team;
        Character *leader;

    public:
        Team(Character* leader) 
        {
            if (leader->isCaptain() == true){
                throw runtime_error("is already captain");
            } else {
                leader->setCaptain();
                leader->setIsChoose();
                this->set_leader(leader);
                this->set_team(team);
                

                team.push_back(leader);

            }
        };

        virtual vector<Character*> get_team() {
            return this->team;
        };

        virtual Character* get_leader() {
            return this->leader;
        };

        virtual void set_leader(Character* leader) {
            this->leader = leader;
        }

        virtual void set_team(vector<Character*> team) {
            this->team = team;
            }


         virtual void add(Character *other) ;
         virtual void attack(Team *other);
         virtual int stillAlive();
         virtual void print();
         virtual Character* get_target(Team *other);



        ~Team(){

        };
    };

}
