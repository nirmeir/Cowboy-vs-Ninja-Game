#include "Cowboy.hpp"
#include <stdbool.h>

using namespace std;
using namespace ariel;


     void Cowboy::shoot( Character *other) 
        {

         
             if(this->isAlive() == false || other == this) {

                 throw runtime_error("### is already dead 2");

             }

             if(other -> isAlive() == false ) {
                throw runtime_error("is already dead cowboy");
            }

            if(this->hasboolets() == false && this->isAlive() == true){
                this->reload();
            }

            else if(this->bullets > 0 && this->getHealth() > 0){
                // cout << this->getName() << " shoots " << other->getName() << endl;
                other->hit(10);
                // cout<<this->getName()<<" hits  "<<other->getName()<< other->getHealth()<<endl;

                this->bullets--;
            }
        }

        bool Cowboy::hasboolets()
        {
           return this->bullets > 0;
        }

        void Cowboy::reload() 
        {
            if(this->isAlive() == false) {
                throw runtime_error("### is already dead reload ");
            }

            this->bullets = 6;
        }
