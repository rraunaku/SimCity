#include "simcity.h"
#include <vector>
#include <iostream>
using namespace std;

void readInput(string layout, vector<vector<loc> > &region) //function to read the layout
{
	ifstream csv(layout);// opens the read file
	
	int x = 0;
	char chr;// initializing the variable
	csv >> noskipws; // reads whitespaces
    while (csv >> chr) { // runs until it takes input
        vector<loc> y; // initializing the vector to store row
        region.push_back(y); // adds the row to the main vector
        while (chr != '\n') { // only stores input that is not null or a comma
            if (chr != ',') {
                loc temp;// creates a struct variable to store the region type
                temp.regionType = chr;
                region[x].push_back(temp);// adds the that specific data to the respective region
            }
            csv >> chr;// reads again
        }
        x++;
    }

    // print initial state
    cout << "Initial State" << endl;
	print(region);// prints the initial state
}



void print(vector<vector<loc> > region) // printing the region
{
    int pop = 0;
	for (int i = 0; i < region.size(); i++)// loop to acces every variable 
	{
		for (int j = 0; j < region.at(i).size(); j++)
		{
			if (region[i][j].regionType == ' ')
			{
				cout << ' ' << ' ';
			}
			else if (region[i][j].regionType == '-')
			{
				cout << '-' << ' ';
			}
			else if (region[i][j].regionType == '#')
			{
				cout << '#' << ' ';
			}
			else
			{
				if (region[i][j].population == 0)// checks if the region is populated
				{
					cout << region[i][j].regionType << " ";

				}
				else
				{
					if (region[i][j].sick == 0)
					{
						cout << region[i][j].population << " ";
					}
					else
					{
						cout << region[i][j].population << "(" << region[i][j].sick << ") ";
					}
				}
			}


		}
		cout << endl;
	}
}
bool change(vector <vector<loc> > region, vector<vector<loc> > initial) // checks the difference between the previous and current region
{
	for (int i = 0; i < region.size(); i++) {
		for (int j = 0; j < region[i].size(); j++) {
			if (region[i][j].population != initial[i][j].population ||
				region[i][j].regionType != initial[i][j].regionType) {
				return true;
			}
		}
	}

	return false;
}

void update(vector<vector<loc> > &region, int &workers, int&goods, bool &same) // updating the region
{
	vector <vector<loc> > initial = region;
	updateRes(region, workers);
	updateIndustrial(region, workers, goods);
	updateCommercial(region, workers, goods);
	
	
	same = !(change(region, initial)); // returns the value for if the region is same or not.
}



