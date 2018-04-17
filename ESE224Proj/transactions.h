#ifndef TRANSACTIONS_H_INCLUDED
#define TRANSACTIONS_H_INCLUDED

using namespace std;

class transactions{

string nameOfTrans;
double amount;



public : transactions ();

public: transactions (string nameOfTrans, double amount);

double getAmount();

public: void toString();

public : friend ostream& operator<<(ostream& os, const transactions& obj);




};



#endif // TRANSACTIONS_H_INCLUDED
