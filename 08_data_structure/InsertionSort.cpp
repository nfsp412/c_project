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
        if (a[i] < a[i - 1])
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
}

/**
 * 带哨兵版本
 * 将a[0]作为哨兵
 */
void InsertionSort_t(int *a, int n)
{
    int i, j, insertVal;
    // 外层循环用于控制insertVal,即控制待插入的数据,因此从索引1开始
    for (i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
        {
            // 由于后面可能会把a[i]的值覆盖掉,所以临时变量insertVal保存待插入的数据
            a[0] = a[i]; 
            // 内层循环用于确定待插入数据应该插入的位置
            // 确定的方式就是循环和该数据之前的每一个数据进行对比
            // 只要没到头并且a[j]的值大于待插入数据,就一直向前寻找
            // 当我们找到a[j]的数据小于待插入数据insertVal时,就停下来不再向前
            for (j = i - 1; a[j] > a[0]; j--)
            {
                a[j + 1] = a[j];//把前一个值覆盖后一个值,第一次循环时后一个值指的是j+1即i即insertVal值
            }
            // 停下后,最后把待插入的数据的值再覆盖回待插入的位置即可
            a[j + 1] = a[0];
        }
    }
}

/**
 * 优化 折半插入排序
 */
void InsertionSort_b(int *a, int n)
{
    int i, j, insertVal;
    int low, high, mid;
    // 外层循环用于控制insertVal,即控制待插入的数据,因此从索引1开始
    for (i = 1; i < n; i++)
    {
        insertVal = a[i]; 

        // 当 a[mid] == insertVal 时,不停止二分查找,继续二分,为了保证稳定性
        // 找到插入位置后,向后移动[low, i - 1]或者[high + 1, i - 1],再插入元素
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[mid] > insertVal)
            {
                high = mid - 1;
            }else {
                low = mid + 1;//包含了相等的条件
            }
        }
        for (j = i - 1; j >= low; j--)
        {
            a[j + 1] = a[j];
        }
        a[low] = insertVal;   
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

    InsertionSort(L.elem, L.len);       //12 18 22 64 69 78 79 84 94 95
    // InsertionSort_b(L.elem, L.len);  //12 18 22 64 69 78 79 84 94 95
    
    PrintList(L);
    
    // InsertionSort_t(L.elem, L.len);
    
    return 0;
}
