#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

struct quadraticFunction {
    double a, b, c;

    double roots[2];
};

void init(quadraticFunction &f, const double a, const double b, const double c) {
    f.a = a;
    f.b = b;
    f.c = c;

    f.roots[0] = 0;
    f.roots[1] = 0;
}

void input(quadraticFunction &f) {
    do {
        std::cin >> f.a >> f.b >> f.c;

        if (f.a == 0) {
            std::cout << "Coefficient a cannot be 0!" << std::endl;
            std::cout << "Try again." << std::endl;
        }
    } while (f.a == 0);
}

void output(const quadraticFunction &f) {
    std::cout << "f(x) = " << f.a << "x^2 + " << f.b << "x + " << f.c << std::endl;
}

char* toPChar(const quadraticFunction &f) {
    char tmp[64];

    snprintf(tmp, sizeof(tmp), "%.2lfx^2 + %.2lfx + %.2lf", f.a, f.b, f.c);

    char* result = new char[strlen(tmp) + 1];

    strcpy(result, tmp);

    return result;
}

void shift(quadraticFunction &f) {
    f.c += 1;
}

bool odd(const quadraticFunction &f) {
    if (f.b == 0) return true;

    return false;
}

int roots(quadraticFunction &f) {
    const double D = (f.b * f.b) - (4 * f.a * f.c);

    if (D < 0) {
        return 0;
    }
    else if (D == 0) {
        f.roots[0] = -f.b / (2 * f.a);
        f.roots[1] = f.roots[0];

        return 1;
    }
    else {
        f.roots[0] = (-f.b + sqrt(D)) / (2 * f.a);
        f.roots[1] = (-f.b - sqrt(D)) / (2 * f.a);

        return 2;
    }
}

void printVertex(const quadraticFunction &f) {
    const double D = (f.b * f.b) - (4 * f.a * f.c);

    std::cout << "Vertex: (" << -f.b / (2 * f.a) << ", " << -D / (4 * f.a) << ")" << std::endl;
}

int countIntersections(const quadraticFunction &f) {
    const double D = (f.b * f.b) - (4 * f.a * f.c);

    if (D < 0) return 0;
    if (D == 0) return 1;

    return 2;
}

int main() {
    quadraticFunction func;

    init(func, 1, 0, 0);

    std::cout << "=====INPUT=====" << std::endl;
    input(func);

    std::cout << "=====OUTPUT=====" << std::endl;
    output(func);

    const int rootsCount = roots(func);

    if (rootsCount == 0) {
        std::cout << "No real roots." << std::endl;
    }
    else if (rootsCount == 1) {
        std::cout << "Root: " << func.roots[0] << std::endl;
    }
    else {
        std::cout << "Roots: (" << func.roots[0] << ", " << func.roots[1] << ")" << std::endl;
    }

    printVertex(func);

    if (odd(func)) std::cout << "Function is even." << std::endl;
    else std::cout << "Function is neither even nor odd." << std::endl;

    std::cout << "Intersections with OX: " << countIntersections(func) << std::endl;

    char* converted = toPChar(func);
    std::cout << "Conversion: " << converted << std::endl;

    delete[] converted;

    std::cout << "=====END=====" << std::endl;


    shift(func);


    std::cout << "=====OUTPUT AFTER SHIFT=====" << std::endl;
    output(func);

    const int shiftedRootsCount = roots(func);

    if (shiftedRootsCount == 0) {
        std::cout << "No real roots." << std::endl;
    }
    else if (shiftedRootsCount == 1) {
        std::cout << "Root: " << func.roots[0] << std::endl;
    }
    else {
        std::cout << "Roots: (" << func.roots[0] << ", " << func.roots[1] << ")" << std::endl;
    }

    printVertex(func);

    if (odd(func)) std::cout << "Function is even." << std::endl;
    else std::cout << "Function is neither even nor odd." << std::endl;

    std::cout << "Intersections with OX: " << countIntersections(func) << std::endl;

    converted = toPChar(func);
    std::cout << "Conversion: " << converted << std::endl;

    delete[] converted;

    std::cout << "=====END=====" << std::endl;

    return 0;
}
