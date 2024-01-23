#include "Mystring.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

//# CTOR
Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

//# OVERLOADED CTOR
Mystring::Mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

//# Copy CTOR
Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

//# DETOR
Mystring::~Mystring()
{
    delete[] str;
}

//# Display method
void Mystring::display() const
{
    cout << str << ":" << get_length() << endl;
}

//# Get METH
int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; }