#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED


using namespace std;
class Customer{
public :
int idNum;
int accountNum;
double accountBal;
vector<transactions> list;

public : Customer();

public : Customer(int idNum, int accountNum);

public : Customer(int idNum, int accountNum, double accountBal);

public : void setBalance(double money);

public  : double getBalance();

public : void depositCash(double money);

public : void withdrawCash(double money);

public : void printTransactions();

public : void addTransactions(transactions obj1);

public : friend ostream& operator<<(ostream& os, const Customer& obj);

};




#endif // CUSTOMER_H_INCLUDED
