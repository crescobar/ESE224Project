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
#include <iomanip>
#include <fstream>
using namespace std;

int createTransactions(vector<string> &transactions);
void creatingTellers(int numOfTellers, vector<Teller> &tellers);
void creatingCustomers(deque<Customer> &people, int numOfPeople, vector<string> &transactions);

int main() {
	int numOfTellers = 2;
	int tStop = 7;			//User input maybe?
	int customersArriving;
	//2 is the max amount of people that can arrive at the bank at each time step.	
	int numOfPeople = (tStop * 2);	
	
	vector<Teller> tellers;
	vector<string> transactions;
	deque<Customer> people;	//Used to edit both front and ends of a vector.
	queue<Customer> line; //Used to help take whats pushed in, and take out in order
	
	//Creating our Tellers and Customers using loops. Each unique in name, account info, etc.
	createTransactions(transactions);
	creatingTellers(numOfTellers, tellers);
	creatingCustomers(people, numOfPeople, transactions);

	for (int t = 1; t <= tStop; t++) {
		cout << "-------------------------------------\nTstep = " << t << endl;
		cout << "Input number of customers arriving (max 2): ";
		cin >> customersArriving;
		(customersArriving > 2) ? customersArriving = 2 : customersArriving;
		cout << customersArriving << " customer(s) arrived.\n" 
			<< "-------------------------------------" << endl;

		for(int i = 0; i < customersArriving; i++){
			line.push(people.front());
			people.pop_front();
		}
		for (int i = 0; i < numOfTellers; i++) {
			if (tellers[i].isFree() && !line.empty()) {
				tellers[i].addCustomer(line.front());
				line.pop();
			}
		}
		cout << line.size() << " customer(s) are on line.\n" << endl;
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
		people.push_back(Customer(personID, (111230823 + i), (rand() % 2000 + 300)));
	}
	//Simplify this and apply this to the code above
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
