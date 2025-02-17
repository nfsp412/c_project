#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10

/**
 * 顺序表
 * 静态数组,演示insert和delete
 */
typedef struct
{
    int data[MaxSize]; // 数组用于存储数据
    int length;        // 顺序表元素个数
} SeqList;

/**
 * 初始化顺序表,不初始化为0
 */
void InitList(SeqList *L)
{
    L->length = 0;
}

/**
 * 插入元素
 * @param i 下标,从1开始,对应索引0
 * @param e 元素
 */
bool ListInsert(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1) // 代表不能跳跃式的插入元素
    {
        return false;
    }

    if (L->length >= MaxSize)
    {
        return false;
    }

    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }

    L->data[i - 1] = e;

    L->length++;

    return true;
}

/**
 * 删除元素
 * @param i 下标,从1开始,对应索引0
 * @return 被删除的元素
 */
bool ListDelete(SeqList *L, int i, int *e)
{
    if (i < 1 || i > L->length)
    {
        return false;
    }

    *e = L->data[i - 1];

    for (int j = i; j < L->length; j++) // 最后一个元素无需移动,所以j < L.length
    {
        L->data[j - 1] = L->data[j];
    }

    L->length--;

    return true;
}

int main()
{
    // 声明顺序表
    SeqList L;
    // 初始化顺序表
    InitList(&L);
    // 插入元素
    int i = 1;
    int e = 100;
    ListInsert(&L, i, e);

    // 验证
    printf(">before\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }

    // 多插入一些元素
    ListInsert(&L, 2, 200);
    ListInsert(&L, 3, 300);
    printf(">after\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }

    // 插入已有元素位置
    printf(">insert\n");
    ListInsert(&L, 2, 20);
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }

    // 删除元素
    printf(">delete\n");
    int d;
    ListDelete(&L, 2, &d);
    printf("delete is %d\n", d);
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }

    return 0;
}
