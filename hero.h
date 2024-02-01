#ifndef HERO_H
#define HERO_H

#include "loc.h"
#include "residential.h"

void move_towards_monster(vector<vector<loc> >& region, int& hero_xcoordinate, int& hero_ycoordinate); // function for moving the hero towards the monster
void monster_attack_stop(vector<vector<loc> >& region, int& hero_xcoordinate, int& hero_ycoordinate, bool& death_of_monster, bool& death); // function for stopping the monster attack
bool residential_adjacent_hero(vector<vector<loc> >& region, int i, int j); // checking if the hero is adjacent to hero 
bool hero_death(const bool& death); // function for determining if the hero is dead or not
void population_decrease(vector<vector<loc> >& region, bool& death); // function for decreasing the population if the hero dies
void happiness_increase(vector<vector<loc> >& region, bool& death, bool& death_of_monster); // function for increasing the happiness if the hero wins
void hero_simulation(const vector<vector<loc> >& region); // function for printing out the hero 

#endif
