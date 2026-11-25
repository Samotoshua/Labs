
#ifndef LAB6_TINTEGER_H
#define LAB6_TINTEGER_H

#include <iostream>

class TInteger {
protected:
    int* value;
    int size;

    void fromDecimal(long long number);

public:
    TInteger();
    TInteger(const int* value, int size);
    TInteger(const TInteger& other);

    virtual ~TInteger();

    TInteger& operator=(const TInteger& other);

    virtual void input() = 0;
    virtual void output() const = 0;

    long long toDecimal() const;
    virtual int getBase() const = 0;

    virtual TInteger& operator+=(const TInteger& other) = 0;
    virtual TInteger& operator-=(const TInteger& other) = 0;
    virtual TInteger& operator*=(const TInteger& other) = 0;
};

#endif
