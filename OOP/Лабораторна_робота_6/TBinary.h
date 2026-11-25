#ifndef LAB6_TBINARY_H
#define LAB6_TBINARY_H

#include "TInteger.h"

class TBinary : public TInteger {
public:
    TBinary();
    TBinary(const int* value, int size);

    using TInteger::operator=;

    void input() override;
    void output() const override;

    int getBase() const override {
        return 2;
    }

    TInteger& operator+=(const TInteger& other) override;
    TInteger& operator-=(const TInteger& other) override;
    TInteger& operator*=(const TInteger& other) override;
};

#endif