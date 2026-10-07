#include <iostream>
#include <ctime>

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
    if (isValid(iterator)) { iterator.pointer = iterator.pointer->Next; }
}

inline void MovePrev(TIterator &iterator) {
    if (isValid(iterator)) { iterator.pointer = iterator.pointer->Prev; }
}

inline int GetValue(TIterator &iterator) {
    if (isValid(iterator)) { return iterator.pointer->Value; }
    return -1;
}

inline void SetValue(TIterator &iterator, int value) {
    if (isValid(iterator)) { iterator.pointer->Value = value; }
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

void InsertAfter(TList &List, const TIterator &iterator, int value) {
    if (!isValid(iterator)) { return; }
    TListItem *t = new TListItem;
    t->Value = value;
    t->Next = iterator.pointer->Next;
    t->Prev = iterator.pointer;
    if (iterator.pointer->Next != nullptr) { iterator.pointer->Next->Prev = t; }
    iterator.pointer->Next = t;
    if (iterator.pointer == List.Last) List.Last = t;
}

void InsertBefore(TList &List, const TIterator &iterator, int value) {
    if (!isValid(iterator)) { return; }
    TListItem *t = new TListItem;
    t->Value = value;
    t->Prev = iterator.pointer->Prev;
    t->Next = iterator.pointer;
    if (iterator.pointer->Prev != nullptr) { iterator.pointer->Prev->Next = t; }
    iterator.pointer->Prev = t;
    if (iterator.pointer == List.First) List.First = t;
}

void DeleteItem(TList &List, TIterator &iterator) {
    if (!isValid(iterator)) { return; }
    if (iterator.pointer == List.First) { List.First = iterator.pointer->Next; }
    if (iterator.pointer == List.Last) { List.Last = iterator.pointer->Prev; }
    TListItem *t1 = iterator.pointer->Prev;
    TListItem *t2 = iterator.pointer->Next;
    delete iterator.pointer;
    iterator.pointer = t2;
    if (t2 != nullptr) { t2->Prev = t1; }
    if (t1 != nullptr) { t1->Next = t2; }
    if (List.First == nullptr) List.Last = nullptr;
    if (List.Last == nullptr) { List.First = nullptr; }
}

void AddItem(TList &List, int val) {
    if (List.First == nullptr) {
        List.First = new TListItem;

        List.First->Next = nullptr;
        List.First->Prev = nullptr;
        List.First->Value = val;

        List.Last = List.First;
    }

    else {
        List.Last->Next = new TListItem;

        List.Last->Next->Prev = List.Last;
        List.Last->Next->Next = nullptr;
        List.Last->Next->Value = val;

        List.Last = List.Last->Next;
    }
}

void DestroyList(TList &List) {
    TListItem *t = List.First;
    TListItem *r;

    while (t != nullptr) {

        r = t->Next;

        delete t;

        t = r;
    }

    List.First = nullptr;
    List.Last = nullptr;
}

void Print(const TList &List) {
    TListItem *t = List.First;
    while (t != nullptr) {

        std::cout << t->Value << " ";

        t = t->Next;
    }
}
void FillWithNumbers(TList &List) {
    for (int i = 0; i < ListSize; i++) {
        int random_num = rand() % 10;

        AddItem(List, random_num);
    }
}

int main() {

    srand(time(nullptr));

    TList A = InitList();
    TList B = InitList();

    FillWithNumbers(A);
    FillWithNumbers(B);

    Print(A);
    std::cout << '\n';

    Print(B);
    std::cout << '\n';

    DestroyList(A);
    DestroyList(B);

    return 0;
}