
#include <iostream>

#define ListSize 15
#define MaxValue 20

struct TListItem {
    int Value;
    TListItem *Next, *Prev;
};

struct TIterator {
    TListItem *pointer;
};

struct TList {
    TListItem *First, *Last;
};

TList InitList() {
    TList r;
    r.First = nullptr;
    r.Last = nullptr;
    return r;
}

TIterator InitIterator() {
    TIterator r;
    r.pointer = nullptr;
    return r;
}

inline int isValid(TIterator iterator) {
    return iterator.pointer != nullptr;
}

inline void MoveNext(TIterator &iterator) {
    if (isValid(iterator)) {
        iterator.pointer = iterator.pointer->Next;
    }
}

inline void MovePrev(TIterator &iterator) {
    if (isValid(iterator)) {
        iterator.pointer = iterator.pointer->Prev;
    }
}

inline int GetValue(TIterator &iterator) {
    if (isValid(iterator)) {
        return iterator.pointer->Value;
    }
    return -1;
}

inline void SetValue(TIterator &iterator, int value) {
    if (isValid(iterator)) {
        iterator.pointer->Value = value;
    }
}

TIterator GetBegin(TList &List) {
    TIterator r;
    r.pointer = List.First;
    return r;
}

TIterator GetEnd(TList &List) {
    TIterator r;
    r.pointer = List.Last;
    return r;
}

void AddItem(TList &List, const int val) {
    if (List.First == nullptr) {
        List.First = new TListItem;
        List.First->Value = val;
        List.First->Next = List.First;
        List.First->Prev = List.First;

        List.Last = List.First;
    }
    else {
        TListItem *t = new TListItem;

        t->Value = val;
        t->Prev = List.Last;
        t->Next = List.First;

        List.Last->Next = t;
        List.First->Prev = t;

        List.Last = t;
    }
}

void PrintList(TList &List) {
    if (List.First == nullptr)
        return;

    TIterator t = GetBegin(List);

    do {
        std::cout << GetValue(t) << ' ';
        MoveNext(t);
    } while (t.pointer != List.First);
}

void DestroyList(TList &List) {
    if (List.First == nullptr)
        return;

    TListItem *t = List.First->Next;

    while (t != List.First) {
        TListItem *r = t->Next;
        delete t;
        t = r;
    }

    delete List.First;

    List.First = nullptr;
    List.Last = nullptr;
}

double averageArithmetic(TList &List) {
    if (List.First == nullptr)
        return -1;

    int sum = 0;
    int count = 0;

    TIterator t = GetBegin(List);
    TIterator p = GetBegin(List);
    TIterator prev = GetEnd(List);

    MoveNext(p);

    do {
        if (GetValue(prev) > GetValue(p)) {
            sum += GetValue(t);
            count++;
        }

        MoveNext(prev);
        MoveNext(t);
        MoveNext(p);

    } while (t.pointer != List.First);

    if (count == 0)
        return -1;

    return (double)sum / count;
}

int main() {
    TList L = InitList();

    for (int i = 0; i < ListSize; i++) {
        int t;
        std::cin >> t;
        AddItem(L, t);
    }

    PrintList(L);
    std::cout << std::endl;

    std::cout << averageArithmetic(L) << std::endl;

    DestroyList(L);

    return 0;
}
