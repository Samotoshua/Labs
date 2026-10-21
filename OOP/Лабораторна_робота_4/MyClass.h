#ifndef MyClass_h
#define MyClass_h

#include <iostream>

class Polynomial {
private:
    int size;
    int *whole;
    int *natural;

public:
    Polynomial();
    Polynomial(int size);
    Polynomial(int size, const int *matrix);
    Polynomial(int size, const int *num, const int *den);
    Polynomial(const Polynomial &other);

    ~Polynomial();

    Polynomial& operator=(const Polynomial &other);
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;

    bool operator==(const Polynomial &other) const;

    friend std::ostream& operator<<(std::ostream &os, const Polynomial &other);

    void input();
    void output() const;
};

#endif