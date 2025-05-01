#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitStack(SqStack &S)
{
    S.top = -1; // 注意是=而不是==
}

void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool Push(SqStack &S, ElemType e)
{
    if (S.top == MaxSize - 1)
    {
        return false;
    }

    S.data[++S.top] = e;

    return true;
}

bool Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
    {
        return false;
    }

    e = S.data[S.top--];

    return true;
}

bool EnQueue(SqQueue &Q, ElemType e)
{
    if (Q.front == (Q.rear + 1) % MaxSize)
    {
        return false;
    }

    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;

    return true;
    
}

bool DeQueue(SqQueue &Q, ElemType &e)
{
    if (Q.front == Q.rear)
    {
        return false;
    }

    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;

    return true;
    
}

int main()
{
    SqStack S;
    InitStack(S);

    // 读取
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);

    // printf("%2d", i);
    // printf("%2d", j);
    // printf("%2d", k);
    // printf("\n");

    // 入栈
    Push(S, i);
    Push(S, j);
    Push(S, k);

    // 出栈
    ElemType a;
    Pop(S, a);
    printf("%2d", a);
    Pop(S, a);
    printf("%2d", a);
    Pop(S, a);
    printf("%2d", a);
    printf("\n");

    SqQueue Q;
    InitQueue(Q);

    // 读取
    ElemType a1, b1, c1, d1, e1;
    scanf("%d%d%d%d%d", &a1, &b1, &c1, &d1, &e1);

    // printf("%2d", a1);
    // printf("%2d", b1);
    // printf("%2d", c1);
    // printf("%2d", d1);
    // printf("%2d", e1);
    // printf("\n");

    //入队列
    EnQueue(Q, a1);
    EnQueue(Q, b1);
    EnQueue(Q, c1);
    EnQueue(Q, d1);
    bool res = EnQueue(Q, e1);
    if (!res)
    {
        printf("false\n");
    }
    
    //出队列
    DeQueue(Q, a);
    printf("%2d", a);
    DeQueue(Q, a);
    printf("%2d", a);
    DeQueue(Q, a);
    printf("%2d", a);
    DeQueue(Q, a);
    printf("%2d", a);
    printf("\n");

    return 0;
}
