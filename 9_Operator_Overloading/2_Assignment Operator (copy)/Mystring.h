#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

class Mystring
{
private:
    char *str; // pointer to a char[] that holds a C-style string
public:
    Mystring();                       // No-args constructor
    Mystring(const char *s);          // Overloaded constructor
    Mystring(const Mystring &source); // Copy constructor
    ~Mystring();                      // Destructor

    Mystring &operator=(const Mystring &rhs); //! Copy assignment operator"symbol" - operator+

    void display() const;

    int get_length() const; // getters
    const char *get_str() const;
};
#endif