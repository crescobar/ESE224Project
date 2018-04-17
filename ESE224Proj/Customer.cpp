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

Customer :: Customer(){

idNum = 110990116;
accountNum = 123456789;
accountBal = 0;
vector <transactions> list;

}

Customer :: Customer(int idNum, int accountNum){
this->idNum = idNum;
this->accountNum = accountNum;
}


Customer :: Customer(int idNum, int accountNum, double accountBal){
this->idNum = idNum;
this->accountNum = accountNum;
this->accountBal = accountBal;

}


    void Customer :: setBalance(double money){
        accountBal = money;

}

    double Customer :: getBalance(){

    return accountBal;
    }


    void Customer :: depositCash(double money){
    accountBal = accountBal + money;

}

    void Customer :: withdrawCash(double money){
    accountBal = accountBal - money;
    }

    void Customer :: printTransactions(){
    for(int x = 0; x < list.size(); x++){
        list[x].toString();
        printf("\n");

    }

    }

    void Customer :: addTransactions(transactions obj1){
        list.push_back(obj1);
        accountBal = accountBal + obj1.getAmount();
    }

   ostream& operator<<(ostream& os, const Customer& obj)
{
    os << "ID number: " << obj.idNum << " Account number: " << obj.accountNum << " Balance :$" << obj.accountBal;
   return os;
}


