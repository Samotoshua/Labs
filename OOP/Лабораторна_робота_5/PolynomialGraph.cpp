
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

    return colors[static_cast<int>(color)];
}

void PolynomialGraph::setColor(GraphColor newColor) {
    color = newColor;
}

void PolynomialGraph::draw(int width, int height, int scale) const {
    int centerX = width / 2;
    int centerY = height / 2;

    double limit = height / (2.0 * scale);
    double previousY = calcIn(-centerX / (double)scale);

    for (int px = 1; px < width; px++) {
        double x = (px - centerX) / (double)scale;
        double y = calcIn(x);

        if (std::isfinite(y) && std::isfinite(previousY) &&
            std::abs(y) <= limit &&
            std::abs(previousY) <= limit) {

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

    for (int i = 0; i < size; i++)
        result.whole[i] = -result.whole[i];

    return result;
}

bool PolynomialGraph::operator==(const PolynomialGraph& other) const {
    return Polynomial::operator==(other) && color == other.color;
}

void PolynomialGraph::operator[](int degree) const {
    if (degree < 0 || degree >= size) {
        std::cout << "Invalid degree!" << std::endl;
        return;
    }

    std::cout << "Coefficient at x^" << degree
              << " = " << whole[degree]
              << "/" << natural[degree] << std::endl;
}

std::ostream& operator<<(std::ostream& os,
                         const PolynomialGraph& graph) {
    return os << static_cast<const Polynomial&>(graph);
}
