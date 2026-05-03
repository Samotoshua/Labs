#include <stdio.h>
#include <math.h>

double sum(int x) {
    return (sin(x) + x) / 3.0;
}

int main() {
    int a,b,c;

    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);

    printf("S(%d) + S(2 * %d) + S(3 * %d) = %lf", a, b, c, sum(a) + sum(2 * b) + sum(3 * c));

    return 0;
}