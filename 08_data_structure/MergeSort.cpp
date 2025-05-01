#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 归并排序
// kaoyan中要求两两排序
// 时间复杂度 O(nlogn) 最好最坏平均
// 空间复杂度 O(n)
// 稳定,算法复杂

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
 * 两两合并成数组
 * 这个两两,指的是两个数组合并成新的有序数组
 */
void Merge(int *a, int low, int mid, int high)
{
    static int b[10];
    // 将a复制到b
    int i, j, k;
    for (k = low; k <= high; k++)
    {
        b[k] = a[k];
    }

    // 合并两个有序数组的方法
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (b[i] <= b[j])
        {
            // 如果i的数据小,那应该把i取出来赋值,然后i++
            a[k] = b[i++];
        }
        else
        {
            a[k] = b[j++];
        }
    }
    // 奇数个的场景下,剩余的元素最后也要添加到数组中
    while (i <= mid)
    {
        a[k++] = b[i++];
    }
    while (j <= high)
    {
        a[k++] = b[j++];
    }
}

void MergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        // 当递归到只剩下两个元素时,下面两个递归就进不去了,会走到Merge方法,合并两个元素到数组中
        // 此时low=0,high=1,mid=0
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
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

    MergeSort(L.elem, 0, L.len - 1);

    PrintList(L);

    return 0;
}