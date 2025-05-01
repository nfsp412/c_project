#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkStack;

typedef struct
{
    LNode *front;
    LNode *rear;
} LinkQueue;

bool InitLinkQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
    Q.front->next = NULL; // rear也同步指向null
}

bool InitLinkQueueNoHead(LinkQueue &Q)
{
    Q.front = Q.rear = NULL;
}

bool isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyNoHead(LinkQueue Q)
{
    if (Q.front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * 入队列,单链表不用担心越界,所以不需要判满
 * 入队列操作rear,尾插
 */
bool EnQueue(LinkQueue &Q, int x)
{
    LNode *t = (LNode *)malloc(sizeof(LNode));
    t->data = x;
    t->next = NULL;

    // 尾插
    Q.rear->next = t;
    Q.rear = t;
}

/**
 * 入队列,不带头结点,尾插
 * 实际上多了一步首次插入的判断而已
 */
bool EnQueueNoHead(LinkQueue &Q, int x)
{
    LNode *t = (LNode *)malloc(sizeof(LNode));
    t->data = x;
    t->next = NULL;

    if (Q.rear == NULL)
    {
        // 首次插入
        Q.rear = t;
        Q.front = t;
    }
    else
    {
        // 非首次插入
        Q.rear->next = t;
        Q.rear = t;
    }
}

/**
 * 出队列 带头结点 需要判空 操作front指针
 */
bool DeQueue(LinkQueue &Q, int &x)
{
    if (isEmpty(Q))
    {
        return false; // 队列空
    }

    LNode *t = Q.front->next;
    x = t->data;

    // 移动front
    Q.front->next = t->next;

    // 如果出队列的节点(即删除的节点)刚好是rear指向的节点
    if (t == Q.rear)
    {
        Q.rear = Q.front; //
    }

    free(t);
}

bool DeQueueNoHead(LinkQueue &Q, int &x)
{
    if (isEmptyNoHead(Q))
    {
        return false;
    }

    //
    LNode *t = Q.front;
    x = t->data;

    //
    Q.front = t->next;

    if (t == Q.rear)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }

    free(t);
}

// 双端队列

bool InitLinkStack(LinkStack &S)
{
    S = (LNode *)malloc(sizeof(LNode));
    if (S == NULL)
    {
        return false;
    }

    S->next = NULL;
    return true;
}

bool Push(LinkStack &S, int x)
{
    LNode *p = S;
    LNode *t = (LNode *)malloc(sizeof(LNode));
    t->data = x;
    t->next = S->next;
    S->next = t;
    return true;
}

bool isEmptyStack(LinkStack S)
{
    if (S->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNotEmptyStack(LinkStack S)
{
    return !isEmptyStack(S);
}

bool Pop(LinkStack &S, int &x)
{
    if (isEmptyStack(S))
    {
        return false;
    }

    LNode *t = S->next;
    x = t->data;
    S->next = t->next;
    free(t);
}

bool GetTop(LinkStack S, int &x)
{
    if (isEmptyStack(S))
    {
        return false;
    }
    x = S->next->data;
    return true;
}

void PrintLinkStack(LinkStack S)
{
    S = S->next;
    while (S != NULL)
    {
        printf("%4d", S->data);
        S = S->next;
    }
    printf("\n");
}

void PrintLinkQueue(LinkQueue Q)
{
    Q.front = Q.front->next;
    while (Q.front != NULL)
    {
        printf("%4d", Q.front->data);
        Q.front = Q.front->next;
    }
    printf("\n");
}

// 使用队列和栈,来逆置队列元素
void f1(LinkQueue Q, LinkStack &S)
{
    int x;
    while (!isEmpty(Q))
    {
        DeQueue(Q, x); // 出队列
        Push(S, x);    // 入栈
    }
    while (!isEmptyStack(S))
    {
        Pop(S, x);     // 出栈
        EnQueue(Q, x); // 入队列
    }
}

// 2

bool StackOverFlow(LinkStack S)
{
    LNode *t = (LNode *)malloc(sizeof(LNode));
    if (t == NULL)
    {
        // 内存不足即内存溢出
        return true;
    }
    else
    {
        return false;
    }
}

// 入队列 S1入栈
bool EQ(LinkStack &S1, LinkStack &S2, int e)
{
    // S1不满,直接入栈
    if (!isEmptyStack(S1))
    {
        Push(S1, e);
        return true;
    }

    // S1满,S2不为空(即S2有数据在)
    if (StackOverFlow(S1) && !isEmptyStack(S2))
    {
        printf("error\n");
        return false;
    }

    // S1满,S2空,把元素全部移动到S2
    if (StackOverFlow(S1) && isEmptyStack(S2))
    {
        int x;
        while (!isEmptyStack(S1))
        {
            Pop(S1, x);
            Push(S2, x);
        }
    }

    Push(S1, e); // S1入栈
    return true;
}

// 出队列 S1全部出栈到S2中,S2出栈,实现FIFO
bool DQ(LinkStack &S1, LinkStack &S2, int &e)
{
    if (isEmptyStack(S2) && !isEmptyStack(S1))
    {
        int x;
        // 全部移动到S2
        while (!isEmptyStack(S1))
        {
            Pop(S1, x);
            Push(S2, x);
        }
        Pop(S2, e); // 出栈一个代表出队列
        return true;
    }
    return false;
}

// 判空
bool QE(LinkStack S1, LinkStack S2)
{
    if (isEmptyStack(S1) && isEmptyStack(S2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    LinkQueue Q;

    InitLinkQueue(Q);

    EnQueue(Q, 100);
    EnQueue(Q, 200);
    EnQueue(Q, 300);

    PrintLinkQueue(Q);

    //习题部分 3.2.5

    // 2
    LinkStack S;
    InitLinkStack(S);

    f1(Q, S);

    PrintLinkQueue(Q);

    // 3

    return 0;
}
