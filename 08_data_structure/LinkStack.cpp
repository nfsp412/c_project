#include <stdio.h>
#include <stdlib.h>

// 栈
// 单链表实现
// 链表头部看做栈顶,头插法
// 带头结点和不带头结点版本,推荐不带头结点

typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkStack;

// 下面演示不带头结点版本的相关操作

/**
 * 初始化
 */
void InitLinkStackHead(LinkStack &S)
{
    S = NULL;
}

/**
 * 入栈
 */
bool PushHead(LinkStack &S, int x)
{
    LNode *t = (LNode *)malloc(sizeof(LNode));
    t->data = x;
    if (S == NULL)
    {
        // 首个节点
        S = t;
        S->next = NULL;
    }
    else
    {
        t->next = S;
        S = t;
    }

    return true;
}

/**
 * 判空
 */
bool isEmptyHead(LinkStack S)
{
    if (S == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNotEmptyHead(LinkStack S)
{
    return !isEmptyHead(S);
}

/**
 * 出栈
 */
bool PopHead(LinkStack &S, int &x)
{
    if (isEmptyHead(S))
    {
        return false;
    }

    LNode *t = S;
    x = t->data;
    S = S->next;
    free(t);
    return true;
}

/**
 * 获取栈顶元素
 */
bool GetTopHead(LinkStack &S, int &x)
{
    if (S == NULL)
    {
        return false;
    }

    x = S->data;
    return true;
}

void PrintLinkStackHead(LinkStack S)
{
    while (S != NULL)
    {
        printf("%4d", S->data);
        S = S->next;
    }
    printf("\n");
}

// 演示带头结点版本

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

bool isEmpty(LinkStack S)
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

bool isNotEmpty(LinkStack S)
{
    return !isEmpty(S);
}

bool Pop(LinkStack &S, int &x)
{
    if (isEmpty(S))
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
    if (isEmpty(S))
    {
        return false;
    }
    x = S->next->data;
    return true;
}

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

int main()
{
    // LinkStack S;
    // InitLinkStackHead(S);

    // PushHead(S, 100);
    // PushHead(S, 200);
    // PushHead(S, 300);
    // PrintLinkStackHead(S);

    // int x;
    // PopHead(S, x);
    // PopHead(S, x);
    // PopHead(S, x);
    // PrintLinkStackHead(S);

    // int y;
    // GetTopHead(S, y);
    // printf("%d\n", y);

    // bool flag = isEmptyHead(S);
    // if (flag)
    // {
    //     printf("empty\n");
    // }

    // flag = isNotEmptyHead(S);
    // if (flag)
    // {
    //     printf("not empty\n");
    // }

    // LinkStack S;
    // InitLinkStack(S);
    // Push(S, 100);
    // Push(S, 200);
    // Push(S, 300);
    // PrintLinkStack(S);

    // int x;
    // Pop(S, x);
    // // Pop(S, x);
    // // Pop(S, x);
    // // Pop(S, x);
    // PrintLinkStack(S);

    // int y;
    // GetTop(S, y);
    // printf("%d\n", y);

    return 0;
}
