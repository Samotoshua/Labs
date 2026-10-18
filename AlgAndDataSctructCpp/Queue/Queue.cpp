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
    for (int i = 0; i < QueueSize; i++) {
        int value = DeQueue(Q);
        std::cout << value << ' ';
        EnQueue(Q, value);
    }
}

int QueueSum(TQueue &Q) {
    int sum = 0;

    for (int i = 0; i < QueueSize; i++) {
        int value = DeQueue(Q);
        sum += value;
        EnQueue(Q, value);
    }

    return sum;
}

int QueueDobutok(TQueue &Q) {
    int dobutok = 1;

    for (int i = 0; i < QueueSize; i++) {
        int value = DeQueue(Q);
        dobutok *= value;
        EnQueue(Q, value);
    }

    return dobutok;
}

int QueueCount(TQueue &Q) {
    int count = 0;

    for (int i = 0; i < QueueSize; i++) {
        int value = DeQueue(Q);
        count++;
        EnQueue(Q, value);
    }

    return count;
}

int QueueEvenCount(TQueue &Q) {
    int count = 0;

    for (int i = 0; i < QueueSize; i++) {
        int value = DeQueue(Q);
        if (value % 2 == 0) { count++; }
        EnQueue(Q, value);
    }

    return count;
}

int QueueOddSum(TQueue &Q) {
    int sum = 0;

    for (int i = 0; i < QueueSize; i++) {
        int value = DeQueue(Q);
        if (value % 2 != 0) { sum += value; }
        EnQueue(Q, value);
    }

    return sum;
}

int main() {
    srand(time(nullptr));

    TQueue Q = InitQueue();

    fillQueue(Q);

    std::cout << "Queue: ";
    PrintQueue(Q);
    std::cout << std::endl;

    std::cout << "QueueSum = " << QueueSum(Q) << std::endl;

    std::cout << "QueueDobutok = " << QueueDobutok(Q) << std::endl;

    std::cout << "QueueCount = " << QueueCount(Q) << std::endl;

    std::cout << "QueueEvenCount = " << QueueEvenCount(Q) << std::endl;

    std::cout << "QueueOddSum = " << QueueOddSum(Q) << std::endl;

    DestroyQueue(Q);

    if (isEmpty(Q)) {
        std::cout << "Queue is empty" << std::endl;
    }

    return 0;
}