#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode;

typedef struct
{
    LNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    // 头结点和尾节点分配内存空间,是结构体指针,指向头结点和尾节点,初始化时指向相同节点
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));

    // 头结点的next指向NULL
    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true; // 判断的代码和循环队列一样
    }
    else
    {
        return false;
    }
}

/**
 * 入队列,操作rear指针,尾插法
 * 入队列不存在队列满的情况,不像循环队列
 */
void EnQueue(LinkQueue &Q, ElemType e)
{
    // 分配内存
    LNode *s = (LNode *)malloc(sizeof(LNode));

    // data赋值
    s->data = e;

    // next赋值,让s成为最后的节点,即尾节点
    s->next = NULL;

    Q.rear->next = s; // 让rear的next节点指向s

    // 同时让rear本身也移动到尾节点,这样修改并不会影响Q的front,
    Q.rear = s;
}

/**
 * 出队列
 */
bool DeQueue(LinkQueue &Q, ElemType &e)
{
    if (Q.front == Q.rear)
    {
        return false;
    }

    // 获取队列的front的下一节点,因为front作为头结点,并没有存储数据,所以这里获取头结点的下一节点
    LNode *p = Q.front->next;

    // 将出队列元素带回
    e = p->data;

    Q.front->next = p->next; // 让front的下一节点指向p的next,而不是指向p,即断链

    // 不置空的话下一次再执行一次删除就会抛异常
    if (Q.rear == p)
    {
        Q.rear = Q.front; // 队列到达最后,需要让rear指向front,否则下一次删除会抛出异常
    }

    // 释放出队列节点的内存
    free(p);

    return true;
}

int main()
{
    LinkQueue Q;

    InitQueue(Q);

    EnQueue(Q, 33);
    EnQueue(Q, 45);
    EnQueue(Q, 27);

    int e1;
    DeQueue(Q, e1);
    printf("%d\n", e1);
    DeQueue(Q, e1);
    printf("%d\n", e1);

    return 0;
}
