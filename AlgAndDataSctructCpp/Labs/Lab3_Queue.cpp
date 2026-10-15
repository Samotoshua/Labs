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
    if (Q.Head == nullptr)
        throw std::logic_error("Not enough queue elements");

    TQueue Q2 = InitQueue();

    int prev = DeQueue(Q);
    int temp = DeQueue(Q);
    int next = DeQueue(Q);

    EnQueue(Q2, prev);
    while (!isEmpty(Q)) {
        if (prev != next) {
            EnQueue(Q2, temp);
        }
        prev = temp;
        temp = next;
        next = DeQueue(Q);
    }
    EnQueue(Q2, temp);

    return Q2;
}

int main() {
    srand(time(nullptr));

    TQueue Q;
    Q = InitQueue();
    fillQueue(Q);

    std::cout << "Queue: ";
    PrintQueue(Q);
    std::cout << std::endl;


    int var;
    do {
        std::cin >> var;
        EnQueue(Q, var);
    }while (var != -1);
    TQueue Q2 = noSimilarNeighbours(Q);

    PrintQueue(Q2);

    DestroyQueue(Q);
    if (isEmpty(Q)) { std::cout << "Queue is empty" << std::endl; }

    return 0;
}