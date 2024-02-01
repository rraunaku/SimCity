#include "commercial.h"
using namespace std;



void updateCommercial(vector<vector<loc>>& region, int& workers, int& goods) {

    for (int i = 0; i < region.size(); i++) { // goes through all the location in the region
        for (int y = 0; y < region[i].size(); y++) {

            if (workers == 0 || goods == 0) // if this condition is true then goes to the next iteration
            {
                continue;
            }
            if (region[i][y].regionType != 'C')
            {
                continue;
            }

                int lines = 0;// conter to check the no of adjacency to a powerline
                int pop = 0;// counter to check the adjacency to the required number of people


                vector<loc> temp = isAdj(region, i, y);// creates a vector and stores the adjacent region
                for (int s = 0; s < temp.size(); s++)// goea through the vector
                {
                    if (temp[s].regionType == 'T' || temp[s].regionType == '#')// checks the adjacency of a given character
                    {
                        lines += 1;//adds to the counter
                    }
                    if (temp[s].population > 0)// checks the popualtion
                    {
                        pop += 1;
                    }
                }

                if (region[i][y].population == 0) {
                    if (lines >= 1 || pop >= 1) {
                        workers -= 1;
                        goods -= 1;
                        region[i][y].population += 1;
                        return;
                    }
                }
                else if (region[i][y].population == 1) {
                    if (pop >= 2) {
                        workers -= 1;
                        goods -= 1;
                        region[i][y].population += 1;
                        return;
                    }
                }
            }
        }
    }

