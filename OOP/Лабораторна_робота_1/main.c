#include <stdio.h>

struct TPair
{
    double first, second;
};

int check(double n) {
    if (n < 0 || n > 100) {
        printf("Invalid input!\n");
        printf("Number must be greater than 0 and less than 100.\n");
        printf("Please try again.\n");
        printf("\n");
        return 0;
    }
    return 1;
}

void input(struct TPair* ob, int i) {
    int isValid;
    printf("=====INPUT=====");
    printf("\n");
    do {
        printf("Enter number for ob%d: ",i);
        scanf("%lf", &ob->first);

        isValid = check(ob->first);
    }while (!isValid);

    do {
        printf("Enter border for ob%d: ",i);
        scanf("%lf", &ob->second);

        isValid = check(ob->second);
    } while (!isValid);

    printf("\n");
}

int isDiapazon(struct TPair* ob1, struct TPair* ob2) {
    if ((ob2->first > ob1->first - ob1->second && ob2->first < ob1->first + ob1->second) && (ob1->first > ob2->first - ob2->second && ob1->first < ob2->first + ob2->second)) {
        return 3;
    }
    if (ob2->first > ob1->first - ob1->second && ob2->first < ob1->first + ob1->second) {
        return 2;
    }
    if (ob1->first > ob2->first - ob2->second && ob1->first < ob2->first + ob2->second) {
        return 1;
    }
    return 0;
}

double distanceTwo(struct TPair* ob1, struct TPair* ob2) {
    double ob1Limits[2] = {
        ob1->first - ob1->second,
        ob1->first + ob1->second
    };

    double ob2Limits[2] = {
        ob2->first - ob2->second,
        ob2->first + ob2->second
    };

    double min = ob1Limits[0] - ob2Limits[0];
    if (min < 0)
        min = -min;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            double d = ob1Limits[i] - ob2Limits[j];

            if (d < 0)
                d = -d;

            if (d < min)
                min = d;
        }
    }

    return min;
}

void output(struct TPair *ob1, struct TPair *ob2) {
    printf("======OUTPUT=====");
    printf("\n");

    int diapazon = isDiapazon(ob1, ob2);

    if (diapazon == 2) {
        printf("Ob1 contains Ob2s number");
    }
    else if (diapazon == 1) {
        printf("Ob2 contains Ob1s number");
    }
    else if (diapazon == 3) {
        printf("Ob1 and Ob2 contain each other");
    }
    else { printf("No one contain each other"); }

    printf("\n");
    printf("Minimal distance between ob1 and ob2 is: %.2lf", distanceTwo(ob1, ob2));

    printf("\n");
    printf("=====END=====");
    printf("\n");
}

int main(void) {
    struct TPair ob1, ob2;

    input(&ob1,1);
    input(&ob2,2);

    output(&ob1, &ob2);

    return 0;
}
