#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 // 初始容量

/**
 * 顺序表
 * 动态数组
 */
typedef struct
{
    int *data;   // 使用指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表当前元素个数
} SeqList;

/**
 * 初始化顺序表
 * 动态分配内存
 */
void InitList(SeqList *L)
{
    (*L).data = (int *)malloc(InitSize * sizeof(int));
    (*L).length = 0;
    (*L).MaxSize = InitSize;
}

/**
 * 顺序表进行扩容
 * @param L
 * @param len 要扩容的长度
 */
void IncreaseSize(SeqList *L, int len)
{
    int *p = L->data;
    // 顺序表扩容为 MaxSize + len
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i]; // 数据复制到新数组中
    }
    L->MaxSize = L->MaxSize + len;
    // 释放内存
    free(p);
}

int main()
{
    // 声明顺序表
    SeqList L;
    // 初始化顺序表
    InitList(&L);

    // 顺序表扩容
    IncreaseSize(&L, 5);

    // 验证初始化,不管脏数据,只验证效果
    for (int i = 0; i < L.MaxSize; i++)
    {
        printf("%d\n", L.data[i]);
    }

    return 0;
}
