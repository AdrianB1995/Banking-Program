//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#ifndef POLYSAVINGS_H
#define POLYSAVINGS_H

#include <iostream>
#include <stdexcept>
#include "polyAccount.h"

using namespace std;

//Savings Account class.
class SavingsAccount : public Account{
	public : 
		SavingsAccount(double, double);
		~SavingsAccount(void);
		double calculateInterest(void); //calculate interest earned.
	
	private:
		double interestRate;
};

#endif