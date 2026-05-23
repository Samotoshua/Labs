#include <stdio.h>
#include <stdlib.h>

int main() {
    int lengthOfA;
    int counterForB = 0;

    printf("Enter length of A: ");
    scanf("%d", &lengthOfA);

    if (lengthOfA <= 0) return 1;

    int *A = (int *)malloc(lengthOfA * sizeof(int));
    int *B = (int *)malloc(lengthOfA * sizeof(int));

    printf("Enter %d numbers: ", lengthOfA);
    for (int i = 0; i < lengthOfA; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < lengthOfA; i++) {
        if (A[i] < 0) {
            B[counterForB] = A[i] * A[i];
            counterForB++;
        }
    }

    printf("Negative numbers from A, squared in B: \n");
    for (int i = 0; i < counterForB; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    free(A);
    free(B);
    return 0;
}