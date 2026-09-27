#include <iostream>

struct BinaryVector {
    int size;
    int *vector;

    void displayVector();
    int isValid();
};

void BinaryVector::displayVector() {
    std::cout << "(";

    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            std::cout << vector[i];
            break;
        }

        std::cout << vector[i] << ", ";
    }

    std::cout << ")";
}

int BinaryVector::isValid() {
    for (int i = 0; i < size; i++) {
        if ((vector[i] != 0) && (vector[i] != 1)) {
            std::cout << "Numbers must be either 0 or 1!" << std::endl;
            std::cout << "Try again." << std::endl;
            return 0;
        }
    }

    return 1;
}

std::istream& operator>>(std::istream& is, BinaryVector& v) {
    do {
        std::cout << "Enter vector: ";

        for (int i = 0; i < v.size; i++) {
            is >> v.vector[i];
        }

    } while (!v.isValid());

    return is;
}

BinaryVector operator+(BinaryVector &v1, BinaryVector &v2) {
    BinaryVector result;

    result.size = v1.size;
    result.vector = new int[result.size];

    for (int i = 0; i < result.size; i++) {
        result.vector[i] = v1.vector[i] + v2.vector[i];

        if (result.vector[i] == 2) {
            result.vector[i] = 1;
        }
    }

    return result;
}

BinaryVector operator*(BinaryVector &v1, BinaryVector &v2) {
    BinaryVector result;

    result.size = v1.size;
    result.vector = new int[result.size];

    for (int i = 0; i < result.size; i++) {
        result.vector[i] = v1.vector[i] * v2.vector[i];
    }

    return result;
}

int main() {
    BinaryVector bv1;
    BinaryVector bv2;
    BinaryVector Union;
    BinaryVector Intersection;

    std::cout << "=====INPUT=====" << std::endl;

    int n;

    do {
        std::cout << "Enter size: ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "Size must be greater than 0!" << std::endl;
            std::cout << "Try again." << std::endl;
        }

    } while (n <= 0);

    bv1.size = n;
    bv2.size = n;

    bv1.vector = new int[n];
    bv2.vector = new int[n];

    std::cout << "Vector 1:" << std::endl;
    std::cin >> bv1;

    std::cout << "Vector 2:" << std::endl;
    std::cin >> bv2;


    std::cout << "=====OUTPUT=====" << std::endl;

    std::cout << "Vector 1: ";
    bv1.displayVector();
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    bv2.displayVector();
    std::cout << std::endl;


    Union = bv1 + bv2;

    std::cout << "Union:        ";
    Union.displayVector();
    std::cout << std::endl;


    Intersection = bv1 * bv2;

    std::cout << "Intersection: ";
    Intersection.displayVector();
    std::cout << std::endl;


    std::cout << "=====END=====" << std::endl;

    delete[] bv1.vector;
    delete[] bv2.vector;
    delete[] Union.vector;
    delete[] Intersection.vector;

    return 0;
}