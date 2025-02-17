#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

/**
 * 单链表
 */
typedef struct Node
{
    ElemType data;
    struct Node *next;
} LNode;

// 函数声明
bool InitList(LNode *L);
bool InsertList(LNode *L, int i, ElemType e);
bool InsertNextNode(LNode *p, ElemType e);
bool InsertPriorNode(LNode *p, ElemType e);
bool DeleteList(LNode *L, int i, ElemType *e);
void printLinkedList(LNode *L);
bool DeleteNode(LNode *p);

/**
 * 单链表
 * 带头结点,初始化,头结点不存储数据
 * @param L 结构体指针,作形参
 */
bool InitList(LNode *L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 头结点
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL; // 暂时无下一节点

    return true;
}

/**
 * 单链表
 * 插入元素
 * @param L 带插入元素的单链表,是一个结构体指针
 * @param i 插入位置,从1开始,不算头结点
 * @param e 插入元素
 */
bool InsertList(LNode *L, int i, ElemType e)
{

    if (i < 1)
    {
        return false;
    }

    // 创建临时指针p
    LNode *p;
    int j = 0;
    p = L;                         // 头结点赋值给临时指针p
    while (p != NULL && j < i - 1) // 位数1的元素插入时,不会进入循环,不为1的元素插入时,循环找到位数i的节点
    {
        p = p->next; // i-1位置的节点
        j++;
    }

    // 后插
    InsertNextNode(p, e);
    // 前插
    // InsertPriorNode(p, e);

    return true;
}

/**
 * 后插操作
 * @param p 传入节点指针
 * @param e 插入的元素
 */
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
    {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false; // 内存不足导致失败
    }

    s->data = e;
    s->next = p->next; // NULL或者i位置赋值s.next
    p->next = s;       // s赋值给NULL或者i位置

    return true;
}

/**
 * 前插操作
 * @param p 传入节点指针
 * @param e 插入的元素
 */
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
    {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }

    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
}

/**
 * 按位置删除
 * @param L 单链表
 * @param i 位置,从1开始,不包含头结点
 * @param e 被删除的元素指针
 */
bool DeleteList(LNode *L, int i, ElemType *e)
{
    if (i < 1)
    {
        return false;
    }

    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next; // 循环找的i-1位置
        j++;
    }

    if (p == NULL)
    {
        return false;
    }
    if (p->next == NULL)
    {
        return false;
    }

    // i-1位置连接到i+1位置
    LNode *q = p->next; // i位置
    (*e) = q->data;     // 被删除元素
    p->next = q->next;
    free(q);

    return true;
}

/**
 * 打印单链表
 */
void printLinkedList(LNode *L)
{
    LNode *p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/**
 * 单链表删除指定节点
 */
bool DeleteNode(LNode *p)
{
    if (p == NULL)
    {
        return false;
    }

    LNode *q = p->next;      // q指向p+1
    p->data = p->next->data; // 将p+1的数据覆盖p的数据
    p->next = q->next;
    free(q);

    return true;
}

int main()
{
    LNode L;

    bool res = InitList(&L);
    if (res == true)
    {
        printf("InitList success\n");
        printLinkedList(&L);
    }

    bool res1 = InsertList(&L, 1, 100);
    if (res1 == true)
    {
        printf("InsertList success\n");
        printLinkedList(&L);
    }

    bool res2 = InsertList(&L, 1, 10);
    if (res2 == true)
    {
        printf("InsertList success\n");
        printLinkedList(&L);
    }

    bool res3 = InsertList(&L, 1, 1);
    if (res3 == true)
    {
        printf("InsertList success\n");
        printLinkedList(&L);
    }

    bool res4 = InsertList(&L, 2, 33);
    if (res4 == true)
    {
        printf("InsertList success\n");
        printLinkedList(&L);
    }

    int e;
    bool res5 = DeleteList(&L, 2, &e);
    if (res5 == true)
    {
        printf("DeleteList success\n");
        printf("del = %d\n", e);
        printLinkedList(&L);
    }

    return 0;
}
