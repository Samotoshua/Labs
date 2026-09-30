#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

struct quadraticFunction {
    double a, b, c;

    double roots[2];
};

class quadraticFunctionClass {
    private:
        quadraticFunction object;

    public:
        void init(double, double, double);
        void input();
        void output() const;
        char* toPChar() const;

        void setStruct(const quadraticFunction&);
        quadraticFunction getStruct() const;
};

void quadraticFunctionClass::init(const double a, const double b, const double c) {
    object.a = a;
    object.b = b;
    object.c = c;

    object.roots[0] = 0;
    object.roots[1] = 0;
}

void quadraticFunctionClass::input() {
    do {
        std::cin >> object.a >> object.b >> object.c;

        if (object.a == 0) {
            std::cout << "Coefficient a cannot be 0!" << std::endl;
            std::cout << "Try again." << std::endl;
        }
    } while (object.a == 0);
}

void quadraticFunctionClass::output() const {
    std::cout << "f(x) = " << object.a << "x^2 + " << object.b << "x + " << object.c << std::endl;
}

char* quadraticFunctionClass::toPChar() const {
    char tmp[64];

    snprintf(tmp, sizeof(tmp), "%.2lfx^2 + %.2lfx + %.2lf", object.a, object.b, object.c);

    char* result = new char[strlen(tmp) + 1];

    strcpy(result, tmp);

    return result;
}

void quadraticFunctionClass::setStruct(const quadraticFunction &f) {
    object = f;
}

quadraticFunction quadraticFunctionClass::getStruct() const {
    return object;
}

void shift(quadraticFunctionClass &f) {
    quadraticFunction object = f.getStruct();

    object.c += 1;

    f.setStruct(object);
}

bool odd(const quadraticFunctionClass &f) {
    quadraticFunction object = f.getStruct();

    if (object.b == 0) return true;

    return false;
}

int roots(quadraticFunctionClass &f) {
    quadraticFunction object = f.getStruct();

    const double D = (object.b * object.b) - (4 * object.a * object.c);

    if (D < 0) {
        f.setStruct(object);

        return 0;
    }
    else if (D == 0) {
        object.roots[0] = -object.b / (2 * object.a);
        object.roots[1] = object.roots[0];

        f.setStruct(object);

        return 1;
    }
    else {
        object.roots[0] = (-object.b + sqrt(D)) / (2 * object.a);
        object.roots[1] = (-object.b - sqrt(D)) / (2 * object.a);

        f.setStruct(object);

        return 2;
    }
}

void printRoots(const quadraticFunctionClass &f, const int rootsCount) {
    quadraticFunction object = f.getStruct();

    if (rootsCount == 0) {
        std::cout << "No real roots." << std::endl;
    }
    else if (rootsCount == 1) {
        std::cout << "Root: " << object.roots[0] << std::endl;
    }
    else {
        std::cout << "Roots: (" << object.roots[0] << ", " << object.roots[1] << ")" << std::endl;
    }
}

void printVertex(const quadraticFunctionClass &f) {
    quadraticFunction object = f.getStruct();

    const double D = (object.b * object.b) - (4 * object.a * object.c);

    std::cout << "Vertex: (" << -object.b / (2 * object.a) << ", " << -D / (4 * object.a) << ")" << std::endl;
}

int countIntersections(const quadraticFunctionClass &f) {
    quadraticFunction object = f.getStruct();

    const double D = (object.b * object.b) - (4 * object.a * object.c);

    if (D < 0) return 0;
    if (D == 0) return 1;

    return 2;
}

int main() {
    quadraticFunctionClass func;

    func.init(1, 0, 0);

    std::cout << "=====INPUT=====" << std::endl;
    func.input();

    std::cout << "=====OUTPUT=====" << std::endl;
    func.output();

    int rootsCount = roots(func);
    printRoots(func, rootsCount);

    printVertex(func);

    if (odd(func)) std::cout << "Function is even." << std::endl;
    else std::cout << "Function is neither even nor odd." << std::endl;

    std::cout << "Intersections with OX: " << countIntersections(func) << std::endl;

    char* converted = func.toPChar();
    std::cout << "Conversion: " << converted << std::endl;

    delete[] converted;

    std::cout << "=====END=====" << std::endl;



    shift(func);



    std::cout << "=====OUTPUT=====" << std::endl;
    func.output();

    rootsCount = roots(func);
    printRoots(func, rootsCount);

    printVertex(func);

    if (odd(func)) std::cout << "Function is even." << std::endl;
    else std::cout << "Function is neither even nor odd." << std::endl;

    std::cout << "Intersections with OX: " << countIntersections(func) << std::endl;

    converted = func.toPChar();
    std::cout << "Conversion: " << converted << std::endl;

    delete[] converted;

    std::cout << "=====END=====" << std::endl;

    return 0;
}
