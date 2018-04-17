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

Teller :: Teller(){
}

Teller :: Teller( bool myState){
state = myState;
}

bool Teller :: isBusy(){
return state;
}

ostream& operator<<(ostream& os, const Teller& obj)
{
    if(obj.state == true){
        os << "Free";
        return os;
    }
    else {
       os <<  "Busy";
          return os;
    }
}
