#include "hospital.h"
#include <unistd.h>
using namespace std;

void createH(vector<vector<loc> > &region) // creates a hospital region
{
	for (int i = 0; i < region.size() ; i++)
	{
		for (int j = 0; j < region[i].size() - 1 ; j++) // transverse to the cells
		{
			if (region[i][j].regionType == ' ')// chooses a blank space to add the hospital region
			{
				if (findRegionType('R', region, i, j) )
				{
						region[i][j].regionType = 'H'; // sets the region type to H
						
				}
			}
		}
	}
}


void distribute(vector <vector<loc> >& region, int inj)// distributes the sick population to cells
{
	int temp = inj;
	do
	{
		for (int i = 0; i < region.size(); i++) // transverse to the cells
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'R')// if the region is of R regiontype
				{
					if (temp != 0)// if the sick population is not zero
					{
						if (region[i][j].sick == 0)// selects the one whose sick population is zero
						{
							region[i][j].sick += 1;// sets the value 
							--temp;
						}
						else// if the sick population is not zero
						{
							region[i][j].sick += 1;// increases by one
							--temp;
						}
					}

				}
			}
		}
	} while (temp > 0);// runs while the temp is not 0
}



void simulateH(vector<vector<loc> >& region, int& goods)// transfers the sick population to hospitals evenly
{
	int total_sick = 0;// sick people in residential area
	int inH = 0;// sick people in hospital
	int treated = 0;// treated patients;
	int death = 0; // dead people

	
		for (int i = 0; i < region.size(); i++) // gets the total amount of sick people
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'R')// selects the R region type
				{
					if (region[i][j].sick != 0)
					{
						total_sick += region[i][j].sick;
					}
				}
			}
		}
		
			
		
	

	do
	{
		for (int i = 0; i < region.size(); i++) // removes the sick population from the residential area and stores them in a variable
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'R')
				{
					if (region[i][j].sick != 0)
					{
						region[i][j].population -= 1;
						region[i][j].sick -= 1;
					}
				}
			}
		}

		for (int i = 0; i < region.size(); i++) // transferrs the sick populaition into the hospitals
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'H')
				{
					if (total_sick != 0)
					{
						if (region[i][j].population == 0)
						{
							region[i][j].population += 1;
							total_sick -= 1;
							inH += 1;
						}
						else
						{
							region[i][j].population += 1;
							inH += 1;
							total_sick -= 1;
						}
					}

				}
			}
		}
	} while (total_sick > 0);
}

int findGoods(vector<vector<loc> > region) // to find the number of goods available in the commercial area.
{
	int goods = 0;
	for (int i = 0; i < region.size(); i++) // putting the sick people in hospital
	{
		for (int j = 0; j < region[i].size(); j++)
		{
			if (region[i][j].regionType == 'C')
			{
				goods += region[i][j].population;
			}
		}
	}
	return goods;
}

void treat(vector<vector<loc> >& region)// treating the patients
{
	int count = 0;// varibales to keep track of the changes
	int medicalEquipment = 0;
	while (findGoods(region) >= 2)// checks if the required amount of goods are available
	{
		for (int i = 0; i < region.size(); i++) // finding the available goods to cure
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'C' && region[i][j].population % 2 == 0)
				{
					medicalEquipment += region[i][j].population / 2;
					region[i][j].population = 0;
				}
				else if (region[i][j].regionType == 'C' && region[i][j].population % 2 == 1)
				{
					medicalEquipment += region[i][j].population / 2;
					region[i][j].population = 1;
				}
			}
		}
	}
	count = medicalEquipment;
	
		for (int i = 0; i < region.size(); i++) //transferring the treated patients back to their respective residential cell
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'R')
				{
					
						region[i][j].population += 1;// increases the population of the specific region
						medicalEquipment -= 1;
				}
				if (medicalEquipment == 0)
				{
					break;
				}
			}
		}

	

		for (int i = 0; i < region.size(); i++) // transverses through the hospital region
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'H')
				{
					region[i][j].population -= 1;//increases the population of the specific region
					count -= 1;
				}
				if (count == 0)
				{
					break;// breaks when the all the patients are removed from the hospitals
				}
			}
		}
	
}

bool check(vector<vector<loc> >& region) // checking the previous region and current layout
{
	cout << "Waiting for goods";
	for (int i = 0; i < 5; i++)// displaying the message
	{
		cout << ".";
		sleep(250);
	}
	cout << endl;

	if (findGoods(region) < 2)// if the available goods are not available after the timestep
		{
		for (int i = 0; i < region.size(); i++) // transverses through the region
		{
			for (int j = 0; j < region[i].size(); j++)
			{
				if (region[i][j].regionType == 'H')
				{
					region[i][j].population = 0;// decreasing the hospital population to zero
				}
			}
		}
			
			return false;
		}
	else
	{
		treat(region);
		return true;
	}
	
}


