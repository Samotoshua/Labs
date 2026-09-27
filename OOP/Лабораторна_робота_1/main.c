#include <stdio.h>

struct TPair
{
    double first, second;
};

int check(struct TPair* ob) {
    if (( ob->first < 0 || ob->first > 100 ) || (ob->second < 0 || ob->second > 100)) {
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

        printf("Enter border for ob%d: ",i);
        scanf("%lf", &ob->second);

        isValid = check(ob);
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
    if(isDiapazon(ob1, ob2) == 0) {
        if(ob1->first > ob2->first) {
            return (ob1->first - ob1->second) - (ob2->first + ob2->second);
        }
        if(ob1->first < ob2->first) {
            return (ob2->first - ob2->second) - (ob1->first + ob1->second);
        }
    }
    return 0;
}

void output(struct TPair *ob, int i) {
    printf("======OUTPUT=====");
    printf("\n");

    printf("Ob%d (%.2lf  %.2lf  %.2lf)", i, ob->first-ob->second, ob->first, ob->first + ob->second);

    printf("\n");
}

void PrintDiapazon(int diapazon) {
    printf("\n");
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
}

void PrintDistance(double distance) {
    if(distance == 0) {
        printf("Distance is 0");
    }
    else {
        printf("Distance is %.2lf", distance);
    }
    printf("\n");
}

int main(void) {
    struct TPair ob1, ob2;

    input(&ob1,1);
    input(&ob2,2);

    output(&ob1, 1);
    output(&ob2,2);

    isDiapazon(&ob1, &ob2);
    PrintDiapazon(isDiapazon(&ob1, &ob2));

    distanceTwo(&ob1, &ob2);
    PrintDistance(distanceTwo(&ob1, &ob2));

    return 0;
}

