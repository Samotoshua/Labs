#include <iostream>
#include <cstdlib>
#include <ctime>

#define StackSize 15
#define MaxValue 20

struct TStack {
    int value;
    TStack *next;
};

inline int isEmpty(const TStack *s) { return s == nullptr; }

void Push(TStack *&s, int value) {
    if (!s) {
        s = new TStack;
        s->value = value;
        s->next = nullptr;
    }
    else {
        TStack *t = s;
        s = new TStack;
        s->value = value;
        s->next = t;
    }
}

int Pop(TStack *&s) {
    if (isEmpty(s)) { return 0; }
    int result = s->value;
    TStack *t = s->next;
    delete s;
    s = t;
    return result;
}

void DestroyStack(TStack *&s) {
    while (s != nullptr) {
        TStack *t = s->next;
        delete s;
        s = t;
    }
}

void fillStack(TStack *&s){
    for (int i = 0; i < StackSize; i++) {
        Push(s, i); //rand() % MaxValue
    }
}

void PrintStack(TStack *&s) {
    while (!isEmpty(s)) {
        std::cout << Pop(s) << ' ';
    }
}

int StackSum(TStack *&s) {
    int sum = 0;
    while (!isEmpty(s)) {
        sum +=Pop(s);
    }
    return sum;
}

int StackDobutok(TStack *&s) {
    int dobutok = 1;
    while (!isEmpty(s)) {
        dobutok *=Pop(s);
    }

    return dobutok;
}

int StackCount(TStack *&s) {

    int count = 0;
    while (!isEmpty(s)) {
        Pop(s);
        count++;
    }

    return count;
}

int StackEvenCount(TStack *&s) {

    int count = 0;

    while (!isEmpty(s)) {
        if (Pop(s) % 2 == 0) { count++; }
    }

    return count;
}

int StackOddSum(TStack *&s) {
    int sum = 0;

    while (!isEmpty(s)) {
        if (Pop(s) % 2 != 0) { sum += Pop(s); }
    }

    return sum;
}


int main() {
    srand(time(nullptr));

    TStack *s = nullptr;

    fillStack(s);

    std::cout << "Stack: ";
    while (!isEmpty(s)) { std::cout<< Pop(s) << " ";}
    std::cout << std::endl;

    fillStack(s);
    PrintStack(s);
    std::cout << std::endl;

    fillStack(s);
    std::cout << "StackSum = " << StackSum(s) << std::endl;

    fillStack(s);
    std::cout << "StackDobutok = " << StackDobutok(s) << std::endl;

    fillStack(s);
    std::cout << "StackCount = " << StackCount(s) << std::endl;

    fillStack(s);
    std::cout << "StackEvenCount = " << StackEvenCount(s) << std::endl;

    fillStack(s);
    std::cout << "StackOddSum = " << StackOddSum(s) << std::endl;

    fillStack(s);

    DestroyStack(s);
    if (isEmpty(s)) { std::cout << "Stack is empty" << std::endl; }

    return 0;
}