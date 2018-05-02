/*
The goal of this project is to design and develop C++ code and algorithms to simulate a queue
in a bank, serviced by several tellers. A second goal is to effectively employ object-oriented 
design techniques, through appropriate use of classes, data structures and STANDARD TEMPLATE 
LIBRARIES (STLs).
*/

//Erik Bracamonte
//Cristian Escobar
#define _crt_secure_no_warnings
#include "Teller.h"
#include "Customer.h"
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

int createTransactions(vector<string> &transactions);
void creatingTellers(int numOfTellers, vector<Teller> &tellers);
void creatingCustomers(deque<Customer> &people, int numOfPeople, vector<string> &transactions);

int main() {
	
	int numOfTellers = 4;
	int tStop = 15;

	int customersArriving;
	//2 is the max amount of people that can arrive at the bank at each time step.	
	int numOfPeople = (tStop * 2);
	
	vector<Teller> tellers;
	vector<string> transactions;
	deque<Customer> people;	//Used to edit both front and ends of a vector.
	deque<Customer> line; 
	
	//Creating our Tellers and Customers using loops. Each unique in name, account info, etc.
	createTransactions(transactions);
	creatingTellers(numOfTellers, tellers);
	creatingCustomers(people, numOfPeople, transactions);

	for (int t = 1; t <= tStop; t++) {
		cout << "-------------------------------------\nTstep = " << t << endl;
		cout << "Input number of customers arriving (max 2): ";
		cin >> customersArriving;
		(customersArriving > 2 || customersArriving < 0) ? customersArriving = 2 : customersArriving;	//Make sure any input number greater then 2 or
		cout << customersArriving << " customer(s) arrived. (";											//less than 2 is being forced as 2 instead.

		//Output names of each customer arriving.
		for (int i = 0; i < customersArriving; i++) {	
			people[i].getCustomerName();
			if (i < (customersArriving - 1)) {
				cout << ", ";
			}
		}
		cout << ")\n-------------------------------------" << endl;

		//Put number of customers arriving in a queue.
		for(int i = 0; i < customersArriving; i++){
			line.push_back(people.front());
			people.pop_front();
		}
		//Check each teller if they are available and assign them to a customer that's on front of the line.
		for (int i = 0; i < numOfTellers; i++) {
			if (tellers[i].isFree() && !line.empty()) {
				tellers[i].addCustomer(line.front());
				line.pop_front();
			}
		}

		//Output names of remaining customers whose waiting currently.
		cout << line.size() << " customer(s) are on line. (";
		for (int i = 0; i < line.size(); i++) {
			line[i].getCustomerName();
			if (i < (line.size() - 1)) {
				cout << ", ";
			}
		}
		cout <<")" << endl;
	}
	system("pause");
	return 0;
}

/*--------------------------------------------------------------------------
Reading from a file, we store each line of the file into a string and store 
that string into a vector called "transactions". This transactions vector is to be used 
for each customer created. The Customer class has a method that takes in a vector and chooses 
a position at random and copy its content to the customers personal list.
--------------------------------------------------------------------------*/
int createTransactions(vector<string> &transactions) {
	string list;
	ifstream file("transactions.txt");
	if (!file) {
		cout << "File unable to open.\n";
		return 0;
	}

	while (getline(file, list)) {
		transactions.push_back(list);
	}
	return 1;
}
/*--------------------------------------------------------------------------
This creates each unique customer with their own ID, bank account number, and their personal balance..
--------------------------------------------------------------------------*/
void creatingCustomers(deque<Customer> &people, int numOfPeople, vector<string> &transactions) {
	for (int i = 1; i <= numOfPeople; i++) {
		string personID = "C" + to_string(i);
		people.push_back(Customer(personID, (111230826 + i), (rand() % 2000 + 300)));
	}
	//Store transactions from a vector that was made by reading from a file and storing it into each customers
	//personal transactions list.
	for (int j = 0; j < people.size(); j++) {
		people[j].addTransactions(transactions);
	}
}

/*--------------------------------------------------------------------------
This creates each unique teller with their own ID, and each initially available to take a customer.
--------------------------------------------------------------------------*/
void creatingTellers(int numOfTellers, vector<Teller> &tellers) {
	for (int i = 1; i <= numOfTellers; i++) {
		string tellerID = "T" + to_string(i);
		tellers.push_back(Teller(tellerID));
	}
}

