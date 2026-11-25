#ifndef LAB6_THEXIMAL_H
#define LAB6_THEXIMAL_H

#include "TInteger.h"

class THeximal : public TInteger {
public:
    THeximal();
    THeximal(const int* value, int size);

    using TInteger::operator=;

    void input() override;
    void output() const override;

    int getBase() const override {
        return 16;
    }

    TInteger& operator+=(const TInteger& other) override;
    TInteger& operator-=(const TInteger& other) override;
    TInteger& operator*=(const TInteger& other) override;
};

#endif