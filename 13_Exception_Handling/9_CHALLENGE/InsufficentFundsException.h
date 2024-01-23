#ifndef INSUFFICENTFUNDSEXCEPTION_H
#define INSUFFICENTFUNDSEXCEPTION_H

#include <iostream>

class InsufficentFundsException : public std::exception
{
public:
    InsufficentFundsException() noexcept = default;
    virtual const char *what() const noexcept { return "Insufficent funds exception"; }
    ~InsufficentFundsException() = default;
};

#endif