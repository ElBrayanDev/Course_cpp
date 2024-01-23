/*
    DEEP COPYING

* Creates a copy of the pointer
* Each copy will have a unique storage through its pointer
! DEEP copy when you have raw C++ pointers as class data member

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Deep
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    //#Constructor 
    Deep(int d);
    //#Copy constructor
    Deep(const Deep &source);
    //#Destructor
    ~Deep();
};

Deep::Deep(int d)
{
    data = new int;
    *data = d;
}

//#COPY CONSTRUCTOR - !IMPORTANT
Deep::Deep(const Deep &source)
    : Deep{*source.data} //# Delegating constructor Deep (int), and pass a *source.data
{
    cout << "Copy constructor - Deep copy" << endl;
}

Deep::~Deep()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_Deep(Deep s)
{
    cout << s.get_data_value() << endl;
}

int main()
{
    Deep obj1{100};
    display_Deep(obj1); //! Loses the 100 value, because copy called destructor for that pointer

    Deep obj2{obj1};
    obj2.set_data_value(1000); //! Changes obj1 value to 1000, same pointer

    return 0;
}