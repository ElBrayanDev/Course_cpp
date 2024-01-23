#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

class Mystring
{
private:
    char *str; // pointer to a char[] that has a C-style string

public:
    Mystring(); // CTOR
    Mystring(const char *s); // overloaded CTOR
    ~Mystring();             // DTOR
    Mystring(const Mystring &source); // copy CTOR

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif