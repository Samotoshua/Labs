
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

    std::cout << "\n======Operator << ======\n";
    std::cout << p1;
    std::cout << p3;

    std::cout << "\n======Operator == ======\n";
    std::cout << std::boolalpha;
    std::cout << "P3 == P4: " << (p3 == p4) << std::endl;
    std::cout << "P3 == Matrix: " << (p3 == pMatrix) << std::endl;

    std::cout << "\n======Operator + ======\n";
    Polynomial sum = p3 + pMatrix;
    std::cout << sum;

    std::cout << "\n======Operator - ======\n";
    Polynomial difference = p3 - pMatrix;
    std::cout << difference;

    std::cout << "\n======Operator * ======\n";
    Polynomial product = p3 * pMatrix;
    std::cout << product;




    std::cout << "\n======Func copy ======\n";
    Polynomial Pcopy = Polynomial::copy(p1);
    std::cout << Pcopy;

    std::cout << "\n======Func short fraction ======\n";
    pMatrix.toShort();
    std::cout << pMatrix;

    std::cout << "\n======Func calculate in point ======\n";
    std::cout << "P3(1) = " << p1.calcIn(1) << std::endl;
    std::cout << "P3(2) = " << p1.calcIn(2) << std::endl;

    std::cout << "\n======Func find derivative ======\n";
    Polynomial derivative(p1);
    derivative.derive();
    std::cout << derivative;

    std::cout << "\n======Func P(x+b) ======\n";
    p1.addParameter(2);
    std::cout << p1;


    return 0;
}
