#include <iostream>


struct TPair
{
    double first, second;
};

int check(TPair &ob) {
    if (( ob.first < 0 || ob.first > 100 ) || (ob.second < 0 || ob.second > 100)) {
        std::cout << "Invalid input!\n";
        std::cout << "Number must be greater than 0 and less than 100.\n";
        std::cout << "Please try again.\n";
        std::cout << std::endl;
        return 0;
    }
    return 1;
}

void input(TPair &ob, int i) {
    int isValid;
    std::cout << "=====INPUT=====";
    std::cout << std::endl;
    do {
        std::cout << "Enter number for ob" << i << ": ";
        std::cin >> ob.first;

        std::cout << "Enter border for ob" << i << ": ";
        std::cin >> ob.second;

        isValid = check(ob);
    } while (!isValid);

    std::cout << std::endl;
}

int isDiapazon(TPair &ob1,  TPair &ob2) {
    if ((ob2.first > ob1.first - ob1.second && ob2.first < ob1.first + ob1.second) && (ob1.first > ob2.first - ob2.second && ob1.first < ob2.first + ob2.second)) {
        return 3;
    }
    if (ob2.first > ob1.first - ob1.second && ob2.first < ob1.first + ob1.second) {
        return 2;
    }
    if (ob1.first > ob2.first - ob2.second && ob1.first < ob2.first + ob2.second) {
        return 1;
    }
    return 0;
}

double distanceTwo(TPair &ob1,  TPair &ob2) {
    if (ob1.first + ob1.second < ob2.first - ob2.second) {
        return (ob2.first - ob2.second) - (ob1.first + ob1.second);
    }

    if (ob2.first + ob2.second < ob1.first - ob1.second) {
        return (ob1.first - ob1.second) - (ob2.first + ob2.second);
    }

    return 0;
}

void output(TPair &ob, int i) {
    std::cout << "======OUTPUT=====";
    std::cout << std::endl;

    std::cout << "Ob" << i << " " << "(" << ob.first-ob.second << " " << ob.first <<  " " << ob.first + ob.second << ")";

    std::cout << std::endl;
}

void PrintDiapazon(int diapazon) {
    std:: cout << std::endl;
    if (diapazon == 2) {
        std::cout << "Ob1 contains Ob2s number";
    }
    else if (diapazon == 1) {
        std::cout << "Ob2 contains Ob1s number";
    }
    else if (diapazon == 3) {
        std::cout << "Ob1 and Ob2 contain each other";
    }
    else { std::cout << "No one contain each other"; }
    std::cout << std::endl;
}

void PrintDistance(double distance) {
    if(distance == 0) {
        std::cout << "Distance is 0";
    }
    else {
        std::cout << "Distance is " <<  distance;
    }
    std::cout << std::endl;
}


int main() {
    TPair ob1, ob2;

    input(ob1,1);
    input(ob2,2);

    output(ob1, 1);
    output(ob2,2);

    PrintDiapazon(isDiapazon(ob1, ob2));

    PrintDistance(distanceTwo(ob1, ob2));

    return 0;
}