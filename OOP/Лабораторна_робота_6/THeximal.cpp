
#include "THeximal.h"
#include <stdexcept>

THeximal::THeximal() : TInteger() {
}

THeximal::THeximal(const int* arr, int size)
    : TInteger(arr, size) {

    for (int i = 0; i < size; i++) {
        if (value[i] < 0 || value[i] > 15) {
            throw std::invalid_argument("Invalid hex digit");
        }
    }
}

void THeximal::input() {
    std::string s;
    if (!(std::cin >> s)) {
        throw std::invalid_argument("Invalid input");
    }

    for (char c : s) {
        if (!((c >= '0' && c <= '9') ||
              (c >= 'A' && c <= 'F') ||
              (c >= 'a' && c <= 'f'))) {
            throw std::invalid_argument("Invalid hex digit");
              }
    }

    int* arr = new int[s.size()];

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];

        if (c >= '0' && c <= '9')
            arr[i] = c - '0';
        else if (c >= 'A' && c <= 'F')
            arr[i] = c - 'A' + 10;
        else
            arr[i] = c - 'a' + 10;
    }

    delete[] value;
    value = arr;
    size = (int)s.size();
}

void THeximal::output() const {
    for (int i = 0; i < size; i++) {
        if (value[i] < 10) {
            std::cout << value[i];
        } else {
            std::cout << char('A' + value[i] - 10);
        }
    }

    std::cout << std::endl;
}

TInteger& THeximal::operator+=(const TInteger& other) {
    fromDecimal(toDecimal() + other.toDecimal());
    return *this;
}

TInteger& THeximal::operator-=(const TInteger& other) {
    fromDecimal(toDecimal() - other.toDecimal());
    return *this;
}

TInteger& THeximal::operator*=(const TInteger& other) {
    fromDecimal(toDecimal() * other.toDecimal());
    return *this;
}
