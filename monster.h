#ifndef MONSTER_H
#define MONSTER_H

#include<vector>
#include "loc.h"

class Monster {

private:
    int health_monster;
    int strength_monster;
    vector<vector<loc> > region;


public:
    Monster(); // default constructor
    void city_attack(vector<vector<loc> >& region); // function for attacking the city
    void people_injury(vector<vector<loc> >& region); // function for injuring the people
    void hero_approach(vector<vector<loc> >& region, int& happiness); // function for the monster to approach the hero
    bool monster_defeat(); // function to check if the hero defeated the monster

};

#endif
