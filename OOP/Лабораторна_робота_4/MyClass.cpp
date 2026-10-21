#include "MyClass.h"
#include <iostream>

Polynomial::Polynomial() {
    size = 1;
    whole = new int[size];
    natural = new int[size];

    whole[0] = 0;
    natural[0] = 1;

    std::cout << "Default constructor" << std::endl;
}

Polynomial::Polynomial(int size) {
    while (size <= 0) {
        std::cout << "Invalid size! Enter again: ";
        std::cin >> size;
    }

    this->size = size;
    whole = new int[size];
    natural = new int[size];

    for (int i = 0; i < size; i++) {
        whole[i] = 0;
        natural[i] = 1;
    }

    std::cout << "Constructor with size" << std::endl;
}

Polynomial::Polynomial(int size, const int *matrix) {
    if (size <= 0) {
        this->size = 0;

        whole = nullptr;
        natural = nullptr;

        std::cout << "Invalid size! Enter polynomial again:" << std::endl;
        input();
    }
    else {
        this->size = size;
        whole = new int[size];
        natural = new int[size];

        for (int i = 0; i < size; i++) {
            whole[i] = matrix[i];
            natural[i] = matrix[i + size];

            while (natural[i] == 0) {
                std::cout << "Denominator cannot be zero! Enter again: ";
                std::cin >> natural[i];
            }
        }
    }

    std::cout << "Constructor with arrays" << std::endl;
}

Polynomial::Polynomial(int size, const int *num, const int *den) {
    if (size <= 0) {
        this->size = 0;

        whole = nullptr;
        natural = nullptr;

        std::cout << "Invalid size! Enter polynomial again:" << std::endl;
        input();
    }
    else {
        this->size = size;
        whole = new int[size];
        natural = new int[size];

        for (int i = 0; i < size; i++) {
            whole[i] = num[i];
            natural[i] = den[i];

            while (natural[i] == 0) {
                std::cout << "Denominator cannot be zero! Enter again: ";
                std::cin >> natural[i];
            }
        }
    }

    std::cout << "Constructor with arrays" << std::endl;
}

Polynomial::Polynomial(const Polynomial &other) {
    size = other.size;
    whole = new int[size];
    natural = new int[size];

    for (int i = 0; i < size; i++) {
        whole[i] = other.whole[i];
        natural[i] = other.natural[i];
    }

    std::cout << "Copy constructor" << std::endl;
}

Polynomial::~Polynomial() {
    delete[] whole;
    delete[] natural;

    std::cout << "Destructor" << std::endl;
}

Polynomial& Polynomial::operator=(const Polynomial &other) {
    if (this != &other) {
        delete[] whole;
        delete[] natural;

        size = other.size;
        whole = new int[size];
        natural = new int[size];

        for (int i = 0; i < size; i++) {
            whole[i] = other.whole[i];
            natural[i] = other.natural[i];
        }
    }

    std::cout << "Assignment operator" << std::endl;

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &other) const {
    int newSize = (this->size > other.size) ? this->size : other.size;
    Polynomial result(newSize);

    for (int i = 0; i < newSize; i++) {
        int num1 = (i < this->size) ? this->whole[i] : 0;
        int den1 = (i < this->size) ? this->natural[i] : 1;

        int num2 = (i < other.size) ? other.whole[i] : 0;
        int den2 = (i < other.size) ? other.natural[i] : 1;

        result.whole[i] = num1 * den2 + num2 * den1;
        result.natural[i] = den1 * den2;
    }

    return result;
}

Polynomial Polynomial::operator-(const Polynomial &other) const {
    int newSize = (this->size > other.size) ? this->size : other.size;
    Polynomial result(newSize);

    for (int i = 0; i < newSize; i++) {
        int num1 = (i < this->size) ? this->whole[i] : 0;
        int den1 = (i < this->size) ? this->natural[i] : 1;

        int num2 = (i < other.size) ? other.whole[i] : 0;
        int den2 = (i < other.size) ? other.natural[i] : 1;

        result.whole[i] = num1 * den2 - num2 * den1;
        result.natural[i] = den1 * den2;
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial &other) const {
    int newSize = size + other.size - 1;
    Polynomial result(newSize);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < other.size; j++) {
            int k = i + j;

            int num = whole[i] * other.whole[j];
            int den = natural[i] * other.natural[j];

            result.whole[k] = result.whole[k] * den + num * result.natural[k];
            result.natural[k] *= den;
        }
    }

    return result;
}

bool Polynomial::operator==(const Polynomial &other) const {
    if (this->size == other.size) {
        for (int i = 0; i < size; i++) {
            if ((this->whole[i] != other.whole[i]) || (this->natural[i] != other.natural[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &other) {
    os << "P(x) = ";

    for (int i = 0; i < other.size; i++) {
        if (i > 0)
            os << " + ";

        os << "(" << other.whole[i] << "/" << other.natural[i] << ")";

        if (i > 0)
            os << "*x";

        if (i > 1)
            os << "^" << i;
    }

    os << std::endl;
    return os;
}

void Polynomial::input() {
    std::cout << "Enter number of coefficients: ";
    std::cin >> size;

    while (size <= 0) {
        std::cout << "Invalid size! Enter again: ";
        std::cin >> size;
    }

    delete[] whole;
    delete[] natural;

    whole = new int[size];
    natural = new int[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Numerator[" << i << "] = ";
        std::cin >> whole[i];

        std::cout << "Denominator[" << i << "] = ";
        std::cin >> natural[i];

        while (natural[i] == 0) {
            std::cout << "Denominator cannot be zero! Enter again: ";
            std::cin >> natural[i];
        }
    }
}

void Polynomial::output() const {
    std::cout << "P(x) = ";

    for (int i = 0; i < size; i++) {
        if (i > 0)
            std::cout << " + ";

        std::cout << "(" << whole[i] << "/" << natural[i] << ")";

        if (i > 0)
            std::cout << "*x";

        if (i > 1)
            std::cout << "^" << i;
    }

    std::cout << std::endl;
}