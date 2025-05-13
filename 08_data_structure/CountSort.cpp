#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 计数排序

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

/**
 * @param a 待排序数组
 * @param b 输出数组
 * @param n a数组长度
 * @param k a数组的元素的取值范围
 */
void CountSort(int *a, int *b, int n, int k)
{
    int i;
    int c[k];
    //辅助数组c进行初始化
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }
    //遍历a数组,统计次数,记录在c数组
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    //再次遍历辅助数组c进行处理
    //这里从索引1开始处理
    for (int i = 1; i < k; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    //再次遍历辅助数组c进行计数排序
    //从后往前处理,从n-1开始处理
    for (i = n - 1; i >= 0; i--)
    {
        //先查询到c的值并自减
        c[a[i]]--;
        //再插入到b中
        b[c[a[i]]] = a[i];
    }
}

int main()
{
    SeqList L;
    InitList(L, 10);

    SeqList Lb;
    InitList(Lb, 10);

    // 固定
    int a[10] = {1, 3, 3, 2, 4, 5, 7, 7, 3, 6};
    memcpy(L.elem, a, sizeof(a));

    PrintList(L);

    CountSort(L.elem, Lb.elem, L.len, 8);//传入c=8是因为0到7一共8长度

    //   1   2   3   3   3   4   5   6   7   7
    PrintList(Lb);
    
    return 0;
}
