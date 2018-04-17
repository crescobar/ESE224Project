#ifndef TELLER_H_INCLUDED
#define TELLER_H_INCLUDED

class Teller {
public :
    bool state = true;

public : Teller();

public : Teller(bool state);

public : bool isBusy();

public : void setState ();

public : friend ostream& operator<<(ostream& os, const Teller& obj);

};

#endif // TELLER_H_INCLUDED
