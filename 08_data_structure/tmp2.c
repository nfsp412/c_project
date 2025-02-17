#include <stdio.h>

#define MaxSize 10

/**
 * 顺序表
 * 静态数组
 */
typedef struct
{
    int data[MaxSize]; // 数组用于存储数据
    int length;        // 顺序表元素个数
} SeqList;

/**
 * 初始化顺序表
 * 不初始化为0
 */
void InitList(SeqList *L)
{
    L->length = 0;
}

int main()
{
    // 声明顺序表
    SeqList L;
    // 初始化顺序表
    InitList(&L);

    // 验证初始化,有脏数据,改为L.length
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }

    return 0;
}
