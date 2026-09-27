#include <iostream>
 
 
struct TPair
{
    double first, second;
 
    int check();
    void input(int i);
    void output(int i);
    void PrintDiapazon(int diapazon);
    void PrintDistance(double distance);
};
 
int TPair::check() {
    if (( first < 0 || first > 100 ) || (second < 0 || second > 100)) {
        std::cout << "Invalid input!" << std::endl;
        std::cout << "Number must be greater than 0 and less than 100." << std::endl;
        std::cout << "Please try again." << std::endl;
        std::cout << std::endl;
        return 0;
    }
    return 1;
}
 
void TPair::input(int i) {
    std::cout << "=====INPUT=====";
    std::cout << std::endl;
 
        std::cout << "Enter number for ob" << i << ": ";
        std::cin >> first;
 
        std::cout << "Enter border for ob" << i << ": ";
        std::cin >> second;
 
    std::cout << std::endl;
}
 
int isDiapazon(TPair &ob1, TPair &ob2) {
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
 
double distanceTwo(TPair &ob1, TPair &ob2) {
    if (ob1.first + ob1.second < ob2.first - ob2.second) {
        return (ob2.first - ob2.second) - (ob1.first + ob1.second);
    }
 
    if (ob2.first + ob2.second < ob1.first - ob1.second) {
        return (ob1.first - ob1.second) - (ob2.first + ob2.second);
    }
 
    return 0;
}
 
void TPair::output(int i) {
    std::cout << "======OUTPUT=====" << std::endl;
 
    std::cout << "Ob" << i << " " << "(" << first-second << " " << first <<  " " << first + second << ")" << std::endl;
}
 
void TPair::PrintDiapazon(int diapazon) {
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
 
void TPair::PrintDistance(double distance) {
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
 
    do {
        ob1.input(1);
    }while(!ob1.check());
 
    do {
        ob2.input(2);
    }while(!ob2.check());
 
    ob1.output(1);
    ob2.output(2);
 
    ob1.PrintDiapazon(isDiapazon(ob1, ob2));
 
    ob1.PrintDistance(distanceTwo(ob1, ob2));
 
    return 0;
}
