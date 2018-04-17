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

transactions :: transactions (){

}

transactions :: transactions (string nameOfTrans, double amount){
this->nameOfTrans = nameOfTrans;
this->amount = amount;
}

double transactions :: getAmount(){
return amount;
}

void transactions :: toString(){
cout << nameOfTrans << "  $" << amount << endl;
}

 ostream& operator<<(ostream& os, const transactions& obj)
{
    os << obj.nameOfTrans << "  $" << obj.amount;
   return os;
}

