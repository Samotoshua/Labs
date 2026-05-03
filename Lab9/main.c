#include <stdio.h>
#include <stdlib.h>

struct Polinom {
  int degree;
  double* coefficients;
};

int main() {
  int n;
  printf("Enter a number of polinoms: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Incorrect number of polinoms\n");
    return 1;
  }

  struct Polinom* polinoms = malloc(n * sizeof(struct Polinom));
  if (polinoms == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  int max_degree = 0;
  for (int i = 0; i < n; i++) {
    printf("Enter degree of polinom %d: ", i + 1);
    if (scanf("%d", &polinoms[i].degree) != 1 || polinoms[i].degree < 0) {
      printf("Incorrect degree of polinom\n");
      free(polinoms);
      return 1;
    }
    if (polinoms[i].degree > max_degree) {
      max_degree = polinoms[i].degree;
    }

    polinoms[i].coefficients =
        malloc((polinoms[i].degree + 1) * sizeof(double));
    if (polinoms[i].coefficients == NULL) {
      printf("Memory allocation failed\n");
      for (int k = 0; k < i; k++) {
        free(polinoms[k].coefficients);
      }
      free(polinoms);
      return 1;
    }

    printf("Enter %d coefficients: ", polinoms[i].degree + 1);
    for (int j = 0; j <= polinoms[i].degree; j++) {
      scanf("%lf", &polinoms[i].coefficients[j]);
    }
  }

  double* result = calloc(max_degree + 1, sizeof(double));
  if (result == NULL) {
    printf("Memory allocation failed\n");
    for (int i = 0; i < n; i++) free(polinoms[i].coefficients);
    free(polinoms);
    return 1;
  }

  for (int i = 0; i < n; i++) {
    int shift = max_degree - polinoms[i].degree;
    for (int j = 0; j <= polinoms[i].degree; j++) {
      result[j + shift] += polinoms[i].coefficients[j];
    }
  }

  printf("Sum of polinoms: ");
  for (int j = 0; j <= max_degree; j++) {
    int power = max_degree - j;
    if (result[j] != 0) {
      printf("%.2lf", result[j]);
      if (power > 0) printf("x^%d", power);
      if (j < max_degree) printf(" + ");
    }
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    free(polinoms[i].coefficients);
  }
  free(polinoms);
  free(result);

  return 0;
}
