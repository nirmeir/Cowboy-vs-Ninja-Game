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

    class SmartTeam : public Team   //NOLINT
    {


    public:
        using Team::attack;

        SmartTeam(Character *leader): Team(leader) {} 
        SmartTeam(const SmartTeam&) = delete;
        SmartTeam& operator=(const SmartTeam&) = delete;
        SmartTeam(SmartTeam&&) = delete;
        SmartTeam& operator=(SmartTeam&&) = delete;


        vector<Character*> get_team() override {
            return this->get_team();
        };

        Character* get_leader()override {
            return this->get_leader();
        };

        void set_leader(Character* leader) override{
            this->set_leader(leader);
        }
         void set_team(vector<Character*> team)override {
            this->set_team(team);
            }

         void add(Character *other) override;

         void attack(Team *other) override;

         int stillAlive()override;
         void print()override;
         Character* new_target(Team* other);
          
        //  Character* get_target(Team *other) override;

        

        ~SmartTeam() override = default;

    };

    
}

