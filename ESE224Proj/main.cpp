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

int main(){
    int n = 0, timeOpen = 0;
    string nameOfBank;
    cout << "Enter an amount of tellers for your bank" << endl;
    cin >> n;
    cout << "Enter how long itll be open (time steps)" << endl;
    cin >> timeOpen;
    cout << "Enter a name for your Bank" << endl;
    getline(cin, nameOfBank);

    Bank nameOfBank (n);


    return 0;
}
