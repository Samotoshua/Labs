#include <iostream>
#include <cstdlib>
#include <ctime>

#define QueueSize 15
#define MaxValue 20

struct TQueueItem {
    int Value;
    TQueueItem *Next, *Prev;
};

struct TQueue {
    TQueueItem *Head, *Tail;
};

TQueue InitQueue() {
    TQueue Q;
    Q.Head = Q.Tail = nullptr;
    return Q;
}

inline int isEmpty(const TQueue Q) { return Q.Head == nullptr; }

void EnQueue(TQueue &Q, int Value) {
    if (!Q.Tail) {
        Q.Head = new TQueueItem;
        Q.Head->Value = Value;
        Q.Head->Next = Q.Head->Prev = nullptr;
        Q.Tail = Q.Head;
    }
    else {
        Q.Tail->Next = new TQueueItem;
        Q.Tail->Next->Value = Value;
        Q.Tail->Next->Next = nullptr;
        Q.Tail->Next->Prev = Q.Tail;
        Q.Tail = Q.Tail->Next;
    }
}

int DeQueue(TQueue &Q) {
    if (isEmpty(Q)) { return 0; }
    int result = Q.Head->Value;
    TQueueItem *temp = Q.Head;
    Q.Head = Q.Head->Next;
    delete temp;
    if (Q.Head) Q.Head->Prev = nullptr;
    else Q.Tail = nullptr;
    return result;
}

void DestroyQueue(TQueue &Q) {
    TQueueItem *temp = Q.Head, *r;
    while (temp != nullptr) {
        r = temp->Next;
        delete temp;
        temp = r;
    }
    Q.Head = Q.Tail = nullptr;
}

void fillQueue(TQueue &Q){
    for (int i = 0; i < QueueSize; i++) {
        EnQueue(Q, i); //rand() % MaxValue
    }
}

void PrintQueue(TQueue &Q) {
    while (!isEmpty(Q)) {
        std::cout << DeQueue(Q) << ' ';
    }
}

int QueueSum(TQueue &Q) {
    int sum = 0;
    while (!isEmpty(Q)) {
        sum +=DeQueue(Q);
    }
    return sum;
}

int QueueDobutok(TQueue &Q) {
    int dobutok = 1;
    while (!isEmpty(Q)) {
        dobutok *=DeQueue(Q);
    }

    return dobutok;
}

int QueueCount(TQueue &Q) {

    int count = 0;
    while (!isEmpty(Q)) {
        DeQueue(Q);
        count++;
    }

    return count;
}

int QueueEvenCount(TQueue &Q) {

    int count = 0;

    while (!isEmpty(Q)) {
        if (DeQueue(Q) % 2 == 0) { count++; }
    }

    return count;
}

int QueueOddSum(TQueue &Q) {
    int sum = 0;

    while (!isEmpty(Q)) {
        if (DeQueue(Q) % 2 != 0) { sum += DeQueue(Q); }
    }

    return sum;
}

int main() {
    srand(time(nullptr));

    TQueue Q;
    Q = InitQueue();

    fillQueue(Q);

    std::cout << "Queue: ";
    while (!isEmpty(Q)) { std::cout<< DeQueue(Q) << " ";}
    std::cout << std::endl;

    fillQueue(Q);
    PrintQueue(Q);
    std::cout << std::endl;

    fillQueue(Q);
    std::cout << "QueueSum = " << QueueSum(Q) << std::endl;

    fillQueue(Q);
    std::cout << "QueueDobutok = " << QueueDobutok(Q) << std::endl;

    fillQueue(Q);
    std::cout << "QueueCount = " << QueueCount(Q) << std::endl;

    fillQueue(Q);
    std::cout << "QueueEvenCount = " << QueueEvenCount(Q) << std::endl;

    fillQueue(Q);
    std::cout << "QueueOddSum = " << QueueOddSum(Q) << std::endl;

    fillQueue(Q);

    DestroyQueue(Q);
    if (isEmpty(Q)) { std::cout << "Queue is empty" << std::endl; }

    return 0;
}