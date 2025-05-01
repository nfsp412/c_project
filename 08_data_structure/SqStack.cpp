#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize]; // 数组存储栈元素,更常见,索引为0的位置是栈的栈底,入栈实际上就是元素向后赋值,出栈就是从后向前取值,即先进后出
    int top;
} SqStack;

/**
 * 初始化栈方法
 */
void InitStack(SqStack &S)
{
    S.top = -1; // 代表初始化栈,栈为空
}

/**
 * 判断栈是否为空方法
 */
bool StackEmpty(SqStack &S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * 入栈方法
 */
bool Push(SqStack &S, ElemType e)
{
    if (S.top == MaxSize - 1)
    {
        return false; // top,栈的栈顶,数组最大长度MaxSize,对应操作的索引最大是MaxSize - 1,所以top不能大于最大索引,不然top后面自增就会越界
    }
    S.data[++S.top] = e; // 入栈,先++,代表由-1先变为0,再操作数组赋值代表0索引赋值为e,第二次时,先++,代表索引由0变1,再赋值,代表1索引元素赋值e
    return true;
}

/**
 * 出栈
 * 使用引用把出栈获取到的元素带回来
 */
bool Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
    {
        return false; // 代表栈空
    }
    e = S.data[S.top--]; // 代表先取值top索引位置的元素出栈,再操作top--,例如栈底元素索引为0,则先取值,再操作--,变成-1
    return true;
}

/**
 * 获取栈顶元素,即top位置元素
 */
bool GetTop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
    {
        return false;
    }

    e = S.data[S.top]; // 不会包含-1
    return true;
}

void PrintStack(SqStack S)
{
    for (int i = 0; i <= S.top; i++)
    {
        printf("%3d", S.data[i]);
    }
    printf("\n");
}

int main()
{
    SqStack S;

    InitStack(S);

    bool res1 = StackEmpty(S);
    if (res1)
    {
        printf("true\n");
    }

    Push(S, 33);
    Push(S, 47);
    Push(S, 56);

    PrintStack(S);

    int e1;
    GetTop(S, e1);
    printf("%d\n", e1);

    int e2;
    Pop(S, e2);
    printf("%d\n", e2);
    PrintStack(S);

    return 0;
}
