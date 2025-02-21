#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

void PrintList(LinkList L)
{

    L = L->next;

    while (L != NULL)
    {

        printf("%3d", L->data); // 打印当前结点数据

        L = L->next; // 指向下一个结点
    }

    printf("\n");
}

LinkList InitList(LinkList &L)
{
    // 分配头结点内存
    L = (LinkList)malloc(sizeof(LNode));

    // 链表尾节点指向null
    // L->next = NULL;

    // 定义尾节点
    LNode *r = L;

    // 定义临时变量存储输入数据
    int x;

    // 定义临时指针存储节点
    LNode *s;

    // 读取第一个数据
    scanf("%d", &x);

    // 循环判断
    while (x != 9999)
    {
        // 分配内存
        s = (LNode *)malloc(sizeof(LNode));

        // data赋值
        s->data = x;

        // next赋值
        r->next = s;
        r = r->next;
        // r = s;

        // 继续读取数据
        scanf("%d", &x);
    }

    // 初始化结束后,尾节点指向null
    r->next = NULL;

    // 返回L而不是r
    return L;
}

/**
 * 查找i位置值并输出
 */
LNode *LocateList(LinkList L, int i)
{
    if (i == 0)
    {
        return L; // i=0代表返回头结点
    }

    if (i < 1)
    {
        return NULL; // 异常
    }

    // 跳过头结点
    LNode *s;
    s = L->next;

    // 定义临时变量存储位置变化
    int j = 1;

    // s不为null并且j的值小于i,注意等于i的时候,不应该在循环了,此时已经找到了
    while (s != NULL && j < i)
    {
        s = s->next; // 指针向右移动
        j++;         // j自增避免死循环
    }

    return s;
}

bool InsertList(LinkList &L, int i, int e)
{
    // 找到i-1位置的节点
    LNode *p = LocateList(L, i - 1);

    // p为null
    if (p == NULL)
    {
        return false;
    }

    // 分配内存
    LNode *s = (LNode *)malloc(sizeof(LNode));

    // data赋值
    s->data = e;

    // next赋值
    s->next = p->next; // 将s指向位置i的节点
    p->next = s;       // 将i-1位置节点指向s

    return true;
}

bool DeleteList(LinkList &L, int i)
{
    if (i < 1)
    {
        return false;
    }

    // 找到i-1位置节点
    LNode *s = LocateList(L, i - 1);

    if (s == NULL)
    {
        return false;
    }

    // del
    LNode *p;
    p = s->next; // i位置节点临时存储

    // 判断p是否null
    if (p == NULL)
    {
        return false;
    }

    // s下一节点指向i+1位置节点
    s->next = p->next;

    // 释放i位置节点内存
    free(p);

    return true;
}

int main()
{
    LinkList L;
    InitList(L);
    // PrintList(L);

    LNode *s = LocateList(L, 2);
    printf("%d\n", s->data);

    InsertList(L, 2, 99);
    PrintList(L);

    DeleteList(L, 4);
    PrintList(L);

    return 0;
}
