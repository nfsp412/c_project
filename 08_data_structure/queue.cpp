#include "function.h"

// 函数声明:一些常用的单链表的队列的方法
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));

    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }else{
        return false;
    }
}

void EnQueue(LinkQueue &Q, BiTree e)
{
    LNode *p = (LNode *) malloc(sizeof(LNode));

    p->data = e;

    p->next = NULL;

    Q.rear->next = p;

    Q.rear = p;
}

bool DeQueue(LinkQueue &Q, BiTree &e)
{
    if (Q.front == Q.rear)
    {
        return false;
    }

    LNode *p = Q.front->next;//跳过头结点
    
    e = p->data;

    Q.front->next = p->next;

    //多一步重要的判断
    if (Q.rear == p)
    {
        Q.rear = Q.front;//让rear指向front而不是front指向rear,
    }
    
    free(p);
    
    return true;
}