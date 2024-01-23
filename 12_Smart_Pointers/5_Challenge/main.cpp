/********************************************************************************************************
# CHALLENGE

Create a program that has the following:

1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects.

2. a function named fill that expects a vector of shared pointers to Test objects and a int
   representing the number of Test objects to create dynamically and add to the vector.

   This function will prompt the user to enter an integer, create a shared_ptr to a Test object
   initialized to the entered integer and add that shared pointer to the vector.

3. a function named display that expects a vector of shared_ptrs to Test object and displays the
   data in each Test object

# Below is a sample run for the user entering 3 at the console:

How many data points do you want to enter: 3
Enter data point [1] : 10
        Test constructor (10)
Enter data point [2] : 20
        Test constructor (20)
Enter data point [3] : 30
        Test constructor (30)
Displaying vector data
=======================
10
20
30
=======================
        Test destructor (10)
        Test destructor (20)
        Test destructor (30)

I am providing the function prototypes in the code.
However, feel free to modify these as you wish.
Have fun and experiment!
*****************************************************************************************************
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// # Complete Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
    cout << "******************************************************" << endl;
    cout << "Using make()" << endl;
    cout << "******************************************************" << endl
         << endl;

    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}
void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    cout << "******************************************************" << endl;
    cout << "Using fill()" << endl;

    for (size_t i{0}; i < num; i++)
    {
        int temp{0};
        cout << "Enter number for position [" << i << "]: ";
        cin >> temp;
        vec.push_back(std::make_shared<Test>(temp));
    }
    cout << "******************************************************" << endl
         << endl;
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    cout << "******************************************************" << endl;
    cout << "Using display()" << endl;

    for (const auto &c : vec) // # use reference on c to avoid copy
    {
        cout << c->get_data() << endl;
    }
    cout << "******************************************************" << endl
         << endl;
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}