#pragma once
#ifndef TELLER_H_
#define TELLER_H_
#include "Customer.h"
/*-----------------------------------------------------------------------------------------------
Each teller created has 3 variables, a boolean that checks if they are free, a customer class, and their ID.
The teller takes in a customer and checks if they are finished with any tasks they want to initiate.
-----------------------------------------------------------------------------------------------*/
class Teller
{
private:
	bool available;
	Customer customer;

public:
	string tellerID;

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
			cout <<"Teller: " << tellerID << " is finished with " << customer.customerID << endl;
			available = true;
		}
		else { return available; }
	}

	void addCustomer(const Customer &c) {
		customer = c;
		cout << tellerID << " is taking care of " << c.customerID << " who wants " << c.numOfTasks << " task(s)" << endl;
		available = false;
	}
};
#endif