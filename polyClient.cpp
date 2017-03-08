//Adrian Borrego  10/07/16  Assignment #3: Polymorphic Bank
#include "polyAccount.h"
#include "polySavings.h"
#include "polyChecking.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <typeinfo>

using namespace std;

//Main program showing classes functionality.
int main(void)
{
	//Client withdraw/deposit amounts.
	double userWithdraw;
	double userDeposit;
	
	//Creation of 2 Savings, Checking accounts.
	SavingsAccount acc1(500, 0.05);
	SavingsAccount acc2(1000, 0.05);
	CheckingAccount acc3(500, 3.00);
	CheckingAccount acc4(1000, 3.00);
	
	cout << "\nSavings Account #1 balance: $" << acc1.getBalance();
	cout << "\nSavings Account #2 balance: $" << acc2.getBalance();
	cout << "\nChecking Account #1 balance: $" << acc3.getBalance();
	cout << "\nChecking Account #2 balance: $" << acc4.getBalance();
	cout << "\n\nAccounts processed polymorphically\n\n";
	
	//Vector pointer to accounts.
	vector < Account *> accounts(4);
	accounts[0] = &acc1;	
	accounts[1] = &acc2;
	accounts[2] = &acc3;
	accounts[3] = &acc4;
	
	//Processing each account polymorphically.
	for(size_t i = 0; i < accounts.size(); i++)
	{
		cout << "\nEnter an amount to withdraw from Account " << i + 1 << ": ";
		cin >> userWithdraw;
		accounts[i]->debit(userWithdraw);
		
		cout << "\nEnter an amount to deposit into Account " << i + 1 << ": ";
		cin >> userDeposit;
		accounts[i]->credit(userDeposit);
		//Dynamic_cast to detemine if type is SavingsAccount.
		SavingsAccount* savingsAccountPtr = dynamic_cast<SavingsAccount*>(accounts[i]);
		
		//If cast was successful interest will be calculated.
		if(savingsAccountPtr != nullptr)
		{
			double interestEarn = savingsAccountPtr->calculateInterest();
			cout << "Savings Account interest added.\n";
			savingsAccountPtr->credit(interestEarn);
		}
		
		cout << "Updated Account " << i + 1 << " balance: $" << accounts[i]->getBalance() << "\n\n";
	}
	
	return 0;
}
