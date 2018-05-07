#pragma once
#ifndef TELLER_H_
#define TELLER_H_
#include "Customer.h"
//Erik Bracamonte
//Cristian Escobar

/*-----------------------------------------------------------------------------------------------
Each teller created has 3 variables, a boolean that checks if they are free, a customer class, and their ID.
The teller takes in a customer and checks if they are finished with any tasks they want to initiate.
-----------------------------------------------------------------------------------------------*/
class Teller
{
private:
	bool available;
	Customer customer;
	string tellerID;
public:
	Teller() : available(true) {}

	Teller(string name) 
	  : available(true) {
		tellerID = name;
	}
	~Teller() {}

	//Methods
	bool isFree() {
		if (available) {
			cout << "Teller: " << tellerID << " is free." << endl;
			return true;
		}
		else if (customer.done()) {
			cout <<"Teller: " << tellerID << " is finished with " << customer.customerID << " and is now free." << endl;
			available = true;
		}
		else { return available; }
	}

	void addCustomer(Customer &c) {
		customer = c;
		cout << tellerID << " is taking care of " << c.customerID << " (Account #: " << c.accountNumber << ", Balance: $" << c.accountBalance << ") who wants " << c.numOfTasks << " task(s).\n" << endl;
		available = false;
	}
};
#endif