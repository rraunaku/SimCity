#include "pollution.h"
using namespace std;

void pMapInitialize(vector<vector<loc>> &map)
{
	int totPol = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j].regionType == 'I')
			{
				if (map[i][j].population != 0)
				{
					vector<loc> temp = isAdj(map, i, j);
					
					for(int s = 0; s < temp.size(); s++)
					{
						temp[s].pollution += map[i][j].population;
						totPol += 1;
					}
				}
			}
		}
	}
}
void printPol(vector <vector<loc>> map)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); i++)
		{
			if (map[i][j].pollution == 0)
			{
				if (map[i][j].population == 0)
				{
					cout << map[i][j].regionType << " ";
				}
				else
				{
					cout << map[i][j].population << " ";
				}
			}
			else
			{
				cout << map[i][j].pollution << " ";
			}
		}
		cout << endl;
	}
}