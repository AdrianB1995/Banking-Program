//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#include <iostream>
#include <stdexcept>
#include "polyAccount.h"

using namespace std;

//Account class functions:

Account::Account(double initBalance) //Account class constructor.
{
	if(initBalance >= 0.0){
		balance = initBalance;
	}
	else{
		throw invalid_argument("Initial balance was invalid.\n");
		balance = 0.0;
	}
}
//Account class destructor.
Account::~Account(void){
	
}
//Withdraw function with return bool used for fee determination.
bool Account::debit(double amount){
	bool feeCharge;
	
	if(amount > balance){
		throw invalid_argument("Debit amount exceeded account balance.\n");
		feeCharge = false; //No fee will be charged.
	}
	else{
		balance = balance - amount;
		feeCharge = true; //Fee will be charged.
	}
	return feeCharge;
}
//Deposit function.
void Account::credit(double amount){
	if(amount < 0.0){
		throw invalid_argument("Credit amount invalid.\n"); 
	}
	else{
		balance = balance + amount;
	}
}
//Get balance function.
double Account::getBalance(){
	return balance;
}