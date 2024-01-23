/*
    SHALLOW COPYING
#Default compiler copy method

* Having a class that contains a pointer as a data member
* Constructor allocates storage dynamically and initializes the pointer
* Destructor releases that memory allocated by constructor
? WHAT happens in the default copy constructor?
! When we release the storage in the destructor, the other object still refers to the released storage!

Copy obj used by function, goes out of scope, and calls destructor, as it was pointing to same place than obj1, now obj1 is pointing to
#invalid location

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

class Shallow
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    //#Constructor
    Shallow(int d);
    //#Copy constructor
    Shallow(const Shallow &source);
    //#Destructor
    ~Shallow();
};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}

//#COPY CONSTRUCTOR
Shallow::Shallow(const Shallow &source)
    : data(source.data)
{
    cout << "Copy constructor - shallow copy" << endl;
}

Shallow::~Shallow(){
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s){
    cout << s.get_data_value() << endl;
}

int main()
{
    Shallow obj1{100};
    display_shallow(obj1);  //! Loses the 100 value, because copy called destructor for that pointer

    Shallow obj2{obj1};
    obj2.set_data_value(1000);  //! Changes obj1 value to 1000, same pointer

    return 0;
}