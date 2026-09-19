//Двозв'язний список !!!
#include <iostream>

#define ListSize 15
#define MaxValue 20

struct TListItem {
    int Value;
    TListItem *Prev;
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

void AddListItem(TList &List, const int val) {
    if (List.First == nullptr) {
        List.First = new TListItem;
        List.First->Prev = nullptr;
        List.First->Value = val;
        List.Last = List.First;
    }
    else {
        List.Last->Prev = new TListItem;
        List.Last->Prev->Prev = nullptr;
        List.Last->Prev->Value = val;
        List.Last = List.Last->Prev;
    }
}

void DestroyList(TList &List) {
    TListItem *t = List.First, *r;
    while (t != nullptr) {
        r = t->Prev;
        delete t;
        t = r;
    }
    List.First = List.Last = nullptr;
}

void PrintList(TList &List) {
    TListItem *t = List.First;
    while (t != nullptr) {
        std::cout << t->Value << ' ';
        t = t->Prev;
    }
}

int ListSum(TList &List) {
    int sum = 0;
    TListItem *t = List.First;
    while (t != nullptr) {
        sum += t->Value;
        t = t->Prev;
    }
    return sum;
}

int ListDobutok (TList &List) {
    int dobutok = 1;
    TListItem *t = List.First;
    while (t != nullptr) {
        dobutok *= t->Value;
        t = t->Prev;
    }
    return dobutok;
}

int ListCount(TList &List) {
    int count = 0;
    TListItem *t = List.First;
    while (t != nullptr) {
        count++;
        t = t->Prev;
    }
    return count;
}

int ListEvenCount (TList &List) {
    int isEven = 0;
    int count = 0;
    TListItem *t = List.First;
    while (t != nullptr) {
        if (isEven % 2 == 0) {
            count++;
        }
        isEven++;
        t = t->Prev;
    }
    return count;
}

int ListOddSum (TList &List) {
    int isOdd = 0;
    int sum = 0;
    TListItem *t = List.First;
    while (t != nullptr) {
        if (isOdd % 2 != 0) {
            sum += t->Value;
        }
        isOdd++;
        t = t->Prev;
    }
    return sum;
}

int main() {

    TList L;
    L = InitList();

    for (int i = 0; i < ListSize; i++) {
        AddListItem(L, i);
    }
    PrintList(L);
    std::cout << std::endl;

    std::cout << "ListSum = " <<  ListSum(L) << std::endl;
    std::cout << "ListDobutok = " << ListDobutok(L) << std::endl;
    std::cout << "ListCount = " << ListCount(L) << std::endl;
    std::cout << "ListEvenCount = " << ListEvenCount(L) << std::endl;
    std::cout << "ListOddSum = " << ListOddSum(L) << std::endl;

    DestroyList(L);
    return 0;
}