/*
# PURE VIRTUAL FUNCTIONS AND ABSTRACT CLASSES

# Concrete class (normal)
    • Used to instantiate objects from
    • All their member functions are defined
        • Checking Account, Savings Account
        • Faculty, Staff
        • Enemy, Level Boss.

# Abstract class
    • Cannot instantiate objects

    • These classes are used as base classes in inheritance hierarchies

    • Often referred to as Abstract Base Classes

    • Too generic to create objects from
        • Shape, Employee, Account, Player

    • Serves as parent to Derived classes that may have objects

    • Contains at least one pure virtual function

# Pure virtual function

    • Used to make a class abstract
    • Specified with "=0" in its declaration
    • Typically do not provide implementations
!    virtual void function () = 0;

    • Derived classes MUST override the base class
    • If the Derived class does not override then the Derived class is also abstract
    • Used when it doesn't make sense for a base class to have an implementation
        • But concrete classes must implement it

    virtual void draw () = 0;    // Shape
    virtual void defend () = 0;  // Player

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Shape
{ // Abstract Base class
private:
    // attributes common to all shapes
public:
    virtual void draw() = 0;   // pure virtual function
    virtual void rotate() = 0; // pure virtual function
    virtual ~Shape() {}
};

class Open_Shape : public Shape
{ // Abstract class
public:
    virtual ~Open_Shape() {}
};

class Closed_Shape : public Shape
{ // Abstract class
public:
    virtual ~Closed_Shape(){};
};

class Line : public Open_Shape
{ // Concrete class
public:
    virtual void draw() override
    {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle : public Closed_Shape
{ // Concrete class
public:
    virtual void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square : public Closed_Shape
{ // Concrete class
public:
    virtual void draw() override
    {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};

void screen_refresh(const std::vector<Shape *> &shapes)
{
    std::cout << "Refreshing" << std::endl;
    for (const auto p : shapes)
        p->draw();
}

int main()
{
    // cannot declare a variable of abstract type ()
    //    Shape s;
    //    Shape *p = new Shape();

    //        Circle c;
    //        c.draw();

    //    Shape *ptr = new Circle();
    //    ptr->draw();
    //    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    std::vector<Shape *> shapes{s1, s2, s3};

    //    for (const auto p: shapes)
    //        p->draw();

    screen_refresh(shapes);

    delete s1;
    delete s2;
    delete s3;

    return 0;
}