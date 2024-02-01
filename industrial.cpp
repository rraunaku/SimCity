#include "industrial.h"
using namespace std;


void updateIndustrial(vector<vector<loc> >& region, int& workers, int& goods) {


    for (int i = 0; i < region.size(); i++) { // checks every location
        for (int j = 0; j < region[i].size(); j++) {
            if (region[i][j].regionType == 'I' && workers >= 2) {
                bool adjacentToPowerline = false;// sets the default value 
                int adjacentWithPopulationOne = 0; // counter to track the adjacency
                int adjacentWithPopulationTwo = 0; // counter to track the required population adjancency

                
                    vector<loc> temp = isAdj(region, i, j);// creates a vector to store all the adjacent region
                    for (int s = 0; s < temp.size(); s++)// goes through the adjacency list
                    {
                        if (temp[s].regionType == 'T' || temp[s].regionType == '#')// if the region is a powerline
                        {
                            adjacentToPowerline = true;// returns true

                        }
                    }
                
           
                if (region[i][j].population == 0 && adjacentToPowerline) { // checks the regions population and adjancency to  a powerline
                    region[i][j].population += 1;// increases the population of that specific location
                    workers -= 2;// decreases the workers
                    goods += 1;// adds the goods
                    return;
                }
                else if (region[i][j].population == 0) { // if population is 0
                    vector<loc> temp = isAdj(region, i, j); // creates a vector to store all the adjacent region
                    for (int s = 0; s < temp.size(); s++) // goes through the vector
                    {
                        if (temp[s].population >= 1)// checks the population of the adjacent region
                        {
                            adjacentWithPopulationOne += 1;// adds one to the counter 
                        }
                    }
                    if (adjacentWithPopulationOne >= 1) { // checks the no of adjanceny
                        region[i][j].population += 1;//adds population
                        workers -= 2;// decreases 2 workers
                        goods += 1; // adds goods
                        return;
                    }
                }
                else if (region[i][j].population == 1) {// if population is 1
                    vector<loc> temp = isAdj(region, i, j);// creates a vector to store all the adjacent region
                    for (int s = 0; s < temp.size(); s++)// goes through the vector
                    {
                        if (temp[s].population >= 1)// checks the population of the adjacent region
                        {
                            adjacentWithPopulationOne += 1;// adds one to the counter 
                        }
                    }
                    if (adjacentWithPopulationOne >= 2) {// checks the no of adjanceny
                        region[i][j].population += 1;//adds population
                        workers -= 2;// decreases 2 workers
                        goods += 1;// adds goods
                        return;
                    }
                }
                else if (region[i][j].population == 2) {
                    vector<loc> temp = isAdj(region, i, j);
                    for (int s = 0; s < temp.size(); s++)
                    {
                        if (temp[s].population >= 2)
                        {
                            adjacentWithPopulationOne += 1;
                        }
                    }
                    if (adjacentWithPopulationTwo >= 4) {
                        region[i][j].population += 1;
                        workers -= 2;
                        goods += 1;
                        return;
                    }
                }
            }
        }
    }
}