// //Двозв'язний список !!!
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <conio.h>
//
// #define ListSize 15
// #define MaxValue 20
//
// struct TListItem {
//     int Value;
//     struct TListItem *Next, *Prev;
// };
//
// struct TList {
//     struct TListItem *First, *Last;
// };
//
// struct TList InitList() {
//     struct TList r;
//     r.First = NULL;
//     r.Last = NULL;
//     return r;
// }
//
// void AddListItem(struct TList *List, const int val) {
//     if (List->First == NULL) {
//         List->First = (struct TListItem*)malloc(sizeof(struct TListItem));
//         List->First->Next = NULL;
//         List->First->Prev = NULL;
//         List->First->Value = val;
//         List->Last = List->First;
//     }
//     else {
//         List->Last->Next = (struct TListItem*)malloc(sizeof(struct TListItem));
//         List->Last->Next->Prev = List->Last;
//         List->Last->Next->Next = NULL;
//         List->Last->Next->Value = val;
//         List->Last = List->Last->Next;
//     }
// }
//
// void DestroyList(struct TList *List) {
//     struct TListItem *t = List->First, *r;
//     while (t != NULL) {
//         r = t->Next;
//         free(t);
//         t = r;
//     }
//     List->First = List->Last = NULL;
// }
//
// void PrintList(struct TList *List) {
//     struct TListItem *t = List->First;
//     while (t != NULL) {
//         printf("%d ", t->Value);
//         t = t->Next;
//     }
// }
//
// int ListSum(struct TList *List) {
//     int sum = 0;
//     struct TListItem *t = List->First;
//     while (t != NULL) {
//         sum += t->Value;
//         t = t->Next;
//     }
//     return sum;
// }
//
// int ListDobutok (struct TList *List) {
//     int dobutok = 1;
//     struct TListItem *t = List->First;
//     while (t != NULL) {
//         dobutok *= t->Value;
//         t = t->Next;
//     }
//     return dobutok;
// }
//
// int ListCount(struct TList *List) {
//     int count = 0;
//     struct TListItem *t = List->First;
//     while (t != NULL) {
//         count++;
//         t = t->Next;
//     }
//     return count;
// }
//
// int ListEvenCount (struct TList *List) {
//     int isEven = 0;
//     int count = 0;
//     struct TListItem *t = List->First;
//     while (t != NULL) {
//         if (isEven % 2 == 0) {
//             count++;
//         }
//         isEven++;
//         t = t->Next;
//     }
//     return count;
// }
//
// int ListOddSum (struct TList *List) {
//     int isOdd = 0;
//     int sum = 0;
//     struct TListItem *t = List->First;
//     while (t != NULL) {
//         if (isOdd % 2 != 0) {
//             sum += t->Value;
//         }
//         isOdd++;
//         t = t->Next;
//     }
//     return sum;
// }
//
// int main() {
//
//     struct TList L;
//     L = InitList();
//     for (int i = 0; i < ListSize; i++) {
//         AddListItem(&L, i);
//     }
//     PrintList(&L);
//     printf("\n");
//
//     printf("ListSum = %d\n", ListSum(&L));
//     printf("ListDobutok = %d\n", ListDobutok(&L));
//     printf("ListCount = %d\n", ListCount(&L));
//     printf("ListEvenCount = %d\n", ListEvenCount(&L));
//     printf("ListOddSum = %d\n", ListOddSum(&L));
//
//     DestroyList(&L);
//     return 0;
// }