#pragma once
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "loc.h"
#include "residential.h"
using namespace std;

void createH(vector<vector<loc>>& region);
void simulateH(vector<vector<loc>>& region, int& goods);
int findGoods(vector <vector<loc>> region);
void treat(vector <vector<loc>>& region);
void distribute(vector <vector<loc>>& region, int inj);
bool check(vector <vector<loc>>& region);

#endif
