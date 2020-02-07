// Proj2 BY Utah McEntire, CSCI 3110-001, Due: 09/17/19
// PROGRAM ID: proj2.cpp / Fill er Up
// AUTHOR: Utah McEntire
// INSTALLATION: MTSU
// REMARKS: This program simulates fuel demand for a number of vehicles u-
// sing a class.

#include "gaspump.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstddef> //For NULL
using namespace std;

//Default constructor
gaspump::gaspump(string ft, double tc, double ppg){
	fuelType=ft;
	tankCapacity=tc;
	pricePerGallon=ppg;
	fuelAvailable=tc;
}

void gaspump::replenish(){
	fuelAvailable=tankCapacity;
	acceptNextCust=true;
}

void gaspump::dispenseFuel(double *fuelOutArray, double purchaseAmount){
	fuelOutArray[0]=purchaseAmount;
	if (fuelAvailable<tankCapacity/10){ //If gaspump is less than 10% full, turn cust away and refill
		acceptNextCust=false;
		purchaseAmount=0.00;
		fuelOutArray[1]=purchaseAmount;
		replenish();
	}
	else if (fuelAvailable*pricePerGallon<purchaseAmount){ //If greater than 10% but not enough for full purchase
		acceptNextCust=false;
		purchaseAmount=fuelAvailable*pricePerGallon;
		fuelOutArray[1]=purchaseAmount;
		fuelAvailable=0.00;
	}
	else { // 100% of desired fuel available, give cust full requested purchase
		acceptNextCust=true;
		fuelOutArray[1]=purchaseAmount;
		fuelAvailable-=purchaseAmount/pricePerGallon;
	}
	totalFuelDispensed+=purchaseAmount/pricePerGallon; // Adds purchased amounts to total amounts
	totalMoneyCollected+=purchaseAmount;
}