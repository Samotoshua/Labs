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
    TStack *temp = nullptr;

    while (!isEmpty(s)) {
        int value = Pop(s);
        std::cout << value << ' ';
        Push(temp, value);
    }

    while (!isEmpty(temp)) {
        Push(s, Pop(temp));
    }
}

int StackSum(TStack *&s) {
    TStack *temp = nullptr;
    int sum = 0;

    while (!isEmpty(s)) {
        int value = Pop(s);
        sum += value;
        Push(temp, value);
    }

    while (!isEmpty(temp)) {
        Push(s, Pop(temp));
    }

    return sum;
}

int StackDobutok(TStack *&s) {
    TStack *temp = nullptr;
    int dobutok = 1;

    while (!isEmpty(s)) {
        int value = Pop(s);
        dobutok *= value;
        Push(temp, value);
    }

    while (!isEmpty(temp)) {
        Push(s, Pop(temp));
    }

    return dobutok;
}

int StackCount(TStack *&s) {
    TStack *temp = nullptr;
    int count = 0;

    while (!isEmpty(s)) {
        int value = Pop(s);
        count++;
        Push(temp, value);
    }

    while (!isEmpty(temp)) {
        Push(s, Pop(temp));
    }

    return count;
}

int StackEvenCount(TStack *&s) {
    TStack *temp = nullptr;
    int count = 0;

    while (!isEmpty(s)) {
        int value = Pop(s);
        if (value % 2 == 0) { count++; }
        Push(temp, value);
    }

    while (!isEmpty(temp)) {
        Push(s, Pop(temp));
    }

    return count;
}

int StackOddSum(TStack *&s) {
    TStack *temp = nullptr;
    int sum = 0;

    while (!isEmpty(s)) {
        int value = Pop(s);
        if (value % 2 != 0) { sum += value; }
        Push(temp, value);
    }

    while (!isEmpty(temp)) {
        Push(s, Pop(temp));
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

    std::cout << "StackSum = " << StackSum(s) << std::endl;

    std::cout << "StackDobutok = " << StackDobutok(s) << std::endl;

    std::cout << "StackCount = " << StackCount(s) << std::endl;

    std::cout << "StackEvenCount = " << StackEvenCount(s) << std::endl;

    std::cout << "StackOddSum = " << StackOddSum(s) << std::endl;

    DestroyStack(s);
    if (isEmpty(s)) { std::cout << "Stack is empty" << std::endl; }

    return 0;
}