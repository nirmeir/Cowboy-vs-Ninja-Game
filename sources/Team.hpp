#pragma once
#include "Character.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>
#include <vector>

using namespace std;

namespace ariel
{

    class Team
    {

    private:
        vector<Character> team;
        Character *leader;

    public:
        Team(Character *leader) : leader(leader)
        {
            team.push_back(*leader);
        }

        void add(Character *other);
        void attack(Team *other);
        int stillAlive();
        string print();

        ~Team(){

        };
    };
}
