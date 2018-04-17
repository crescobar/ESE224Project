#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

using namespace std;

class Bank{
public :
    int numOfTell;
    vector<int> numOfSteps;
    vector<Customer> queueList;

public : Bank();

public : void amountOfTellers(int amount);
public : void addCustomerToQ(Customer obj);














};


#endif // BANK_H_INCLUDED
