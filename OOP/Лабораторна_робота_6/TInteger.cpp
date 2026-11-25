
#include "TInteger.h"
#include <stdexcept>

TInteger::TInteger() {
    size = 1;
    value = new int[size];
    value[0] = 0;
}

TInteger::TInteger(const int* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        throw std::invalid_argument("Invalid array");
    }

    this->size = size;
    value = new int[size];

    for (int i = 0; i < size; i++) {
        value[i] = arr[i];
    }
}

TInteger::TInteger(const TInteger& other) {
    size = other.size;
    value = new int[size];

    for (int i = 0; i < size; i++) {
        value[i] = other.value[i];
    }
}

TInteger::~TInteger() {
    delete[] value;
}

long long TInteger::toDecimal() const {
    long long number = 0;

    for (int i = 0; i < size; i++) {
        number = number * getBase() + value[i];
    }

    return number;
}

void TInteger::fromDecimal(long long number) {
    if (number < 0) {
        number = -number;
    }

    int base = getBase();
    int n = 1;
    long long temp = number;

    while (temp >= base) {
        temp /= base;
        n++;
    }

    int* arr = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = number % base;
        number /= base;
    }

    delete[] value;
    value = arr;
    size = n;
}

void TInteger::output() const {
    for (int i = 0; i < size; i++) {
        std::cout << value[i];
    }

    std::cout << std::endl;
}

TInteger& TInteger::operator=(const TInteger& other) {
    if (this != &other) {
        fromDecimal(other.toDecimal());
    }

    return *this;
}