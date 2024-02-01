#include "monster.h"
#include "residential.h"
#include "loc.h"
#include <cmath>

Monster::Monster() {
    int x = rand() % region.size();
    int y = rand() % region[0].size();
    health_monster = 100; // the initial health of the monster
    strength_monster = 100;  // the initial strength of the monster
}

void Monster::city_attack(vector<vector<loc> >& region) {
    int attacking_at_x = rand() % region.size();
    int attacking_at_y = rand() % region[0].size();

    if (region[attacking_at_x][attacking_at_y].regionType == 'R') { // Checking if the location is the Residential area

        int amount_of_damage = rand() % 100 + 1;
        region[attacking_at_x][attacking_at_y].population -= amount_of_damage;
        if (region[attacking_at_x][attacking_at_y].population < 0) {
            region[attacking_at_x][attacking_at_y].population = 0;
        }
    }
}


void Monster::people_injury(vector<vector<loc> >& region) {

    int injury_at_x = rand() % region.size();
    int injury_at_y = rand() % region[0].size();


    if (region[injury_at_x][injury_at_y].regionType == 'R' && region[injury_at_x][injury_at_y].population > 0) {
        int number_of_injuries = rand() % 5 + 1;
        region[injury_at_x][injury_at_y].population -= number_of_injuries;
    }

    if (region[injury_at_x][injury_at_y].population < 0) {
        region[injury_at_x][injury_at_y].population = 0;
    }
}


void Monster::hero_approach(vector<vector<loc> >& region, int& happiness) {
    int monster_xcoordinate = rand() % region.size();
    int monster_ycoordinate = rand() % region[0].size();


    region[monster_xcoordinate][monster_ycoordinate].regionType = 'M';


    bool victory_of_hero = (rand() % 2 == 0); // The chance of the hero winning is 50%

    if (victory_of_hero) {
        happiness += 1;
    }

    region[monster_xcoordinate][monster_ycoordinate].regionType = ' ';
}

bool Monster::monster_defeat() {
    if (health_monster <= 0) {
        return true;
    }

    else {
        return false;
    }
}
