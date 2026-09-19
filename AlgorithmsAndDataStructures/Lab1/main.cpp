#include <iostream>
#include <ctime>

#define ListSize 15
#define MaxValue 20

struct TListItem {
    int Value;
    TListItem *Next, *Prev;
};

struct TListIterator {
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

TListIterator InitIterator() {
    TListIterator r;
    r.pointer = nullptr;
    return r;
}

inline int isValid(TListIterator iterator) {
    return iterator.pointer != nullptr;
}

inline void MoveNext(TListIterator &iterator) {
    if (isValid(iterator)) { iterator.pointer = iterator.pointer->Next; }
}

inline void MovePrev(TListIterator &iterator) {
    if (isValid(iterator)) { iterator.pointer = iterator.pointer->Prev; }
}

inline int GetValue(TListIterator &iterator) {
    if (isValid(iterator)) { return iterator.pointer->Value; }
    return -1;
}

inline void SetValue(TListIterator &iterator, int value) {
    if (isValid(iterator)) { iterator.pointer->Value = value; }
}

TListIterator GetBegin(TList &List) {
    TListIterator r;
    r.pointer = List.First;
    return r;
}

TListIterator GetEnd(TList &List) {
    TListIterator r;
    r.pointer = List.Last;
    return r;
}

void InsertAfter(TList &List, const TListIterator &iterator, int value) {
    if (!isValid(iterator)) { return; }
    TListItem *t = new TListItem;
    t->Value = value;
    t->Next = iterator.pointer->Next;
    t->Prev = iterator.pointer;
    if (iterator.pointer->Next != nullptr) { iterator.pointer->Next->Prev = t; }
    iterator.pointer->Next = t;
    if (iterator.pointer == List.Last) List.Last = t;
}

void InsertBefore(TList &List, const TListIterator &iterator, int value) {
    if (!isValid(iterator)) { return; }
    TListItem *t = new TListItem;
    t->Value = value;
    t->Prev = iterator.pointer->Prev;
    t->Next = iterator.pointer;
    if (iterator.pointer->Prev != nullptr) { iterator.pointer->Prev->Next = t; }
    iterator.pointer->Prev = t;
    if (iterator.pointer == List.First) List.First = t;
}

void DeleteItem(TList &List, TListIterator &iterator) {
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

void AddListItem(TList &List, int val) {
    if (List.First == nullptr) {
        List.First = new TListItem;

        List.First->Next = nullptr;
        List.First->Prev = nullptr;
        List.First->Value = val;

        List.Last = List.First;
    }

    else {
        TListIterator iterator = GetEnd(List);
        InsertAfter(List, iterator, val);
    }
}

void DestroyList(TList &List) {
    TListIterator iterator = GetBegin(List);

    while (isValid(iterator)) {
        DeleteItem(List, iterator);
    }
}

void PrintList(TList &List) {
    TListIterator t = GetBegin(List);
    while (isValid(t)) {

        std::cout << GetValue(t) << ' ';

        MoveNext(t);
    }
}

void FillListWithNumbers(TList &List) {
    for (int i = 0; i < ListSize; i++) {
        int random_num = rand() % 10;

        AddListItem(List, random_num);
    }
}

void DeleteRepeats(TList &List) {
    TListIterator t = GetBegin(List);

    while (isValid(t)) {
        TListIterator p = t;
        MoveNext(p);

        while (isValid(p)) {

            if (GetValue(t) == GetValue(p)) {
                DeleteItem(List, p);
            }

            else{ MoveNext(p); }
        }
        MoveNext(t);
    }
}

TList Union(TList &A, TList &B) {
    TList C = InitList();

    TListIterator a = GetBegin(A);
    TListIterator b = GetBegin(B);

    while (isValid(a)) {
        AddListItem(C, GetValue(a));

        MoveNext(a);
    }

    while (isValid(b)) {
        AddListItem(C, GetValue(b));

        MoveNext(b);
    }

    DeleteRepeats(C);

    return C;
}

int main() {

    srand(time(nullptr));

    TList A = InitList();
    TList B = InitList();

    FillListWithNumbers(A);
    FillListWithNumbers(B);

    TList C = Union(A, B);

    PrintList(A);
    std::cout << '\n';

    PrintList(B);
    std::cout << '\n';

    PrintList(C);
    std::cout << '\n';

    DestroyList(A);
    DestroyList(B);
    DestroyList(C);

    return 0;
}