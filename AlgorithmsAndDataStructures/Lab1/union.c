#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ListSize 15
#define MaxValue 20
 
struct TListItem {
    int Value;
    struct TListItem *Next, *Prev;
};
 
struct TList {
   struct TListItem *First,*Last;
};
 
struct TList InitList(){
    struct TList r;
    r.First = NULL;
    r.Last = NULL;
    return r;
}
 
void AddListItem(struct TList *List, int val) {
    if (List->First == NULL) {
        List->First = (struct TListItem*)malloc(sizeof(struct TListItem));
        List->First->Next = NULL;
        List->First->Prev = NULL;
        List->First->Value = val;
        List->Last = List->First;
    }
    else {
        List->Last->Next = (struct TListItem*)malloc(sizeof(struct TListItem));
        List->Last->Next->Prev = List->Last;
        List->Last->Next->Next = NULL;
        List->Last->Next->Value = val;
        List->Last = List->Last->Next;
    }
}
 
void DestroyList(struct TList *List) {
    struct TListItem *t = List->First, *r;

    while (t != NULL) {
        r = t->Next;
        free(t);
        t = r;
    }

    List->First = List->Last = NULL;
}
 
void PrintList(struct TList *List) {
    struct TListItem *t = List->First;

    while (t != NULL) {
        printf("%d", t->Value);
        t = t->Next;
    }
}
 
void FillListWithNumbers(struct TList *List) {
    // Генерація числа від 0 до 9
    int random_num = rand() % 10;
 
    for (int i = 0; i < ListSize; i++) {
        AddListItem(List, random_num);
        random_num = rand() % 10;
    }
}
 
void DeleteRepeats(struct TList *List) {
    struct TListItem *t = List->First;

    while (t != NULL) {
        struct TListItem *p = t->Next;

        while (p != NULL) {
            struct TListItem *next = p->Next;

            if (t->Value == p->Value) {

                if (p->Prev != NULL){
                    p->Prev->Next = p->Next;
                }

                if (p->Next != NULL) {
                    p->Next->Prev = p->Prev;
                }

                else {
                    List->Last = p->Prev;
                }
                free(p);
            }
            p = next;
        }
        t = t->Next;
    }
}
struct TList Union(struct TList *A, struct TList *B) {
    struct TList C = InitList();

    struct TListItem *a = A->First;
    struct TListItem *b = B->First;

    while (a != NULL) {
        AddListItem(&C, a->Value);
        a = a->Next;
    }

    while (b != NULL) {
        AddListItem(&C, b->Value);
        b = b->Next;
    }

    DeleteRepeats(&C);

    return C;
}
 
int main(void) {
    srand(time(NULL));
 
    struct TList A;
    struct TList B;
    struct TList C;
 
    A = InitList();
    B = InitList();
 
    FillListWithNumbers(&A);
    FillListWithNumbers(&B);
 
    C = Union(&A,&B);
 
    PrintList(&A);
    printf("\n");
    PrintList(&B);
    printf("\n");
    PrintList(&C);

    DestroyList(&A);
    DestroyList(&B);
    DestroyList(&C);

    return 0;
}