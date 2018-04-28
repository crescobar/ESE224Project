#pragma once
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*----------------------------------------------------------------
Each arriving customer has an ID, account number, account balance and a list of recent
transactions, as its data members. It also has the amount of tasks it will want to be complete
to be able to tell the teller.
----------------------------------------------------------------*/
class Customer {
private:
	friend class Teller;	//Teller class can now access customer class private variables without methods
	vector<string> eventType;
	int numOfTasks;
	string customerID;
	int accountNumber;
	int accountBalance;
	vector<string> transactions;

public:
	//The reason why theres a colon after constructor is its initialising 
	//member variables before the body of the constructor executes.
	Customer(){}

	Customer(string id, int accountNum, int balance) 
	  :	numOfTasks(1 + (rand() % 3)), 
		transactions(rand() % 7 + 2),
		eventType({"deposit", "withdraw", "printList" }) {
		customerID = id;
		accountNumber = accountNum;
		accountBalance = balance;
	}

	~Customer() {}

	//Methods
	void getCustomerName() {
		cout << customerID;
	}

	void withdraw(double value) {
		if (value > accountBalance) {
			cout << customerID << " could not take out " << value << " from his account as it's higher then his account balance." << endl;
			cout << endl;
		}
		else {
			accountBalance = accountBalance - value;
			cout << customerID << " withdrew $" << value << " from his account." << endl;
			cout << endl;
		}
	}

	void deposit(int value) {
		accountBalance += value;
		cout << customerID << " deposited $" << value << " to his account." << endl;
		cout << endl;
	}

	void printList() {
		cout << customerID << " asked for his transaction history." << endl;
		for (int i = 0; i < transactions.size(); i++) {
			cout << transactions[i] << " " << endl;
		}
		cout << endl;
	}

	//Whatever is given in input list, the method will choose at random what goes inside this customers
	//own transaction list. 
	void addTransactions(vector<string> &list) {
		int size = transactions.size();
		for (int i = 0; i < size; i++) {
			transactions[i] = ( list[ rand() % list.size() ]);
		}
	}

	//Each customer will choose at random what task they want to initiate 
	//until their number of tasks is equal to 0.

	bool done() {

		int n = eventType.size(); 
		int choose = rand() % n;
		string choice = eventType[choose];

		if (choice == "deposit") {
			eventType.erase(eventType.begin() + choose);
			deposit(rand() % accountBalance);
		}
		if(choice == "withdraw") {
			eventType.erase(eventType.begin() + choose);
			withdraw(rand() % accountBalance);
		}
		if (choice == "printList") {
			eventType.erase(eventType.begin() + choose);
			printList();
		}
		return --numOfTasks == 0;
	}

};
#endif