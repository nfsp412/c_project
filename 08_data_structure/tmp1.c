#include <stdio.h>

#define MaxSize 10

typedef int ElemType;

/**
 * 顺序表
 * 使用静态数组存储数据
 */
typedef struct
{
    ElemType data[MaxSize];
    int length; // 表示数据元素的个数
} SeqList;

/**
 * 初始化顺序表
 */
void InitList(SeqList *L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
        // (*L).data[i] = 0;
    }
    L->length = 0;
    // (*L).length = 0;
}

int main()
{
    // 声明顺序表
    SeqList L;
    // 初始化顺序表
    InitList(&L);

    // 验证初始化
    for (int i = 0; i < MaxSize; i++)
    {
        printf("%d\n", L.data[i]);
    }

    return 0;
}
