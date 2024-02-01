#pragma once
#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
#include <iostream>
#include "loc.h"
using namespace std;

vector<loc> isAdj(vector <vector<loc> > region, int i, int j);
bool findRegionType(char type, vector<vector<loc> > region, int x, int y);
void updateRes(vector<vector<loc> >&vect, int &workers);


#endif 
