
#include "TBinary.h"

TBinary::TBinary() : TInteger() {
}

TBinary::TBinary(const int* arr, int size)
    : TInteger(arr, size) {

    for (int i = 0; i < size; i++) {
        if (value[i] != 0 && value[i] != 1) {
            throw std::invalid_argument("Invalid binary digit");
        }
    }
}

void TBinary::input() {
    std::string s;
    if (!(std::cin >> s)) {
        throw std::invalid_argument("Invalid input");
    }

    for (char c : s) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Invalid binary digit");
        }
    }

    int* arr = new int[s.size()];

    for (int i = 0; i < (int)s.size(); i++) {
        arr[i] = s[i] - '0';
    }

    delete[] value;
    value = arr;
    size = (int)s.size();
}

void TBinary::output() const {
    TInteger::output();
}

TInteger& TBinary::operator+=(const TInteger& other) {
    fromDecimal(toDecimal() + other.toDecimal());
    return *this;
}

TInteger& TBinary::operator-=(const TInteger& other) {
    fromDecimal(toDecimal() - other.toDecimal());
    return *this;
}

TInteger& TBinary::operator*=(const TInteger& other) {
    fromDecimal(toDecimal() * other.toDecimal());
    return *this;
}

