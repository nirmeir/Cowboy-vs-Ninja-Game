#include <iostream>
#include <string>
#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Team.hpp"
#include "sources/Point.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("TESTS"){
    Point p1(1,2);
    Point p2(3,4);
    Point p3(8.2,4.14);
    Point p4(13,24.14);
    Point p5(4,5);
    Point p6(6,7);
    Point p7(8,9);

    CHECK_NOTHROW(Cowboy *c1 = new Cowboy("Nir",p1));
    CHECK_NOTHROW(OldNinja *n1 = new OldNinja("Moshe",p2));
    Cowboy *Nir = new Cowboy("Nir",p1);
    OldNinja *Moshe = new OldNinja("Moshe",p2);
    YoungNinja *Yossi = new YoungNinja("Yossi",p3);
    TrainedNinja *Tal = new TrainedNinja("Tal",p4);
    Cowboy *Or = new Cowboy("Or",p5);
    OldNinja *Yoni = new OldNinja("Yoni",p6);
    YoungNinja *Yael = new YoungNinja("Yael",p7);

    CHECK(p1.distance(p2)==2.8284271247461903);
    CHECK_NOTHROW(p1.print());
    CHECK(p1.print()=="(1,2)");
    CHECK(Nir->getName()=="Nir");
    CHECK_NOTHROW(Nir->getLocation());
    CHECK(Nir->getHealth()==100);
    CHECK(Nir->isAlive()==true);
    CHECK(Nir->hasboolets()==true);
    CHECK_NOTHROW(Nir->reload());
    CHECK_NOTHROW(Nir->shoot(Moshe));
    CHECK_NOTHROW(Nir->hit(Moshe));

    Team *t1 = new Team(Nir);
    CHECK_NOTHROW(t1->add(Yossi));
    CHECK_NOTHROW(t1->add(Moshe));

    Team *t2 = new Team(Tal);
    CHECK_NOTHROW(t2->add(Or));
    CHECK_NOTHROW(t2->add(Yoni));
    CHECK_NOTHROW(t2->add(Yael));
    CHECK_NOTHROW(t1->attack(t2));
    CHECK_NOTHROW(t2->attack(t1));
    CHECK_NOTHROW(t1->print());

}
