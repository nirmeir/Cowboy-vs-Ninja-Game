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
        vector<Character*> _team;
        Character *_leader;

    public:
        Team(Character* leader) : _leader(nullptr) //NOLINT
        {

            if(!leader->isCaptain()) {
                leader->setCaptain();
                leader->setIsChoose();
                this->set_leader(leader);
                this->set_team(_team);
                _team.push_back(leader);

            }
        
            else if (leader->isCaptain()){
                throw runtime_error("is already captain");
            } 
        
        
            
        };

        Team(const Team&) = delete;
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;

        virtual vector<Character*> get_team() {
            return this->_team;
        };

        virtual Character* get_leader() {
            return this->_leader;
        };

        virtual void set_leader(Character* leader) {
            this->_leader = leader;
        }

        virtual void set_team(vector<Character*> team) {
            this->_team = team;
            }


         virtual void add(Character *other) ;
         virtual void attack(Team *other);
         virtual int stillAlive();
         virtual void print();
         virtual Character* get_target(Team *other);



        virtual ~Team() = default;

    };

}
