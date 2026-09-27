#include <iostream>
#include <cmath>
#include <cstring>

struct quadraticFunction {
    double a, b, c;

    double roots[2];
};

class quadraticFunctionClass {
    private:
        quadraticFunction object;
    public:
        void init();
        void input();
        void output() const;
        char* toPChar() const;
        void roots();
        void printRoots() const;
        void printVertex() const;
        int countIntersections() const;
        bool odd() const;
        void shift(double);
};

void quadraticFunctionClass::init() {
    object.a = NULL;
    object.b = NULL;
    object.c = NULL;
}

void quadraticFunctionClass::input() {
    std::cin >> object.a >> object.b >> object.c;
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

void quadraticFunctionClass::shift(const double c) {
    object.c += c;
}

bool quadraticFunctionClass::odd() const {
    if (-object.b / (2 * object.a) == 0) return true;
    return false;
}

void quadraticFunctionClass::roots() {
    const double D = (object.b * object.b) - (4 * object.a * object.c);

    if (D < 0) { object.roots[0] = NULL; object.roots[1] = NULL; }
    if (D == 0) { object.roots[0] = -object.b / (2 * object.a); object.roots[1] = -object.b / (2 * object.a); }
    else {
        object.roots[0] = -object.b + sqrt(D) / (2 * object.a);
        object.roots[1] = -object.b - sqrt(D) / (2 * object.a);
    }
}

void quadraticFunctionClass::printRoots() const {
    std::cout << "Roots: (" << object.a << ", " << object.b << ")" << std::endl;
}

void quadraticFunctionClass::printVertex() const {
    const double D = (object.b * object.b) - (4 * object.a * object.c);
    std::cout << "Vertex: (" << -object.b / (2 * object.a) << ", " <<  -D / (4 * object.a)  << ")" << std::endl;
}

int quadraticFunctionClass::countIntersections() const {
    const double D = (object.b * object.b) - (4 * object.a * object.c);
    if (D < 0) return 0;
    if (D == 0) return 1;
    return 2;
}

int main() {
    quadraticFunctionClass func;

    func.init();

    std::cout << "=====INPUT=====" << std::endl;
    func.input();

    std::cout << "=====OUTPUT=====" << std::endl;
    func.output();


    func.roots();
    func.printRoots();

    func.printVertex();

    if (func.odd()) std::cout << "Fuction is even." << std::endl;
    else std::cout << "Fuction is odd." << std::endl;

    std::cout << "Intersections with OX: " << func.countIntersections() << std::endl;

    std::cout << "=====END=====" << std::endl;



    func.shift(15);



    std::cout << "=====OUTPUT=====" << std::endl;
    func.output();

    func.roots();
    func.printRoots();

    func.printVertex();

    if (func.odd()) std::cout << "Fuction is even." << std::endl;
    else std::cout << "Fuction is odd." << std::endl;

    std::cout << "Intersections with OX: " << func.countIntersections() << std::endl;

    std::cout << "=====END=====" << std::endl;

    char* converted = func.toPChar();
    std::cout << "Conversion: " << converted << std::endl;

    delete converted;

    return 0;
}