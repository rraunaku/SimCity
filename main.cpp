#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "simcity.h"
#include "residential.h"
#include "industrial.h"
#include "chernobyl.h"
#include "hospital.h"
#include "hero.h"
using namespace std;

int main()
{
	vector<vector<loc> > region;
	string regionLayout;// initializing the variable to store region file
	string tline;// temp file to slice the string and store the necessary data
	int timeLimit = 0;// initializing the variable to store the time limit
	int refreshRate = 0;// initializing the variable 
	int workers = 0;
	int goods = 0;
	int pollution = 0;
	int happiness = 0;
	ifstream config("config1.txt"); // opening the config file

	if (!config.is_open())// checks if the file opens
	{
		cout << "File couldn't open!" << endl;
		exit(EXIT_FAILURE);// exits file if the file doesnt open
	}

	while (getline(config, tline))// loops while the stream can read an inout
	{
		size_t pos = tline.find("Region Layout:");// stores the position of the necessary data
		regionLayout = tline.substr(pos + 14); //slices the data
		//cout << regionLayout << "\n";
		break;
	}
	while (getline(config, tline))
	{
		size_t pos = tline.find("Time Limit:");// stores the position of the necessary data
		timeLimit = stoi(tline.substr(pos + 11));//slices the data
		//cout << timeLimit << "\n";
		break;
	}
	while (getline(config, tline))
	{
		size_t pos = tline.find("Refresh Rate:");// stores the position of the necessary data
		refreshRate = stoi(tline.substr(pos + 13));//slices the data
		//cout << refreshRate << "\n";
		break;
	}
	config.close();
	readInput(regionLayout, region); // reads the input from the region csv file

	bool same = false; // boolean value to indicate if the region is same for thr two time step
	int i;
	for (i = 1; i < timeLimit; i++) {

		update(region, workers, goods, same); // update the region file
		cout << "STATE: " << i << endl;
		print(region);// prints the current time step
		cout << "Available Workers: " << workers << endl;// displays available workers
		cout << "Available Goods: " << goods << endl << endl;// displays available goods
		

		if (same == true) // runs if the region is the same for two loops
		{
			cout << "No change." << endl;
			break;
		}
	}

	cout << "Final State:" << endl;
	print(region);// prints out the final layout
	cout << endl;

	int inj = 0;
	game(region, inj);

	// Project 2y
	char proceed;// variable to get the decision from the user
	cout << "Want to proceed to the second part of the simulation? (Y/N): ";
	cin >> proceed; // taking the input
	proceed = toupper(proceed); // sets the decision character to upper case
	if (proceed == 'N')// if the decision in no then it exits the program
	{
		exit(0);
	}
	else
	{
		distribute(region, inj);// distributes the sick population to cells
		createH(region);// creates a hospital region
		print(region);// prints the layout
		cout << endl;
		if (inj != 0)// if the sick population is 0 
		{
			cout << "Transferring the sick population to the hospital." << endl;
			simulateH(region, goods);// transfers the population to hospitals
			print(region);
			cout << endl;
			cout << "Treating the patients with the available goods." << endl;
			treat(region);// treats the sick population and sends them back to their respective residential cells
			print(region);

			cout << endl;


			bool app = false;
			for (int i = 0; i < 2; i++)// checks available goods for 2 time step
			{
				treat(region);
				app = check(region);
				if (!app)
				{
					cout << "Not enough medical equipment!" << endl;

				}
				else
				{
					cout << "Treatment approved!" << endl;
				}

			}
			cout << endl;
			cout << "Death occurred!!!!!!!" << endl;
			print(region);
		}
	}
	




	
	return 0;
}
