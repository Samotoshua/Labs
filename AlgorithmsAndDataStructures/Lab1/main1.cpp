// #include <iostream>
// #include <ctime>
//
// #define ListSize 15
// #define MaxValue 20
//
// struct TListItem {
//     int Value;
//     TListItem *Next, *Prev;
// };
//
// struct TList {
//     TListItem *First, *Last;
// };
//
// TList InitList() {
//     TList r;
//     r.First = nullptr;
//     r.Last = nullptr;
//     return r;
// }
//
// void AddListItem(TList &List, int val) {
//     if (List.First == nullptr) {
//         List.First = new TListItem;
//
//         List.First->Next = nullptr;
//         List.First->Prev = nullptr;
//         List.First->Value = val;
//
//         List.Last = List.First;
//     }
//
//     else {
//         List.Last->Next = new TListItem;
//
//         List.Last->Next->Prev = List.Last;
//         List.Last->Next->Next = nullptr;
//         List.Last->Next->Value = val;
//
//         List.Last = List.Last->Next;
//     }
// }
//
// void DestroyList(TList &List) {
//     TListItem *t = List.First;
//     TListItem *r;
//
//     while (t != nullptr) {
//
//         r = t->Next;
//
//         delete t;
//
//         t = r;
//     }
//
//     List.First = nullptr;
//     List.Last = nullptr;
// }
//
// void PrintList(const TList &List) {
//     TListItem *t = List.First;
//     while (t != nullptr) {
//
//         std::cout << t->Value << " ";
//
//         t = t->Next;
//     }
// }
//
// void FillListWithNumbers(TList &List) {
//     for (int i = 0; i < ListSize; i++) {
//         int random_num = rand() % 10;
//
//         AddListItem(List, random_num);
//     }
// }
//
// void DeleteRepeats(TList &List) {
//     TListItem *t = List.First;
//
//     while (t != nullptr) {
//         TListItem *p = t->Next;
//
//         while (p != nullptr) {
//             TListItem *next = p->Next;
//
//             if (t->Value == p->Value) {
//
//                 if (p->Prev != nullptr) {
//                     p->Prev->Next = p->Next;
//                 }
//
//                 if (p->Next != nullptr) {
//                     p->Next->Prev = p->Prev;
//                 }
//
//                 else {
//                     List.Last = p->Prev;
//                 }
//                 delete p;
//             }
//             p = next;
//         }
//         t = t->Next;
//     }
// }
//
// TList Union(const TList &A, const TList &B) {
//     TList C = InitList();
//
//     TListItem *a = A.First;
//     TListItem *b = B.First;
//
//     while (a != nullptr) {
//
//         AddListItem(C, a->Value);
//
//         a = a->Next;
//     }
//
//     while (b != nullptr) {
//
//         AddListItem(C, b->Value);
//
//         b = b->Next;
//     }
//
//     DeleteRepeats(C);
//
//     return C;
// }
//
// int main() {
//
//     srand(time(nullptr));
//
//     TList A = InitList();
//     TList B = InitList();
//
//     FillListWithNumbers(A);
//     FillListWithNumbers(B);
//
//     TList C = Union(A, B);
//
//     PrintList(A);
//     std::cout << '\n';
//
//     PrintList(B);
//     std::cout << '\n';
//
//     PrintList(C);
//     std::cout << '\n';
//
//     DestroyList(A);
//     DestroyList(B);
//     DestroyList(C);
//
//     return 0;
// }