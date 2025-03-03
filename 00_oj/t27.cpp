#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int &i, int &j)
{
    int t;
    t = i;
    i = j;
    j = t;
}

void BubbleSort(int *a, int n)
{
    bool flag;
    for (int i = 1; i <= n - 1; i++)
    {
        flag = false;
        for (int j = 1; j <= n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                flag = true;
            }
        }
        if (flag == false)
        {
            return;
        }
    }
}

int Partitions(int *a, int low, int high)
{
    int t = low;
    while (low < high)
    {
        while (low < high && a[high] >= a[t])
        {
            high--;
        }
        while (low < high && a[low] <= a[t])
        {
            low++;
        }
        swap(a[low], a[high]);
    }
    swap(a[t], a[low]);
    return low;
}

void QuickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pos = Partitions(a, low, high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}

void InsertSort(int *a, int n)
{
    int i, j, insertVal;
    for (i = 1; i <= n - 1; i++)
    {
        insertVal = a[i];
        for (j = i - 1; j >= 0 && a[j] > insertVal; j--)
        {
            a[j + 1] = a[j]; // 01来看,应该是索引0数据覆盖掉索引1数据
        }
        // 01来看,应该是插入数据覆盖掉索引0数据
        // 但是上面j--了,所以此时j不是1而是-1,所以下面是j+1而不是j,因为j+1此时等于0
        a[j + 1] = insertVal;
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
    BubbleSort(b1, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%3d", b1[i]);
    }
    printf("\n");

    int b2[10];
    memcpy(b2, a, sizeof(a));
    QuickSort(b2, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%3d", b2[i]);
    }
    printf("\n");

    int b3[10];
    memcpy(b3, a, sizeof(a));
    InsertSort(b3, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%3d", b3[i]);
    }
    printf("\n");

    // <n 和 <=n-1 是一样的
}
