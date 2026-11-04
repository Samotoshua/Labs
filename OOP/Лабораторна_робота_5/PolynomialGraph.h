#ifndef POLYNOMIAL_GRAPH_H
#define POLYNOMIAL_GRAPH_H

#include "MyClass.h"
#include "raylib.h"

enum class GraphColor {
    Red,
    Green,
    Blue,
    Yellow,
    Purple,
    Black
};

class PolynomialGraph : public Polynomial {
private:
    GraphColor color;

public:
    PolynomialGraph();
    PolynomialGraph(int size, const int* num, const int* den,
                    GraphColor color = GraphColor::Blue);
    PolynomialGraph(const PolynomialGraph& other);

    Color getColor() const;
    void setColor(GraphColor newColor);
    void draw(int width, int height, int scale) const;
    void input();

    PolynomialGraph& operator++();
    PolynomialGraph& operator--();
    PolynomialGraph operator-() const;
    bool operator==(const PolynomialGraph& other) const;
    TPair operator[](int degree) const;

    friend std::istream& operator>>(std::istream& is, PolynomialGraph& graph);
    friend std::ostream& operator<<(std::ostream& os,
                                    const PolynomialGraph& graph);
};

#endif
