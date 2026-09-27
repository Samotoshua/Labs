#include <iostream>
#include <cmath>
#include <cstring>

struct quadraticFunction {
    double a, b, c;

    double roots[2];
};

void init(quadraticFunction &f) {
    f.a = NULL;
    f.b = NULL;
    f.c = NULL;
}

void input(quadraticFunction &f) {
    std::cin >> f.a >> f.b >> f.c;
}

void output(quadraticFunction &f) {
    std::cout << "f(x) = " << f.a << "x^2 + " << f.b << "x + " << f.c << std::endl;
}

char* toPChar(quadraticFunction &f) {
    char tmp[64];
    snprintf(tmp, sizeof(tmp), "%.2lfx^2 + %.2lfx + %.2lf", f.a, f.b, f.c);

    char* result = new char[strlen(tmp) + 1];
    strcpy(result, tmp);
    return result;
}

void shift(quadraticFunction &f, const double c) {
    f.c += c;
}

bool odd(const quadraticFunction &f) {
    if (-f.b / (2 * f.a) == 0) return true;
    return false;
}

void roots(quadraticFunction &f) {
    const double D = (f.b * f.b) - (4 * f.a * f.c);

    if (D < 0) { f.roots[0] = NULL; f.roots[1] = NULL; }
    if (D == 0) { f.roots[0] = -f.b / (2 * f.a); f.roots[1] = -f.b / (2 * f.a); }
    else {
        f.roots[0] = -f.b + sqrt(D) / (2 * f.a);
        f.roots[1] = -f.b - sqrt(D) / (2 * f.a);
    }
}

void printVertex(const quadraticFunction &f) {
    const double D = (f.b * f.b) - (4 * f.a * f.c);
    std::cout << "Vertex: (" << -f.b / (2 * f.a) << ", " <<  -D / (4 * f.a)  << ")" << std::endl;
}

int countIntersections(const quadraticFunction &f) {
    const double D = (f.b * f.b) - (4 * f.a * f.c);
    if (D < 0) return 0;
    if (D == 0) return 1;
    return 2;
}

int main() {
    quadraticFunction func;

    init(func);

    std::cout << "=====INPUT=====" << std::endl;
    input(func);

    std::cout << "=====OUTPUT=====" << std::endl;
    output(func);

    roots(func);
    std::cout << "Roots: (" << func.roots[0] << ", " << func.roots[1] << ")" << std::endl;

    printVertex(func);

    if (odd(func)) std::cout << "Fuction is even." << std::endl;
    else std::cout << "Fuction is odd." << std::endl;

    std::cout << "Intersections with OX: " << countIntersections(func) << std::endl;

    std::cout << "=====END=====" << std::endl;



    shift(func, 15);



    std::cout << "=====OUTPUT=====" << std::endl;
    output(func);

    roots(func);
    std::cout << "Roots: (" << func.roots[0] << ", " << func.roots[1] << ")" << std::endl;

    printVertex(func);

    if (odd(func)) std::cout << "Fuction is even." << std::endl;
    else std::cout << "Fuction is odd." << std::endl;

    std::cout << "Intersections with OX: " << countIntersections(func) << std::endl;

    std::cout << "=====END=====" << std::endl;

    char* converted = toPChar(func);
    std::cout << "Conversion: " << converted << std::endl;

    delete converted;

    return 0;
}