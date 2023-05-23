#include "YoungNinja.hpp"

using namespace std;
using namespace ariel;

void YoungNinja::move(Character *other)
{
    this->setLocation(Point::moveTowards(this->getLocation(), other->getLocation(), this->speed));
}

void YoungNinja::slash(Character *other)
{
    if (this->isAlive() == false || other == this)
    {
       throw runtime_error("the character are dead 3");
        return;
    }
    else if (other->isAlive() == false) {
        throw runtime_error("the character are dead 4");
        return;
    }

    else if (this->getLocation().distance(other->getLocation()) < 1)
    {
        other->hit(40);
    }
    else
    {
        cout << "Target is too far away" << endl;
    }
}

bool YoungNinja::is_close(Character *other)
{
    return (this->getLocation().distance(other->getLocation()) < 1);
}

