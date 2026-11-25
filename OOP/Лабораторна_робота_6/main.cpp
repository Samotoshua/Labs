#include <iostream>
#include "TBinary.h"
#include "THeximal.h"
#include "TInteger.h"

int main() {
    using std::cout, std::endl;

    // ================= BINARY =================

    cout << "Binary:" << endl;

    const int binaryNumbers[] = {1, 0, 1, 0, 1};

    TBinary binary1;
    TBinary binary2(binaryNumbers, 5);
    TBinary binaryCopy(binary2);

    cout << "Constructors:" << endl;

    binary1.output();
    binary2.output();
    binaryCopy.output();

    cout << "Operations:" << endl;

    binary1 += binary2;
    binary1.output();

    binary1 *= binary2;
    binary1.output();

    binary1 -= binary2;
    binary1.output();

    // ================= HEXIMAL =================

    cout << "\nHeximal:" << endl;

    const int hexNumbers[] = {3, 15};

    THeximal hex1;
    THeximal hex2(hexNumbers, 2);
    THeximal hexCopy(hex2);

    cout << "Constructors:" << endl;

    hex1.output();
    hex2.output();
    hexCopy.output();

    cout << "Operations:" << endl;

    hex1 += hex2;
    hex1.output();

    hex1 *= hex2;
    hex1.output();

    hex1 -= hex2;
    hex1.output();

    // ================= MIXED =================

    cout << "\nMixed operations:" << endl;

    binary2 += hex2;
    binary2.output();

    binary2 -= hex2;
    binary2.output();

    binary2 *= hex2;
    binary2.output();

    // ================= ASSIGNMENT =================

    cout << "\nAssignment:" << endl;

    binary1 = hex2;
    binary1.output();

    hex1 = binaryCopy;
    hex1.output();

    return 0;
}