#include "MyClass.h"
#include <cmath>
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

// Polynomial Polynomial::operator-(const Polynomial &other) const {
//     return (other * -1 ) + *this;
// }

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

Polynomial Polynomial::operator*(const double num) const {
    Polynomial result(this->size);
    for (int i = 0; i < this->size; i++) {
        int t = this->whole[i] * num;

        result.whole[i] = t;
        result.natural[i] = this->natural[i];
    }
    return result;
}

bool Polynomial::operator==(const Polynomial &other) const {
    if (size != other.size) return false;

    for (int i = 0; i < size; i++) {
        if (whole[i] * other.natural[i] != other.whole[i] * natural[i]) {
            return false;
        }
    }

    return true;
}

Polynomial Polynomial::copy(const Polynomial &other) {
    return Polynomial(other);
}

void Polynomial::toShort() const {
    for (int i = 0; i < size; i++) {
        int a = whole[i];
        int b = natural[i];

        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            const int temp = b;
            b = a % b;
            a = temp;
        }

        whole[i] /= a;
        natural[i] /= a;

        if (natural[i] < 0) {
            whole[i] *= -1;
            natural[i] *= -1;
        }
    }
}

double Polynomial::calcIn(const double num) const {
    double result = 0;

    for (int i = 0; i < size; i++) {
        result += (whole[i] * 1.0 / natural[i]) * std::pow(num, i);
    }

    return result;
}

void Polynomial::derive() {
    const int newSize = (size > 1) ? size - 1 : 1;
    Polynomial result(newSize);

    for (int i = 1; i < size; i++) {
        result.whole[i - 1] = whole[i] * i;
        result.natural[i - 1] = natural[i];
    }

    result.toShort();
    *this = result;
}

void Polynomial::addParameter(const double num) {
    const int b = num;

    int n[] = {b, 1};
    int d[] = {1, 1};

    Polynomial shift(2, n, d);// P(x) = num + x
    Polynomial result(1, &whole[size - 1], &natural[size - 1]);// P(x) = lastN/lastD

    for (int i = size - 2; i >= 0; i--) {
        Polynomial coefficient(1, &whole[i], &natural[i]);

        result = result * shift + coefficient;
        result.toShort();
    }

    *this = result;
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

