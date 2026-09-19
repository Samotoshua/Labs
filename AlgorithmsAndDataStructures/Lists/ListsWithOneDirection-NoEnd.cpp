// //Однозв'язний список без кінця
 #include <iostream>

 #define ListSize 15
 #define MaxValue 20

 struct TListItem {
     int Value;
     TListItem *Next;
 };

 struct TList {
     TListItem *First;
 };

 TList InitList() {
     TList r;
     r.First = nullptr;
     return r;
 }

 void AddListItem(TList &List, const int val) {
     if (List.First == nullptr) {
         List.First = new TListItem;
         List.First->Next = nullptr;
         List.First->Value = val;
     }
     else {
         TListItem *t = List.First;

         while (t->Next != nullptr) {
            t = t->Next;
         }

         t->Next = new TListItem;
         t->Next->Value = val;
         t->Next->Next = nullptr;
     }
 }

 void DestroyList(TList &List) {
     TListItem *t = List.First, *r;
     while (t != nullptr) {
         r = t->Next;
         delete t;
         t = r;
     }
     List.First = nullptr;
 }

 void PrintList(TList &List) {
     TListItem *t = List.First;
     while (t != nullptr) {
         std::cout << t->Value << ' ';
         t = t->Next;
     }
 }

 int ListSum(TList &List) {
     int sum = 0;
     TListItem *t = List.First;
     while (t != nullptr) {
         sum += t->Value;
         t = t->Next;
     }
     return sum;
 }

 int ListDobutok (TList &List) {
     int dobutok = 1;
     TListItem *t = List.First;
     while (t != nullptr) {
         dobutok *= t->Value;
         t = t->Next;
     }
     return dobutok;
 }

 int ListCount(TList &List) {
     int count = 0;
     TListItem *t = List.First;
     while (t != nullptr) {
         count++;
         t = t->Next;
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
         t = t->Next;
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
         t = t->Next;
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