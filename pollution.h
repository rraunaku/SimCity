#pragma once
#ifndef POLLUTION_H
#define POLLUTION_H
#include <iostream>
#include "loc.h"
#include "industrial.h"
using namespace std;

void pMapInitialize(vector<vector<loc>> region, vector<vector<loc>>& pMap);
void printPol(vector <vector<loc>> map);


#endif