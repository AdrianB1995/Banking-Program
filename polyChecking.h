//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#ifndef POLYCHECKING_H
#define POLYCHECKING_H

#include <iostream>
#include <stdexcept>
#include "polyAccount.h"

using namespace std;

//Checking Account class.
class CheckingAccount : public Account{
	public :
		CheckingAccount(double, double);
		~CheckingAccount(void);
		virtual void credit(double); //deposit.
		virtual bool debit(double); //withdraw.
		
	private :	
		double fee; //fee charged per transaction.
};

#endif
