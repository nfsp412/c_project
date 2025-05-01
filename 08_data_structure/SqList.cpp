#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

/**
 * 静态分配
 */
typedef struct
{
    ElemType data[MaxSize];
    int length = 0;
} SqList;

void PrintSqList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%3d", L.data[i]);
    }
}

/**
 * 插入元素到指定位置
 * i从1开始
 * length和索引的关系为 最大索引 = length - 1
 * i和索引的关系为 索引 = i - 1
 * 插入的i和length的关系为 1 <= i <= length + 1 代表着插入元素时中间不能空着
 */
bool InsertSqList(SqList &L, int i, ElemType e)
{
    if (L.length == MaxSize || i < 1 || i > L.length + 1)
    {
        return false;
    }

    // 元素后移
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // 将 length - 1 索引位置的元素后移到 length 索引的位置
    }

    // 元素插入
    L.data[i - 1] = e;

    // 长度自增
    L.length++;

    return true;
}

/**
 * 删除指定位置元素
 */
bool DeleteSqList(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }

    // 被删除元素
    e = L.data[i - 1];

    // 元素前移
    for (int j = i; j < L.length; j++)
    {
        // 将 i + 1 位置上的元素移动到 i 的位置上
        // 对应的索引就是[j]->[j-1]
        L.data[j - 1] = L.data[j];
    }

    L.length--;

    return true;
}

/**
 * 查找元素所在的位置,非索引
 * 找到返回,没找到返回0
 */
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
        
    }

    return 0;
    
}

int main()
{
    // 声明
    SqList L;

    // 测试
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;

    // 打印
    PrintSqList(L);

    // 插入
    bool res1 = InsertSqList(L, 2, 100);
    // bool res = InsertSqList(L, -3, 100);
    // bool res = InsertSqList(L, 5, 100);
    if (res1)
    {
        printf("true\n");
    }

    // 再打印
    PrintSqList(L);

    // 删除
    ElemType e1;
    // DeleteSqList(L, 4, e1);
    // DeleteSqList(L, 2, e1);
    // DeleteSqList(L, 1, e1);
    bool res2 = DeleteSqList(L, 5, e1);
    if (res2)
    {
        printf("true\n");
    }

    // 再打印
    printf("del %d\n", e1);
    PrintSqList(L);

    // 查询元素的位置(非索引)
    int loc = LocateElem(L, 100);
    printf("loc %d\n", loc);

    return 0;
}
