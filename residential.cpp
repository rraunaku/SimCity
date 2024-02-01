#include "residential.h"
using namespace std;


vector<loc> isAdj(vector<vector<loc>> region, int i, int j) { // return all the adjancent location of the region of gib=ven coordinates
	vector<loc> temp;
	if (j + 1 < region.size() && i <region.size())
	{
		temp.push_back(region[i][j + 1]);
	}
	if (j - 1 >= 0 && i < region.size())
	{
		temp.push_back(region[i][j - 1]);
	}
	if (j - 1 >= 0 && i - 1 >= 0)
	{
		temp.push_back(region[i - 1][j - 1]);
	}
	if (i - 1 >= 0 && j < region[i].size())
	{
		temp.push_back(region[i - 1][j]);
	}
	if (i - 1 >= 0 && j + 1 < region[i].size())
	{
		temp.push_back(region[i - 1][j + 1]);
	}
	if (i + 1 < region.size() && j - 1 >= 0)
	{
		temp.push_back(region[i + 1][j - 1]);
	}
	if (i + 1 < region.size() && j < region[i].size())
	{
		temp.push_back(region[i + 1][j]);
	}
	if (i + 1 < region.size() && region[i].size())
	{
		temp.push_back(region[i + 1][j + 1]);
	}
	return temp;
}



bool findRegionType(char type, vector<vector<loc>> region, int x, int y) // checks if the adjacent list contains the given character and return a value
{
	bool dec = false; // sets the default value
	vector<loc> temp = isAdj(region, x, y); // creates a adjacent list
	for (int i = 0; i < temp.size(); i++)// goes through vector
	{
		
		if (type == temp[i].regionType)// checks if it cantains the given character
		{
			dec = true;
			break;
		}
	}
	return dec;
}



void updateRes(vector<vector<loc>> &region, int &workers)// updating the residential region
{
	for (int i = 0; i < region.size(); i++)// goes through every storeed location
	{
		for (int j = 0; j < region[i].size(); j++)
		{
			int pop = region[i][j].population; // sets the default population for the loop
			if (region[i][j].regionType == 'R')// runs if the location type is residential
			{

				if (pop == 0)
				{
					vector<loc> temp = isAdj(region, i, j);//creates a adjacency list
						bool decision = findRegionType('T', region, i, j); // if the specifc region is adjacent to the given character it return true
						if (decision == true)// if true
						{
							region[i][j].population += 1;// adds population
							workers = workers + 1;// adds avalable workers
							return;
						}
				
					

					int counter = 0;// counter to check the no of adjancent location
					for (int x = 0; x < temp.size(); x++)// goes through the vector
					{
						if (temp[x].population >= 1)// if the adjacent region has required population
						{
							counter++;// adds a value to the counter
							if (counter >= 1)// if the counter reaches the required condition
							{
								region[i][j].population += 1;
								workers = workers + 1;
								break;
							}
						}
					}
				}

				 else if (pop == 1)// counter to check the no of adjancent location
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)// goes through the vector
					{
						if (temp[x].population >= 1)// if the adjacent region has required population
						{
							counter++;	// adds a value to the counter
							if (counter >= 2) // if the counter reaches the required condition
							{
								region[i][j].population += 1;
								workers = workers + 1;
								break;
							}
						}
						
					}
				}

				else if (pop == 2)// counter to check the no of adjancent location
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)// goes through the vector
					{
						if (temp[x].population >= 2)// if the adjacent region has required population
						{
							counter++;// adds a value to the counter
							if (counter >= 4)// if the counter reaches the required condition
							{
								region[i][j].population += 1;
								workers = workers + 1;
								break;
							}
						}
						
					}
				}

				else if (pop == 3)
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 3)// if the adjacent region has required population
						{
							counter++;// adds a value to the counter
							if (counter >= 6)// if the counter reaches the required condition
							{
								region[i][j].population += 1;
								workers = workers + 1;
								break;
							}
						}
						
					}
				}

				else if (pop == 4)
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 4)// if the adjacent region has required population
						{
							counter++;// adds a value to the counter
							if (counter == 8)// if the counter reaches the required condition
							{
								region[i][j].population += 1;
								workers = workers + 1;
								break;
							}
						}
						
						}
					}
				}
			}
		}
	}









