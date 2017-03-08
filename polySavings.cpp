//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#include <iostream>
#include <stdexcept>
#include "polySavings.h"

using namespace std;

//SavingsAccount class functions:

//SavingsAccount class constructor.
SavingsAccount::SavingsAccount(double initBalance, double initInterest) : Account(initBalance) {
	interestRate = initInterest;
}

//SavingsAccount class destructor.
SavingsAccount::~SavingsAccount(void){
	
}
//Calculate interet earned (balance * interestRate).
double SavingsAccount::calculateInterest(void){
	double tempInterest = 0.0;
	tempInterest = balance * interestRate;
	return tempInterest;
}