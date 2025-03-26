#include <stdio.h>
#include <stdlib.h>

// 栈 是一种特殊的线性表 后进先出 栈顶进行插入删除操作
// 顺序表实现, 单链表实现

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int top; // 指向栈顶,一般0开始
} SqStack;

typedef struct
{
    char data[MaxSize];
    int top; // 指向栈顶,一般0开始
} SqStackChar;

void InitStack(SqStack &S)
{
    S.top = -1; // 初始化
}

void InitStackChar(SqStackChar &S)
{
    S.top = -1; // 初始化
}

void DestroyStack(SqStack &S)
{
    S.top = -1;
}

bool Push(SqStack &S, int x)
{
    // 数组最大元素索引应该是MaxSize-1
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.top++;           // 先移动top
    S.data[S.top] = x; // 再赋值
    return true;
}

bool PushChar(SqStackChar &S, char x)
{
    // 数组最大元素索引应该是MaxSize-1
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.top++;           // 先移动top
    S.data[S.top] = x; // 再赋值
    return true;
}

bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
    {
        return false; // 代表栈空
    }
    x = S.data[S.top];
    S.top--;
}

bool PopChar(SqStackChar &S, char &x)
{
    if (S.top == -1)
    {
        return false; // 代表栈空
    }
    x = S.data[S.top];
    S.top--;
}

bool GetTop(SqStack S, int &x)
{
    if (S.top == -1)
    {
        return false; // 代表栈空
    }
    x = S.data[S.top];
}

bool isEmpty(SqStack S)
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

bool isEmptyChar(SqStackChar S)
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

// 共享栈
typedef struct
{
    int data[MaxSize];
    int top[2];
} stk;

void Initstk(stk &s)
{
    s.top[0] = -1;
    s.top[1] = MaxSize;
}

bool stk_empty(stk s)
{
    if (s.top[0] + 1 == s.top[1])
    {
        return true; // 满
    }
    else
    {
        return false; // 不满
    }
}

/**
 * @param i i为0代表S1栈,i为1代表S2栈
 */
int push(stk &s, int i, int x)
{
    if (i != 0 || i != 1)
    {
        exit(0);
    }
    if (!stk_empty(s))
    {
        // 满
        return 0;
    }
    // switch的使用
    switch (i)
    {
    case 0:
        s.data[++s.top[0]] = x;
        return 1;
        break;

    case 1:
        s.data[--s.top[1]] = x;
        return 1;
        break;
    }
}

bool stk_top1_empty(stk s)
{
    if (s.top[0] == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stk_top2_empty(stk s)
{
    if (s.top[1] == MaxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int pop(stk &s, int i, int &x)
{
    if (i != 0 || i != 1)
    {
        exit(0);
    }
    if (stk_empty(s))
    {
        // 空
        return 0;
    }
    switch (i)
    {
    case 0:
        // 判空
        if (stk_top1_empty(s))
        {
            return -1;
        }
        else
        {
            x = s.data[s.top[0]--];
            return 1;
        }
        break;

    case 1:
        // 判空
        if (stk_top2_empty(s))
        {
            return -1;
        }
        else
        {
            x = s.data[s.top[1]++];
            return 1;
        }

        break;
    }
}

// 1 括号匹配
bool bracketCheck(char s[], int len)
{
    SqStackChar S;
    InitStackChar(S);

    // 遍历括号字符数组
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            // 左括号进行入栈
            PushChar(S, s[i]);
        }
        else
        {
            // 右括号出栈判断

            if (isEmptyChar(S))
            {
                return false; // 栈空,当前是右括号,是一种匹配失败的情况
            }

            char c1;
            PopChar(S, c1);
            if (s[i] == ')' && c1 != '(')
            {
                return false; // 匹配失败的情况
            }
            if (s[i] == ']' && c1 != '[')
            {
                return false; // 匹配失败的情况
            }
            if (s[i] == '}' && c1 != '{')
            {
                return false; // 匹配失败的情况
            }
        }
    }

    // 全部遍历结束后,如果栈不空,代表匹配失败的情况
    if (isEmptyChar(S))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool expressionCheck(char s[])
{
    SqStackChar S;
    InitStackChar(S);

    // 遍历括号字符数组
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            // 左括号进行入栈
            PushChar(S, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            // 右括号出栈判断

            if (isEmptyChar(S))
            {
                return false; // 栈空,当前是右括号,是一种匹配失败的情况
            }

            char c1;
            PopChar(S, c1);
            if (s[i] == ')' && c1 != '(')
            {
                return false; // 匹配失败的情况
            }
            if (s[i] == ']' && c1 != '[')
            {
                return false; // 匹配失败的情况
            }
            if (s[i] == '}' && c1 != '{')
            {
                return false; // 匹配失败的情况
            }
        }

        i++;
    }

    // 全部遍历结束后,如果栈不空,代表匹配失败的情况
    if (isEmptyChar(S))
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
    SqStack S;
    InitStack(S);

    // 1 括号匹配
    char s[5] = {'{', '[', '(', ')', ']'};
    int len = 5;
    bool res = bracketCheck(s, len);
    if (res)
    {
        printf("success\n");
    }
    else
    {
        printf("failed\n");
    }

    // 2 表达式求值
    // 中缀转后缀,手算时左优先,保证结果唯一性
    // 中缀转前缀,手算时右优先,保证结果唯一性

    // 中缀转后缀,后缀表达式求值,借助栈实现

    // 3 递归调用 栈实现

    // 表达式验证
    char s1[11] = {'a', '+', 'b', '*', '(', 'c', '-', 'd', ')', '\0'};
    bool res1 = expressionCheck(s1);
    if (res1)
    {
        printf("success\n");
    }
    else
    {
        printf("failed\n");
    }

    return 0;
}
