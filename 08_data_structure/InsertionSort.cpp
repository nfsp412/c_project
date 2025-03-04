#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 插入排序
// 直接插入排序代码实现

// 时间复杂度 最坏平均O(n2) 最好情况O(n)
// 空间复杂度 O(1)
// 稳定,算法简单

typedef struct
{
    int *elem;
    int len;
} SeqList;

void InitList(SeqList &L, int len)
{
    L.len = len;
    L.elem = (int *)malloc(sizeof(int) * L.len);
    srand(time(NULL));
    for (int i = 0; i < L.len; i++)
    {
        L.elem[i] = rand() % 100;
    }
}

void PrintList(SeqList L)
{
    for (int i = 0; i < L.len; i++)
    {
        printf("%3d", L.elem[i]);
    }
    printf("\n");
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void InsertionSort(int *a, int n)
{
    int i, j, insertVal;
    // 外层循环用于控制insertVal,即控制待插入的数据,因此从索引1开始
    for (i = 1; i < n; i++)
    {
        // 由于后面可能会把a[i]的值覆盖掉,所以临时变量insertVal保存待插入的数据
        insertVal = a[i]; 
        // 内层循环用于确定待插入数据应该插入的位置
        // 确定的方式就是循环和该数据之前的每一个数据进行对比
        // 只要没到头并且a[j]的值大于待插入数据,就一直向前寻找
        // 当我们找到a[j]的数据小于待插入数据insertVal时,就停下来不再向前
        for (j = i - 1; j >= 0 && a[j] > insertVal; j--)
        {
            a[j + 1] = a[j];//把前一个值覆盖后一个值,第一次循环时后一个值指的是j+1即i即insertVal值
        }
        // 停下后,最后把待插入的数据的值再覆盖回待插入的位置即可
        a[j + 1] = insertVal;
    }
}

int main()
{
    SeqList L;
    InitList(L, 10);

    // 固定
    int a[10] = {64, 94, 95, 79, 69, 84, 18, 22, 12, 78};
    memcpy(L.elem, a, sizeof(a));

    PrintList(L);

    InsertionSort(L.elem, L.len);

    PrintList(L);

    return 0;
}
