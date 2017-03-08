//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#ifndef POLYACCOUNT_H
#define POLYACCOUNT_H

#include <iostream>
#include <stdexcept>

using namespace std;
//Account class.
class Account {
	public :
		Account(double);
		~Account(void);
		virtual void credit(double); //deposit.
		virtual bool debit(double); //withdraw.
		double getBalance();
	
	protected:
		double balance; //account balance.
};

#endif