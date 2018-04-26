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
/*
Each arriving customer has an ID, account number, account balance and a list of recent
transactions, as its data members. It also has the amount of tasks it will want to be complete
to be able to tell the teller.
*/
class Customer {
private:
	friend class Teller; //Teller class can now access the private variables without methods
	vector<string> eventType;
	int numOfTasks;
	string customerID;
	int accountNumber;
	int accountBalance;
	vector<string> transactions;

public:
	//The reason why theres a colon after constructor is its initialising 
	//member variables before the body of the constructor executes.
	//When creating a customer we need to give them a 
	//accountBalance number, an ID, account number, and
	//list of transactions made before they talk to the teller.
	Customer(){}

	Customer(string id, int accountNum, int balance) 
	  :	numOfTasks(1 + (rand() % 3)), 
		transactions(rand() % 7 + 2),
		eventType({ "deposit", "withdraw", "printList" }) {
		customerID = id;
		accountNumber = accountNum;
		accountBalance = balance;
	}

	void withdraw(double value) {
		if (value > accountBalance) {
			cout << customerID << " could not take out " << value << " from his account as it's higher then his account balance." << endl;
		}
		else {
			accountBalance = accountBalance - value;
			cout << customerID << " withdrew $" << value << " from his account." << endl;
		}
	}

	void deposit(int value) {
		accountBalance += value;
		cout << customerID << " deposited $" << value << " to his account." << endl;
	}

	void printList() {
		cout << customerID << " asked for his transaction history." << endl;
		for (int i = 0; i < transactions.size(); i++) {
			cout << transactions[i] << " " << endl;
		}
	}

	//Whatever is given in that list, the method will choose at random what goes inside this customers
	//own transaction list. 
	void addTransactions(vector<string> &list) {
		int size = transactions.size();
		for (int i = 0; i < size; i++) {
			transactions[i] = ( list[ rand() % list.size() ]);
		}
	}

	//Where we handle each possible event that will occur. 
	bool done() {
		int n = eventType.size();
		int choose = rand() % n;
		if (eventType[choose] == "deposit") {
			eventType.erase(eventType.begin() + choose);
			deposit(rand() % accountBalance);
		}
		else if(eventType[choose] == "withdraw") {
			eventType.erase(eventType.begin() + choose);
			withdraw(rand() % accountBalance);
		}
		else if (eventType[choose] == "printList") {
			eventType.erase(eventType.begin() + choose);
			printList();
		}
		return --numOfTasks < 0;
	}

};
#endif