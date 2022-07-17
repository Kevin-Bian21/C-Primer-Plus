//
// Created by 边文凯 on 2022/1/3.
//

#include <stdio.h>
#include <stdlib.h> /* 为 malloc()、free()提供原型 */

typedef struct Student{
    int id;
    char* name;
    int age;
}Stu;

typedef struct Node{
    struct Node* next;
    Stu data;
}LNode, *LinkList;  //LNode 为结构体 Node 类型，LinkList 指向的是结构体 Node 的指针类型

LinkList L; //定义头指针变量，用头指针来标识一个单链表

LinkList InitList(LinkList L);
void InsertFromTail(Stu data);
Stu createStudent(int id, char* name, int age);
void printList(LinkList L);

int main() {
    L = InitList(L);
//    printList(L);
    char* name = "边文凯";
    char* name1 = "边文涛";
    Stu s = createStudent(1001, name, 22);
    Stu s1 = createStudent(1002, name1, 28);
    InsertFromTail(s);
    InsertFromTail(s1);

    printList(L);
}

//链表初始化，构造一个空的线性表L
LinkList InitList(LinkList L) {
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    L->data.id = 0;
    L->data.name = NULL;
    L->data.age = 0;
    return L;
}

void InsertFromTail(Stu data) {
    LNode* p;
    p = (LinkList) malloc(sizeof(LNode));
    p -> data = data;
    LinkList tail;
    tail = L;
    while (tail -> next != NULL) {
        tail = tail -> next;
    }
    tail -> next = p;
    p -> next = NULL;
}

Stu createStudent(int id, char* name, int age) {
    Stu *s = (Stu*) malloc(sizeof(Stu));
    s->id = id;
    s->name = name;
    s->age = age;
    return *s;
}

void printList(LinkList L){
    if (L -> next == NULL)
        printf("The LinkList is empty! \n");
    while (L -> next != NULL) {
        printf("%s\n", L -> next -> data.name);
        L = L->next;
    }
}

/**
基本操作：
InitList (&L)
操作结果：构造一个空的线性表L。
DestroyList(&L)
初始条件：线性表L已存在。
操作结果：销毁线性表L。
ClearList (&L)
初始条件：线性表L已存在。
操作结果：将L重置为空表。
ListEmpty(L)
初始条件：线性表L已存在。
操作结果：若L为空表， 则返回true, 否则返回false。
ListLength(L)
初始条件：线性表L已存在。
操作结果：返回L中数据元素个数。
GetElem(L,i,&e)
初始条件：线性表L巳存在，且1:,s;i:os;ListLength(L)。
操作结果：用e返回L中第1个数据元素的值。
LocateElem(L,e)
初始条件：线性表L已存在。
操作结果：返回L中第1个 值与e相同的元素在 L中的位置 。若这样的数据元素不存在 ， 则返回值为0。
PriorElem(r,,cur_e,&pre_e)
初始条件：线性表L已存在。
操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回其前驱，否则操作失败，pre_e无定义。
NextElem(L,cur_e,&next_e)
初始条件：线性表L已存在。
操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回其后继，否则操作失败，next_e无定义。
Listinsert(&L,i,e)
初始条件：线性表L已存在，且1:,s;i:os;ListLength (L) +l。
操作结果：在 L中第1个位置之前插入新的数据元素 e, L的长度加1。
ListDelete(&L,i)
初始条件：线性表L已存在且非空 ，且l:os;i:os;ListLength(L)。
操作结果：删除L的第1个数据元素，L的长度减1。
TraverseList(L)
初始条件：线性表L已存在。
操作结果：对线性表L进行遍历，在遍历过程中对 L的每个结点访问一次。
*/