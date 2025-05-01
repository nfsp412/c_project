#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct
{
    int data[MaxSize];
    int length = 0;
} SqList;

bool InsertList(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1 || L.length >= MaxSize)
    {
        return false;
    }

    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }

    L.data[i - 1] = e;

    L.length++;

    return true;
}

bool DeleteList(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }

    e = L.data[i - 1];

    //移动
    for (int j = i; j <= L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }

    L.length--;

    return true;
    
}

void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;

    // PrintList(L);

    int e1;
    scanf("%d", &e1); // 插入的元素

    bool res1 = InsertList(L, 2, e1);
    if (res1)
    {
        PrintList(L);
    }
    else
    {
        printf("false\n");
    }

    int i1;
    scanf("%d", &i1); // 删除的位置
    int e2;           // 被删除的元素
    bool res2 = DeleteList(L, i1, e2);
    if (res2)
    {
        PrintList(L);
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
