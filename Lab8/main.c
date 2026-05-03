#include <stdio.h>

int func(int x, int i) {
    if (x % i == 0) {
        printf("%d : %d = %d\n", x, i, x / i);
    }

    return x != i ? func(x, i + 1) : 0;
}

int main() {
    int k;

    do {
        printf("Enter the k (k > 0): \n");
        scanf("%d", &k);
    }while(k <= 0);

    func(k, 1);

    return 0;
}