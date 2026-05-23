#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i_A, j_A;

    printf("Enter rows and columns: ");
    scanf("%d %d", &i_A, &j_A);

    if (i_A <= 0 || j_A <= 0) return 1;

    int *A = (int *)malloc(i_A * j_A * sizeof(int));

    int elements = 0;
    double result = 1;

    printf("Enter matrix elements: \n");
    for(int i = 0; i < i_A; i++) {
        for(int j = 0; j < j_A; j++) {
            scanf("%d", (A + i * j_A + j));
        }
    }

    for(int i = 0; i < i_A; i += 2) {
        for(int j = 0; j < j_A; j += 2) {
            int val = *(A + i * j_A + j);
            if (val > 0) {
                result *= val;
                elements++;
            }
        }
    }

    if (elements > 0)
        printf("Seredne geometricne %lf\n", pow(result, 1.0 / elements));

    free(A);
    return 0;
}