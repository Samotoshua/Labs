#include <iostream>
#include "PolynomialGraph.h"

int main() {
    int n1[] = {-1, 0, 1};
    int d1[] = {1, 1, 1};

    int n2[] = {1, 1};
    int d2[] = {1, 1};

    int n3[] = {4, 0, -1};
    int d3[] = {1, 1, 1};

    PolynomialGraph graph1(3, n1, d1, GraphColor::Blue);
    PolynomialGraph graph2(2, n2, d2);
    PolynomialGraph graph3(3, n3, d3, GraphColor::Green);
    graph2.setColor(GraphColor::Red);

    std::cout << "Original:\n" << graph1;

    ++graph1;
    std::cout << "After ++:\n" << graph1;

    --graph1;
    std::cout << "After --:\n" << graph1;

    PolynomialGraph negative = -graph1;
    std::cout << "Negative:\n" << negative;

    TPair coefficient = graph1[2];
    std::cout << "Coefficient at x^2 = "
              << coefficient.x << '/' << coefficient.y << '\n';

    PolynomialGraph copy(graph1);
    std::cout << std::boolalpha;
    std::cout << "Same polynomial and color: " << (graph1 == copy) << '\n';
    copy.setColor(GraphColor::Red);
    std::cout << "Same polynomial, different color: " << (graph1 == copy) << '\n';

    // std::cout << "\n--- Input using input() ---\n";
    // PolynomialGraph enteredByMethod;
    // enteredByMethod.input();
    // std::cout << "Entered polynomial:\n" << enteredByMethod;
    //
    // std::cout << "\n--- Input using operator >> ---\n";
    // PolynomialGraph enteredByOperator;
    // std::cin >> enteredByOperator;
    // std::cout << "Entered polynomial:\n" << enteredByOperator;

    const int width = 900;
    const int height = 600;
    const int scale = 40;
    const int centerX = width / 2;
    const int centerY = height / 2;

    InitWindow(width, height, "Polynomial Graphs");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int x = centerX % scale; x < width; x += scale)
            DrawLine(x, 0, x, height, LIGHTGRAY);

        for (int y = centerY % scale; y < height; y += scale)
            DrawLine(0, y, width, y, LIGHTGRAY);

        DrawLine(0, centerY, width, centerY, BLACK);
        DrawLine(centerX, 0, centerX, height, BLACK);

        graph1.draw(width, height, scale);
        graph2.draw(width, height, scale);
        graph3.draw(width, height, scale);

        DrawText("Blue: x^2 - 1", 15, 15, 20, BLUE);
        DrawText("Red: x + 1", 15, 40, 20, RED);
        DrawText("Green: 4 - x^2", 15, 65, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
