//********************************************************************
//CPSC 230 TR Fall 2021             Chapter 4
// Slides Not Covered
//Twymun Safford
//Function to Calculate balance
//*****************************************************************

//Determines which of the two pziza sizes is the best byu

//headers and libraries
//Determines which of two pizza sizes is the best buy.
#include <iostream>
using namespace std;
//Returns factorial of n.
//The argument n should be nonnegative.
//Function Definition
double new_balance(double balance_par, double rate_par)
{
	double interest_fraction, interest;
	interest_fraction = rate_par / 100;
	interest = interest_fraction * balance_par;
	return (balance_par + interest);
}

int main()
{
	int balance, interest;
	cout << "I can calculate your new account balance based on the current balance and" << endl;
	cout << "\ninterest rate. Please enter your current balance: " << endl;
	cin >> balance;
	cout << "\nNow, please enter the interest rate." << endl;
	//interest rate
	cin >> interest;
	//factorial fnction
	cout << "For a bank account with a starting value of $ "
		<< balance << " and an interest rate of " << interest
		<< " , your new balance will be $ " << new_balance(balance, interest) << endl; 
	return 0;
}