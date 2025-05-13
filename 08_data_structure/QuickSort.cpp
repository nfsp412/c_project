#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 快速排序,也是交换排序的一种

// 时间复杂度 最好平均O(nlogn) 最坏情况O(n2)
// 空间复杂度 O(logn)
// 不稳定,算法复杂

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
 * 快排方法的核心,用于找到分割点的索引下标
 * @param arr 待排序数组
 * @param low 代表低位索引,初始时是0
 * @param high 代表高位索引,初始时是len-1
 * @return 返回分割点的索引下标
 */
int Partition(int *arr, int low, int high)
{
    // 每次固定把低位索引low的元素设置为分割点元素,初始时是0位置
    int t = arr[low];
    // low严格小于high
    while (low < high)
    {
        // 先从高位寻找
        while (low < high && arr[high] >= t)
        {
            high--;
        }
        // 找到待交换的数据,将低位赋值为找到的数据
        // 即使覆盖了分割点数据也没事,因为分割点数据在进入循环之前已经保存到t了
        arr[low] = arr[high];

        while (low < high && arr[low] <= t)
        {
            low++;
        }
        arr[high] = arr[low];
    }

    // 每一轮比较结束后,将分割点数据覆盖回低位
    arr[low] = t;

    // 返回分割点的索引下标
    return low;
}

int Partition_(int *a, int low, int high)
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
    swap(a[low], a[t]);

    return low;
}

/**
 * 快速排序
 * @param arr 待排序的数组
 * @param low 代表低位索引,初始时是0
 * @param high 代表高位索引,初始时是len-1
 */
void QuickSort(int *arr, int low, int high)
{

    if (low < high)
    {
        // 找到low和high相遇时所在的分割点
        // 对于升序排列,要保证pos左边的数据小于分割点数据,右边的数据大于分割点的数据
        int pos = Partition(arr, low, high);
        // int pos = Partition_(arr, low, high);
        
        // 没用注释掉
        // printf("first\n");
        // for (int i = 0; i < 10; i++)
        // {
        //     printf("%3d", arr[i]);
        // }
        // printf("\n");
        // return ;

        // 针对左边和右边各自再次递归调用快排方法,分治
        QuickSort(arr, low, pos - 1);
        QuickSort(arr, pos + 1, high);
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

    QuickSort(L.elem, 0, L.len - 1);

    PrintList(L);//12 18 22 64 69 78 79 84 94 95

    return 0;
}
