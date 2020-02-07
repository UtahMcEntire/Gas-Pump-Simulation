// Proj2 BY Utah McEntire, CSCI 3110-001, Due: 09/17/19
// PROGRAM ID: proj2.cpp / Fill er Up
// AUTHOR: Utah McEntire
// INSTALLATION: MTSU
// REMARKS: This program simulates fuel demand for a number of vehicles u-
// sing a class.

#ifndef gaspump_H
#define gaspump_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstddef> //For NULL
using namespace std;

class gaspump{
public:

	//Constructor
	gaspump(string ft, double tc, double ppg);
	
	void getFuelType(){cout<<fuelType;};	
	double getPricePerGallon(){return pricePerGallon;};
	double getAvailableFuel(){return fuelAvailable;};
	double getTotalFuelDispensed(){return totalFuelDispensed;};
	double getTotalMoneyCollected(){return totalMoneyCollected;};
	void dispenseFuel(double *fuelOutArray, double purchaseAmount);

private:

	string fuelType;
	double fuelAvailable;
	double tankCapacity;
	double pricePerGallon;
	double totalFuelDispensed=0;
	double totalMoneyCollected=0;
	bool acceptNextCust;
	void replenish();
	
};

#endif