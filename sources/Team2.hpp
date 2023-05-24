#pragma once
#include "Character.hpp"
#include "Team.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>
#include <vector>

using namespace std;

namespace ariel
{

    class Team2 : public Team
    {


    public:
        using Team::attack;

        Team2(Character *leader): Team(leader){}


        Team2(const Team2&) = delete;
        Team2& operator=(const Team2&) = delete;
        Team2(Team2&&) = delete;
        Team2& operator=(Team2&&) = delete;

        vector<Character*> get_team() override {
            return this->_team;
        };

        Character* get_leader()override {
            return this->_leader;
        };

        void set_leader(Character* leader) override{
            this->_leader = leader;
        }
         void set_team(vector<Character*> team)override {
            this->_team = team;
            }

         void add(Character *other) override;
         void attack(Team *other) override;
         int stillAlive()override;
         void print()override;
          
         Character* get_target(Team *other) override;

        

        ~Team2() override = default ;

        
    };

    
}

