#pragma once
#ifndef LOC_H
#define LOC_H
#include <iostream>
#include <vector>
using namespace std;
struct loc // a struct that includes all the variables encompassed by a location.
{
	char regionType;
	int population = 0 ;
	int pollution= 0;
	int sick = 0;
	int happiness = 0;
};

#endif