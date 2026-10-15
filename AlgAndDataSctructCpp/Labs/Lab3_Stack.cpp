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

int timesInQueue(TStack *&s, auto value) {
    int count = 0;
    while (!isEmpty(s)) {
        if (Pop(s) == value) {
            count++;
        }
    }

    return count;
}

int main() {
    using namespace std;

    srand(time(nullptr));

    TStack *s = nullptr;
    fillStack(s);

    cout << "Stack: ";
    PrintStack(s);
    cout << std::endl;

    char var;
    do {
        std::cin >> var;
        Push(s, var);
    }while (var != 'q');
    cout << timesInQueue(s, 'w');
    cout << std::endl;

    DestroyStack(s);
    if (isEmpty(s)) { cout << "Stack is empty" << std::endl; }

    return 0;
}