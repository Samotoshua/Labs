#include <iostream>
#include "MyClass.h"

int main() {
    Polynomial p1;

    Polynomial p2(3);

    int whole[] = {1, 3, -2};
    int natural[] = {2, 4, 5};

    int matrix[2][3] = {{1,7,-2}, {8,41,6}};
    Polynomial pMatrix(3, *matrix);

    Polynomial p3(3, whole, natural);

    Polynomial p4(p3);

    std::cout << "\nP1: ";
    p1.output();

    std::cout << "P2: ";
    p2.output();

    std::cout << "Matrix: ";
    pMatrix.output();

    std::cout << "P3: ";
    p3.output();

    std::cout << "P4: ";
    p4.output();

    std::cout << "\n======Assignment P2 = P3======\n";
    p2 = p3;
    p2.output();

    std::cout << "\n======Input P1=====\n";
    p1.input();
    p1.output();

    return 0;
}