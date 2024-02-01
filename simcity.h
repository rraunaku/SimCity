#pragma once
#ifndef SIMCITY_H
#define SIMCITY_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "loc.h"
#include "residential.h"
#include "industrial.h"
#include "commercial.h"
#include "pollution.h"
#include "hospital.h"
using namespace std;

void readInput(string layout, vector<vector<loc> >& region);
void update(vector <vector<loc> >& region, int& workers, int& goods, bool& same);
void print(vector<vector<loc> > region);


#endif // !READCSV_H

