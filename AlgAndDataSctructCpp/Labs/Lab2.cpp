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
    int sum = 0;
    int count = 0;

    if (List.First == nullptr)
        return -1;

    TListItem *t = List.First;
    TListItem *p = t->Next;
    TListItem *prev = List.Last;

    do {
        if (prev->Value > p->Value) {
            sum += t->Value;
            count++;
        }

        prev = t;
        t = t->Next;
        p = p->Next;

    } while (t != List.First);

    if (count == 0)
        return -1;

    return (double)sum / count;
}


int main() {
    TList L;
    L = InitList();

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