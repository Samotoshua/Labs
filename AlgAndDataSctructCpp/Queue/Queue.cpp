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
    TQueue temp = InitQueue();

    while (!isEmpty(Q)) {
        int value = DeQueue(Q);
        std::cout << value << ' ';
        EnQueue(temp, value);
    }

    while (!isEmpty(temp)) {
        EnQueue(Q, DeQueue(temp));
    }
}

int QueueSum(TQueue &Q) {
    TQueue temp = InitQueue();
    int sum = 0;

    while (!isEmpty(Q)) {
        int value = DeQueue(Q);
        sum += value;
        EnQueue(temp, value);
    }

    while (!isEmpty(temp)) {
        EnQueue(Q, DeQueue(temp));
    }

    return sum;
}

int QueueDobutok(TQueue &Q) {
    TQueue temp = InitQueue();
    int dobutok = 1;

    while (!isEmpty(Q)) {
        int value = DeQueue(Q);
        dobutok *= value;
        EnQueue(temp, value);
    }

    while (!isEmpty(temp)) {
        EnQueue(Q, DeQueue(temp));
    }

    return dobutok;
}

int QueueCount(TQueue &Q) {
    TQueue temp = InitQueue();
    int count = 0;

    while (!isEmpty(Q)) {
        int value = DeQueue(Q);
        count++;
        EnQueue(temp, value);
    }

    while (!isEmpty(temp)) {
        EnQueue(Q, DeQueue(temp));
    }

    return count;
}

int QueueEvenCount(TQueue &Q) {
    TQueue temp = InitQueue();
    int count = 0;

    while (!isEmpty(Q)) {
        int value = DeQueue(Q);
        if (value % 2 == 0) { count++; }
        EnQueue(temp, value);
    }

    while (!isEmpty(temp)) {
        EnQueue(Q, DeQueue(temp));
    }

    return count;
}

int QueueOddSum(TQueue &Q) {
    TQueue temp = InitQueue();
    int sum = 0;

    while (!isEmpty(Q)) {
        int value = DeQueue(Q);
        if (value % 2 != 0) { sum += value; }
        EnQueue(temp, value);
    }

    while (!isEmpty(temp)) {
        EnQueue(Q, DeQueue(temp));
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