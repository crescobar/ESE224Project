#pragma once
#ifndef TELLER_H_
#define TELLER_H_
#include "Customer.h"
class Teller
{
private:
	bool available;
	Customer customer;

public:
	string tellerID;
	Teller() : available(true) {}

	Teller(string name) : available(true) {
		tellerID = name;
	}
	~Teller() {}
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