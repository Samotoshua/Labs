
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

void InsertAfter(TList &List, const TIterator &iterator, int value) {
    if (!isValid(iterator))
        return;

    TListItem *t = new TListItem;
    t->Value = value;
    t->Next = iterator.pointer->Next;
    t->Prev = iterator.pointer;

    iterator.pointer->Next->Prev = t;
    iterator.pointer->Next = t;

    if (iterator.pointer == List.Last)
        List.Last = t;
}

void InsertBefore(TList &List, const TIterator &iterator, int value) {
    if (!isValid(iterator))
        return;

    TListItem *t = new TListItem;
    t->Value = value;
    t->Prev = iterator.pointer->Prev;
    t->Next = iterator.pointer;

    iterator.pointer->Prev->Next = t;
    iterator.pointer->Prev = t;

    if (iterator.pointer == List.First)
        List.First = t;
}

void DeleteItem(TList &List, TIterator &iterator) {
    if (!isValid(iterator))
        return;

    if (List.First == List.Last) {
        delete iterator.pointer;
        List.First = nullptr;
        List.Last = nullptr;
        iterator.pointer = nullptr;
        return;
    }

    TListItem *t1 = iterator.pointer->Prev;
    TListItem *t2 = iterator.pointer->Next;

    t1->Next = t2;
    t2->Prev = t1;

    if (iterator.pointer == List.First)
        List.First = t2;

    if (iterator.pointer == List.Last)
        List.Last = t1;

    delete iterator.pointer;
    iterator.pointer = t2;
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

    TListItem *t = List.First;

    do {
        std::cout << t->Value << ' ';
        t = t->Next;
    } while (t != List.First);
}

int ListSum(TList &List) {
    if (List.First == nullptr)
        return 0;

    int sum = 0;
    TIterator t = GetBegin(List);

    do {
        sum += GetValue(t);
        MoveNext(t);
    } while (t.pointer != List.First);

    return sum;
}

int ListDobutok(TList &List) {
    if (List.First == nullptr)
        return 0;

    int dobutok = 1;
    TIterator t = GetBegin(List);

    do {
        dobutok *= GetValue(t);
        MoveNext(t);
    } while (t.pointer != List.First);

    return dobutok;
}

int ListCount(TList &List) {
    if (List.First == nullptr)
        return 0;

    int count = 0;
    TIterator t = GetBegin(List);

    do {
        count++;
        MoveNext(t);
    } while (t.pointer != List.First);

    return count;
}

int ListEvenCount(TList &List) {
    if (List.First == nullptr)
        return 0;

    int count = 0;
    TIterator t = GetBegin(List);

    do {
        if (GetValue(t) % 2 == 0) {
            count++;
        }
        MoveNext(t);
    } while (t.pointer != List.First);

    return count;
}

int ListOddSum(TList &List) {
    if (List.First == nullptr)
        return 0;

    int sum = 0;
    TIterator t = GetBegin(List);

    do {
        if (GetValue(t) % 2 != 0) {
            sum += GetValue(t);
        }
        MoveNext(t);
    } while (t.pointer != List.First);

    return sum;
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

void printListNTimes(TList &List, int n) {
    if (List.First == nullptr)
        return;

    for (int i = 0; i < n; i++) {
        PrintList(List);
        std::cout << std::endl;
    }
}

int main() {
    TList L = InitList();

    for (int i = 0; i < ListSize; i++) {
        AddItem(L, i);
    }

    PrintList(L);
    std::cout << std::endl;

    std::cout << "ListSum = " << ListSum(L) << std::endl;
    std::cout << "ListDobutok = " << ListDobutok(L) << std::endl;
    std::cout << "ListCount = " << ListCount(L) << std::endl;
    std::cout << "ListEvenCount = " << ListEvenCount(L) << std::endl;
    std::cout << "ListOddSum = " << ListOddSum(L) << std::endl;

    printListNTimes(L, 3);
    std::cout << std::endl;

    TIterator it = GetBegin(L);

    InsertAfter(L, it, 100);
    InsertBefore(L, it, 200);

    std::cout << "After insertion: ";
    PrintList(L);
    std::cout << std::endl;

    DeleteItem(L, it);

    std::cout << "After deletion: ";
    PrintList(L);
    std::cout << std::endl;

    TIterator last = GetEnd(L);
    MoveNext(last);

    std::cout << "First via MoveNext: "
              << GetValue(last) << std::endl;

    TIterator first = GetBegin(L);
    MovePrev(first);

    std::cout << "Last via MovePrev: "
              << GetValue(first) << std::endl;

    DestroyList(L);

    TList Single = InitList();
    AddItem(Single, 5);

    TIterator one = GetBegin(Single);
    DeleteItem(Single, one);

    std::cout << "Single after deletion: "
              << ListCount(Single) << std::endl;

    DestroyList(Single);

    return 0;
}
