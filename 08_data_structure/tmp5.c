#include <stdio.h>
#include <stdlib.h>

#define InitSize 5

typedef int ElemType;

/**
 * 顺序表
 * 动态数组
 */
typedef struct
{
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList *L)
{
    L->data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L->length = 0;
    L->MaxSize = InitSize;
}

/**
 * 按位查找元素值
 * @param L 待查找的顺序表,不传地址
 * @param i 查找的位数,从1开始
 * @return 元素值
 */
ElemType GetElem(SeqList L, int i)
{
    return L.data[i - 1];
}

/**
 * 按元素值查找位数
 * @param L 待查找的顺序表,不传地址
 * @param e 待查找的元素值,没找到返回-1
 * @return 位数
 */
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.MaxSize; i++) //这里演示使用MaxSize,实际上应该使用length
    {
        if (L.data[i] == e) 
        {
            return i + 1;
        }
    }
    return -1;
    
}

int main()
{
    SeqList L;
    InitList(&L);
    for (int i = 0; i < L.MaxSize; i++)
    {
        printf("L[%d] = %d\n", i + 1, L.data[i]);
    }

    ElemType e = GetElem(L, 1);
    printf("%d\n", e);

    int l = LocateElem(L, 0);
    printf("%d\n", l);

    return 0;
}
