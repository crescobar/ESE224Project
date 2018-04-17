#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iterator>
#include <stdio.h>
#include "transactions.h"
#include "Customer.h"
#include "Teller.h"
#include "Bank.h"

using namespace std;
    //int numOfTell;
    //vector<int> numOfSteps;
    //vector<Customer> queueList;
	//testing git

Bank :: Bank (){

}

void Bank :: amountOfTellers(int amount){

numOfTell = amount;

}

void Bank :: addCustomerToQ(Customer obj){
    queueList.push_back(obj);
}

