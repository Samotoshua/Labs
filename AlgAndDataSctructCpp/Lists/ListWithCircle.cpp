//Кільцевий двозв'язний список
#include <iostream>

#define ListSize 15
#define MaxValue 20

struct TListItem {
    int Value;
    TListItem *Next, *Prev;
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
    TListItem *t = List.First;

    do {
        sum += t->Value;
        t = t->Next;
    } while (t != List.First);

    return sum;
}

int ListDobutok(TList &List) {
    if (List.First == nullptr)
        return 0;

    int dobutok = 1;
    TListItem *t = List.First;

    do {
        dobutok *= t->Value;
        t = t->Next;
    } while (t != List.First);

    return dobutok;
}

int ListCount(TList &List) {
    if (List.First == nullptr)
        return 0;

    int count = 0;
    TListItem *t = List.First;

    do {
        count++;
        t = t->Next;
    } while (t != List.First);

    return count;
}

int ListEvenCount(TList &List) {
    if (List.First == nullptr)
        return 0;

    int count = 0;
    TListItem *t = List.First;

    do {
        if (t->Value % 2 == 0) {
            count++;
        }

        t = t->Next;
    } while (t != List.First);

    return count;
}

int ListOddSum(TList &List) {
    if (List.First == nullptr)
        return 0;

    int sum = 0;
    TListItem *t = List.First;

    do {
        if (t->Value % 2 != 0) {
            sum += t->Value;
        }

        t = t->Next;
    } while (t != List.First);

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

int main() {
    TList L;
    L = InitList();

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

    DestroyList(L);

    return 0;
}