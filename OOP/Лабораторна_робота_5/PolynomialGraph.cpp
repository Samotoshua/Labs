#include "PolynomialGraph.h"
#include <cmath>
#include <iostream>

PolynomialGraph::PolynomialGraph()
    : Polynomial(), color(GraphColor::Blue) {}

PolynomialGraph::PolynomialGraph(int size, const int* num,
                                 const int* den, GraphColor color)
    : Polynomial(size, num, den), color(color) {}

PolynomialGraph::PolynomialGraph(const PolynomialGraph& other)
    : Polynomial(other), color(other.color) {}

Color PolynomialGraph::getColor() const {
    const Color colors[] = {
        RED, GREEN, BLUE, YELLOW, PURPLE, BLACK
    };
    return colors[static_cast<int>(this->color)];
}

void PolynomialGraph::setColor(GraphColor newColor) {
    color = newColor;
}

void PolynomialGraph::draw(int width, int height, int scale) const {
    if (width <= 0 || height <= 0 || scale <= 0) return;

    int centerX = width / 2;
    int centerY = height / 2;
    double limit = height / (2.0 * scale);
    double previousY = calcIn(-centerX / (double)scale);

    for (int px = 1; px < width; px++) {
        double x = (px - centerX) / (double)scale;
        double y = calcIn(x);

        if (std::abs(y) <= limit && std::abs(previousY) <= limit) {
            int py1 = centerY - (int)(previousY * scale);
            int py2 = centerY - (int)(y * scale);
            DrawLine(px - 1, py1, px, py2, getColor());
        }
        previousY = y;
    }
}

PolynomialGraph& PolynomialGraph::operator++() {
    whole[0] += natural[0];
    return *this;
}

PolynomialGraph& PolynomialGraph::operator--() {
    whole[0] -= natural[0];
    return *this;
}

PolynomialGraph PolynomialGraph::operator-() const {
    PolynomialGraph result(*this);
    for (int i = 0; i < size; i++) {
        result.whole[i] = -result.whole[i];
    }
    return result;
}

bool PolynomialGraph::operator==(const PolynomialGraph& other) const {
    return Polynomial::operator==(other) && color == other.color;
}

TPair PolynomialGraph::operator[](int degree) const {
    if (degree < 0 || degree >= size) {
        std::cout << "Invalid degree!\n";
        return {0, 1};
    }
    return {whole[degree], natural[degree]};
}

void PolynomialGraph::input() {
    std::cin >> *this;
}

std::istream& operator>>(std::istream& is, PolynomialGraph& graph) {
    int count;
    std::cout << "Enter number of coefficients: ";
    is >> count;
    if (!is) return is;//cin.fail()

    while (count <= 0) {
        std::cout << "Invalid size! Enter again: ";
        is >> count;
        if (!is) return is;
    }

    Polynomial temp(count);
    graph.Polynomial::operator=(temp);

    for (int i = 0; i < count; i++) {
        std::cout << "Numerator[" << i << "] = ";
        is >> graph.whole[i];
        if (!is) return is;

        std::cout << "Denominator[" << i << "] = ";
        is >> graph.natural[i];
        if (!is) return is;

        while (graph.natural[i] == 0) {
            std::cout << "Denominator cannot be zero! Enter again: ";
            is >> graph.natural[i];
            if (!is) return is;//cin.fail()
        }
    }

    std::cout << "Choose color:\n"
              << "1 - Red\n2 - Green\n3 - Blue\n"
              << "4 - Yellow\n5 - Purple\n6 - Black\n"
              << "Color (1-6): ";

    int choice;
    is >> choice;
    if (!is) return is;

    while (choice < 1 || choice > 6) {
        std::cout << "Invalid color! Enter from 1 to 6: ";
        is >> choice;
        if (!is) return is;
    }

    graph.color = static_cast<GraphColor>(choice - 1);
    return is;
}


std::ostream& operator<<(std::ostream& os, const PolynomialGraph& graph) {
    const char* names[] = {
        "Red", "Green", "Blue",
        "Yellow", "Purple", "Black"
    };

    const char* ansiColors[] = {
        "\x1B[31m", "\x1B[32m", "\x1B[34m",
        "\x1B[33m", "\x1B[35m", "\x1B[30m"
    };

    int index = static_cast<int>(graph.color);

    os << ansiColors[index];
    os << static_cast<const Polynomial&>(graph);
    os << "\x1B[0m";

    os << "Color: " << names[index]
       << " (" << index + 1 << ")\n";

    return os;
}

