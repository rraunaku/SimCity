#include "hero.h"
#include<cmath>

void move_towards_monster(vector<vector<loc> >& region, int& hero_xcoordinate, int& hero_ycoordinate) { // Moving the hero towards the monster
    // First finding the location of the monster
    int monster_xcoordinate = -1;
    int monster_ycoordinate = -1;

    for (int i = 0; i < region.size(); i++) {
        for (int j = 0; j < region[i].size(); j++) {
            if (region[i][j].regionType == 'M') {
                monster_xcoordinate = i;
                monster_ycoordinate = j;
                break;
            }
        }

        if (monster_xcoordinate != -1) {
            break;
        }
    }

    if (hero_xcoordinate == monster_xcoordinate && hero_ycoordinate == monster_ycoordinate) { // Checking if the hero's location and monster's location is the same as the monster
        return; // hero is at the monster's location
    }

    // Determining the direction the monster towards the monster
    int dx = (monster_xcoordinate > hero_xcoordinate) ? 1 : (monster_xcoordinate < hero_xcoordinate) ? -1 : 0;
    int dy = (monster_ycoordinate > hero_ycoordinate) ? 1 : (monster_ycoordinate < hero_ycoordinate) ? -1 : 0;

    //Updating the hero's coordinates
    hero_xcoordinate += dx;
    hero_ycoordinate += dy;
}

void monster_attack_stop(vector<vector<loc> >& region, int& hero_xcoordinate, int& hero_ycoordinate, bool& death_of_monster, bool& death) { // Stopping the attack of the monster

    // Finding the location of the monster in the region
    int monster_xcoordinate = -1;
    int monster_ycoordinate = -1;

    for (int i = 0; i < region.size(); i++) {
        for (int j = 0; j < region[i].size(); j++) {
            if (region[i][j].regionType == 'M') {
                monster_xcoordinate = i;
                monster_ycoordinate = j;
                break;
            }
        }

        if (monster_xcoordinate != -1) {
            break;
        }
    }
    // Checking if the hero's location is the same as the monster
    if (hero_xcoordinate == monster_xcoordinate && hero_ycoordinate == monster_ycoordinate) {
        // region[monster_xcoordinate][monster_ycoordinate].regionType = 'M';
        death_of_monster = true;

        if (residential_adjacent_hero(region, hero_xcoordinate, hero_ycoordinate)) {
            // region[monster_xcoordinate][monster_ycoordinate].regionType = 'M';
            death_of_monster = true;
            region[hero_xcoordinate][hero_ycoordinate].regionType = 'R';
        }
    }
}

bool residential_adjacent_hero(vector<vector<loc> >& region, int i, int j) { // Checking if the hero is adjacent to the residential area
    vector<loc> x = isAdj(region, i, j);
    int number_of_rows = region.size();
    int number_of_column = region[0].size();

    for (int i = 0; i < x.size(); i++) {
        if (x[i].regionType == 'R') {
            return true;
        }

    }

    return false;
}

bool hero_death(const bool& death) { // Checking the status of the hero
    return death;
}


void population_decrease(vector<vector<loc> >& region, bool& death) { // Decreasing the population if the hero is dead
    if (death) { // Checking if the hero is dead
        return;
    }

    for (int i = 0; i < region.size(); i++) { // Decreasing the population of the residential area if hero is dead
        for (int j = 0; j < region[i].size(); j++) {
            if (region[i][j].regionType == 'R') {
                region[i][j].population--;

                if (region[i][j].population < 0) {
                    region[i][j].population = 0;
                }
            }
        }
    }

    death = true;
}

void happiness_increase(vector<vector<loc> >& region, bool& death, bool& death_of_monster) { // increasing the happiness of the population
    int maximum_happiness = 10;
    // Checking if hero is alive and monster is dead
    if (death || !death_of_monster) {
        return;
    }

    for (int i = 0; i < region.size(); i++) { // Increasing the happiness of the residential region
        for (int j = 0; j < region[i].size(); j++) {
            if (region[i][j].regionType == 'R') {
                region[i][j].happiness += 1;

                if (region[i][j].happiness > maximum_happiness) {
                    region[i][j].happiness = maximum_happiness;
                }
            }
        }
    }

    death_of_monster = true;
}

void hero_simulation(const vector<vector<loc> >& region) {
    for (const auto& row : region) {
        for (const auto& cell : row) {
            cout << cell.regionType << ' ';
        }
        cout << endl;
    }
}
