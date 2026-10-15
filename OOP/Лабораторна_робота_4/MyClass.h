#ifndef MyClass_h
#define MyClass_h

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

    void input();
    void output() const;
};

#endif