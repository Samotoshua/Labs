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

TQueue noSimilarNeighbours(TQueue &Q) {
    if (isEmpty(Q))
        throw std::logic_error("Not enough queue elements");

    TQueue Q2 = InitQueue();

    int prev = DeQueue(Q);
    if (isEmpty(Q)) { EnQueue(Q2, prev); return Q2; }

    int temp = DeQueue(Q);
    if (isEmpty(Q)) {
        EnQueue(Q2, prev);
        EnQueue(Q2, temp);
        return Q2;
    }

    int next = DeQueue(Q);

    EnQueue(Q2, prev);
    while (!isEmpty(Q)) {
        if (prev != next) { EnQueue(Q2, temp); }
        prev = temp;
        temp = next;
        next = DeQueue(Q);
    }

    if (prev != next) { EnQueue(Q2, temp); }
    EnQueue(Q2, next);

    return Q2;
}

int main() {
    srand(time(nullptr));

    TQueue Q;
    Q = InitQueue();

    std::cout << "Enter elements (-1 to stop): ";

    int var;
    do {
        std::cin >> var;
        if (var != -1) EnQueue(Q, var);
    } while (var != -1);
    TQueue Q2 = noSimilarNeighbours(Q);

    std::cout << "New queue: ";
    PrintQueue(Q2);
    std::cout << std::endl;

    DestroyQueue(Q);
    DestroyQueue(Q2);
    if (isEmpty(Q)) { std::cout << "Queue is empty" << std::endl; }

    return 0;
}