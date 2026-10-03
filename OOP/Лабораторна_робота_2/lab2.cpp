#include <iostream>

struct BinaryVector {
    int size;
    int *vector;
};

void displayVector(BinaryVector &v) {
    std::cout << "(";

    for (int i = 0; i < v.size; i++) {
        if (i == v.size - 1) {
            std::cout << v.vector[i];
            break;
        }

        std::cout << v.vector[i] << ", ";
    }

    std::cout << ")";
}

int isValid(BinaryVector &v) {
    for (int i = 0; i < v.size; i++) {
        if ((v.vector[i] != 0) && (v.vector[i] != 1)) {
            std::cout << "Numbers must be either 0 or 1!" << std::endl;
            std::cout << "Try again." << std::endl;
            return 0;
        }
    }

    return 1;
}

std::istream& operator>>(std::istream& is, BinaryVector& v) {
    std::cout << "Enter size: ";
    is >> v.size;

    v.vector = new int[v.size];

    do {
        std::cout << "Enter vector: ";

        for (int i = 0; i < v.size; i++) {
            is >> v.vector[i];
        }

    } while (!isValid(v));

    return is;
}

BinaryVector operator+(BinaryVector &v1, BinaryVector &v2) {
    BinaryVector result;

    if (v1.size >= v2.size) {
        result.size = v1.size;
    }
    else {
        result.size = v2.size;
    }

    result.vector = new int[result.size];

    for (int i = 0; i < result.size; i++) {

        if (i < v1.size && i < v2.size) {
            result.vector[i] = v1.vector[i] + v2.vector[i];
        }
        else if (i < v1.size) {
            result.vector[i] = v1.vector[i];
        }
        else if (i < v2.size) {
            result.vector[i] = v2.vector[i];
        }

        if (result.vector[i] == 2) {
            result.vector[i] = 1;
        }
    }

    return result;
}

BinaryVector operator*(BinaryVector &v1, BinaryVector &v2) {
    BinaryVector result;

    if (v1.size >= v2.size) {
        result.size = v2.size;
    }
    else {
        result.size = v1.size;
    }

    result.vector = new int[result.size];

    for (int i = 0; i < result.size; i++) {
        result.vector[i] = v1.vector[i] * v2.vector[i];
    }

    return result;
}

void printNumbersFromVector(BinaryVector &v) {
    std::cout << "(";

    int first = 1;

    for (int i = 0; i < v.size; i++) {

        if (v.vector[i] == 1) {

            if (!first) {
                std::cout << ", ";
            }

            std::cout << i;
            first = 0;
        }
    }

    std::cout << ")";
}

int main() {
    BinaryVector bv1;
    BinaryVector bv2;
    BinaryVector Union;
    BinaryVector Crossing;

    std::cout << "=====INPUT=====" << std::endl;

    std::cin >> bv1;
    std::cin >> bv2;

    std::cout << "=====OUTPUT=====" << std::endl;

    std::cout << "Vector 1: ";
    displayVector(bv1);
    std::cout << std::endl;

    std::cout << "Numbers: ";
    printNumbersFromVector(bv1);
    std::cout << std::endl;


    std::cout << "Vector 2: ";
    displayVector(bv2);
    std::cout << std::endl;

    std::cout << "Numbers: ";
    printNumbersFromVector(bv2);
    std::cout << std::endl;


    Union = bv1 + bv2;

    std::cout << "Union: ";
    displayVector(Union);
    std::cout << std::endl;

    std::cout << "Numbers: ";
    printNumbersFromVector(Union);
    std::cout << std::endl;


    Crossing = bv1 * bv2;

    std::cout << "Crossing: ";
    displayVector(Crossing);
    std::cout << std::endl;

    std::cout << "Numbers: ";
    printNumbersFromVector(Crossing);
    std::cout << std::endl;


    std::cout << "=====END=====" << std::endl;

    return 0;
}