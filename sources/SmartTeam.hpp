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

    class SmartTeam : public Team
    {


    public:
        using Team::attack;

        SmartTeam(Character *leader): Team(leader){}

        vector<Character*> get_team() override {
            return this->team;
        };

        Character* get_leader()override {
            return this->leader;
        };

        void set_leader(Character* leader) override{
            this->leader = leader;
        }
         void set_team(vector<Character*> team)override {
            this->team = team;
            }

         void add(Character *other) override;

         void attack(Team *other) override;

         int stillAlive()override;
         void print()override;
         Character* new_target(Team* other);
          
        //  Character* get_target(Team *other) override;

        

        ~SmartTeam(){

        };
    };

    
}

