#include <iostream>
#include <cmath>
#include <cstring>

struct quadraticFunction {
    double a, b, c;
};

void init(quadraticFunction &f) {
    f.a = 0;
    f.b = 0;
    f.c = 0;
}

void input(quadraticFunction &f) {
    std::cin >> f.a >> f.b >> f.c;
}

void output(quadraticFunction &f) {
    std::cout << "f(x) = "
              << f.a << "x^2 + "
              << f.b << "x + "
              << f.c << std::endl;
}

char* toPChar(quadraticFunction &f) {
    char tmp[64];

    snprintf(
        tmp,
        sizeof(tmp),
        "%.2lfx^2 + %.2lfx + %.2lf",
        f.a,
        f.b,
        f.c
    );

    char* result = new char[strlen(tmp) + 1];
    strcpy(result, tmp);

    return result;
}

void shift(quadraticFunction &f, const double c) {
    f.c += c;
}

inline double discriminant(const quadraticFunction &f) {
    return f.b * f.b - 4 * f.a * f.c;
}

bool odd(const quadraticFunction &f) {
    if (-f.b / (2 * f.a) == 0)
        return true;

    return false;
}

int roots(const quadraticFunction &f, double rootsArray[2]) {
    double D = discriminant(f);

    if (D < 0) {
        return 0;
    }

    if (D == 0) {
        rootsArray[0] = -f.b / (2 * f.a);
        rootsArray[1] = rootsArray[0];

        return 1;
    }

    rootsArray[0] = (-f.b + sqrt(D)) / (2 * f.a);
    rootsArray[1] = (-f.b - sqrt(D)) / (2 * f.a);

    return 2;
}

void printVertex(const quadraticFunction &f) {
    double D = discriminant(f);

    std::cout << "Vertex: ("
              << -f.b / (2 * f.a)
              << ", "
              << -D / (4 * f.a)
              << ")"
              << std::endl;
}

void printRoots(double rootsArray[2], int count) {
    if (count == 0) {
        std::cout << "Roots: no roots" << std::endl;
    }

    else if (count == 1) {
        std::cout << "Roots: (" << rootsArray[0] << ")" << std::endl;
    }

    else {
        std::cout << "Roots: ("
                  << rootsArray[0] << ", "
                  << rootsArray[1] << ")"
                  << std::endl;
    }
}

int main() {
    quadraticFunction func;

    double rootsArray[2];

    init(func);

    std::cout << "=====INPUT=====" << std::endl;
    input(func);

    std::cout << "=====OUTPUT=====" << std::endl;

    output(func);

    int rootsCount = roots(func, rootsArray);

    printRoots(rootsArray, rootsCount);

    printVertex(func);

    if (odd(func))
        std::cout << "Function is even." << std::endl;
    else
        std::cout << "Function is odd." << std::endl;

    std::cout << "Intersections with OX: "
              << rootsCount
              << std::endl;

    std::cout << "=====END=====" << std::endl;


    shift(func, 15);


    std::cout << "=====OUTPUT=====" << std::endl;

    output(func);

    rootsCount = roots(func, rootsArray);

    printRoots(rootsArray, rootsCount);

    printVertex(func);

    if (odd(func))
        std::cout << "Function is even." << std::endl;
    else
        std::cout << "Function is odd." << std::endl;

    std::cout << "Intersections with OX: "
              << rootsCount
              << std::endl;

    std::cout << "=====END=====" << std::endl;

    char* converted = toPChar(func);

    std::cout << "Conversion: "
              << converted
              << std::endl;

    delete[] converted;

    return 0;
}