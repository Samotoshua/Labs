
#ifndef PolynomialGraph_h
#define PolynomialGraph_h

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

    PolynomialGraph& operator++();
    PolynomialGraph& operator--();
    PolynomialGraph operator-() const;
    bool operator==(const PolynomialGraph& other) const;
    void operator[](int degree) const;

    friend std::ostream& operator<<(std::ostream& os,
                                    const PolynomialGraph& graph);
};

#endif
