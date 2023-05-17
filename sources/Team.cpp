#include "Team.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>
#include <vector>

using namespace std;
using namespace ariel;

void Team::add(Character *other)
{
    team.push_back(*other);
}


void Team::attack( Team *other){}

int Team::stillAlive(){
    return 0;
}
string Team::print(){
    return "";}

