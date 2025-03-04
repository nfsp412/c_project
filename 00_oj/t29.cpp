#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void SelectSort(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(a[i], a[min]);
        }
    }
}

void AdjustDown(int *a, int d, int n)
{
    int dad = d;
    int son = dad * 2 + 1;

    while (son < n)
    {
        if (son + 1 < n && a[son] < a[son + 1])
        {
            son++;
        }

        if (a[dad] < a[son])
        {
            swap(a[dad], a[son]);

            dad = son;
            son = dad * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *a, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        AdjustDown(a, i, n);
    }
    swap(a[0], a[n - 1]);

    // n-1代表当前剩余的无序数据的数量,最少2
    for (i = n - 1; i > 1; i--)
    {
        AdjustDown(a, 0, i);
        swap(a[0], a[i - 1]);
    }
}

void Merge(int *a, int low, int mid, int high)
{
    static int b[10];
    int i, j, k;
    // 复制临时数组b用于遍历 注意不是a完整数组
    for (k = low; k <= high; k++)
    {
        b[k] = a[k];
    }

    // 合并数组
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (b[i] <= b[j])
        {
            a[k] = b[i++];
        }
        else
        {
            a[k] = b[j++];
        }
    }
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
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int a[10];
    int x;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x);
        a[i] = x;
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%3d", a[i]);
    // }
    // printf("\n");

    int b1[10];
    memcpy(b1, a, sizeof(a));
    MergeSort(b1, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%3d", b1[i]);
    }
    printf("\n");

    return 0;
}
