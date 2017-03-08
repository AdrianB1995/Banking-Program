//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#include <iostream>
#include <stdexcept>
#include "polyChecking.h"

using namespace std;

///CheckingAccount class functions:

//CheckingAccount class constructor.
CheckingAccount::CheckingAccount(double initBalance, double initFee) : Account(initBalance){
	if(fee < 0.0){
		throw invalid_argument("Fee charged for transactions is invalid, no fee will be charged.\n");
	}
	else{
		fee = initFee;
	}
}
//CheckAccount class destructor.
CheckingAccount::~CheckingAccount(void){
	
}
//Redefined credit function with fee charge.
void CheckingAccount::credit(double amount){
	
	if(amount < 0.0){
		throw invalid_argument("Credit amount invalid.\n"); 
	}
	else{
		Account::credit(amount);
		balance = balance - fee;
	}	
}
//Redefined debit function with fee charge.
bool CheckingAccount::debit(double amount){
	bool tempFee;
	tempFee = Account::debit(amount);

	if(tempFee == true){
		balance = balance - fee;
	}
	if(tempFee == false){
		cout << "No fee was charged.\n";
	}
}
