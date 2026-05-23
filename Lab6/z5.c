#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("input.txt", "r");
    if (!f) return 1;
    
    int n;
    fscanf(f, "%d", &n);
    
    int (*matrix)[n] = malloc(n * sizeof(*matrix));
    
    if (!matrix) {
        fclose(f);
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &matrix[i][j]);
        }
    }
    fclose(f);
    
    int sP, lP, sR = -1, lR = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = matrix[i][j];
            int isP = (num > 1);
            
            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    isP = 0;
                    break;
                }
            }
            
            if (isP) {
                if (sR == -1 || num < sP) { sP = num; sR = i; }
                if (lR == -1 || num > lP) { lP = num; lR = i; }
            }
        }
    }
    
    if (sR != -1 && lR != -1 && sR != lR) {
        for (int j = 0; j < n; j++) {
            int t = matrix[sR][j];
            matrix[sR][j] = matrix[lR][j];
            matrix[lR][j] = t;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    free(matrix);
    
    return 0;
}