// Proj2 BY Utah McEntire, CSCI 3110-001, Due: 09/17/19
// PROGRAM ID: proj2.cpp / Fill er Up
// AUTHOR: Utah McEntire
// INSTALLATION: MTSU
// REMARKS: This program simulates fuel demand for a number of vehicles u-
// sing a class.
// Started via Skeleton++

#include "gaspump.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;


int main(){
	int seed, numOfVehicles, pumpindex=0;
	double tankCapacity, pricePerGallon, purchaseAmount, percentage, percentage1, percentage2, percentage3, typenum;
	double *fuelOutArray = new double[2]; // creates 2 item fuel output array
	gaspump *gasStation[3]; // creates 3 item fuel type array
	string fuelType;
	
	ifstream myIn;
	myIn.open("gas.txt"); //input filename
	assert(myIn);
	
	myIn>>seed;
	srand(seed); //random number seeding
	myIn>>numOfVehicles;
	while (myIn>>fuelType>>tankCapacity>>pricePerGallon>>percentage){
		gasStation[pumpindex] = new gaspump(fuelType, tankCapacity, pricePerGallon); //constructor initializes pump object
		if(pumpindex==0){ //Sets percentage ranges
			percentage1=percentage;
		}
		else if(pumpindex==1){
			percentage2=percentage;
		}
		else if (pumpindex==2){
			percentage3=percentage;
		}
		pumpindex++;
	}

	for (int i=1; i<=numOfVehicles; i++){ //fuel pump selection
		typenum=(((double) rand() + 1) / RAND_MAX);
		if (typenum>1-percentage1){
			pumpindex=0;
		}
		else if (typenum<percentage3){
			pumpindex=2;
		}
		else{
			pumpindex=1;
		}
		purchaseAmount=((((int) rand() % 6))* 5 + 30); //Fuel purchase amount selection
		gasStation[pumpindex]->dispenseFuel(fuelOutArray, purchaseAmount);
		
		cout<<i<<" ";
		gasStation[pumpindex]->getFuelType(); 						//Car number and fuel type
		cout<<fixed<<setprecision(2)<<" "<<gasStation[pumpindex]->getPricePerGallon()<<" "  //price per gallon
			<<fuelOutArray[0]<<" " 									//requested purchase amount
			<<fuelOutArray[1]<<" " 									//actual purchase amt
			<<fuelOutArray[1]/gasStation[pumpindex]->getPricePerGallon()<<" " //Gallons purchased
			<<gasStation[pumpindex]->getAvailableFuel()<<endl;		//Fuel available
	}
	
	for(int i=0; i<3; i++){ //final totals output
		gasStation[i]->getFuelType();
		cout<<" "<<gasStation[i]->getTotalFuelDispensed()<<" "<<gasStation[i]->getTotalMoneyCollected()<<endl;
	}
	
	for(int i=0; i<3; i++){
		delete gasStation[i];
		gasStation[i]=NULL;
	}
	delete [] fuelOutArray;
	
	myIn.close(); //close the opened files
	return 0;
}
