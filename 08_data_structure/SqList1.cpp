#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 静态分配

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void InitSqList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

void PrintSqList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}

bool InsertSqList(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1 || L.length == MaxSize)
    {
        return false;
    }

    // 从最后一个元素开始移动
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.data[j + 1] = L.data[j];
    }
    L.data[i - 1] = e;
    L.length++;

    return true;
}

bool DeleteSqList(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }

    e = L.data[i - 1];

    // 从i位置开始移动
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;

    return true;
}

ElemType FindElemByIndex(SqList L, int i)
{
    if (i < 1 || i > L.length)
    {
        return -1;
    }

    return L.data[i - 1];
}

int FindIndexByElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if ((ElemType)L.data == e)
        {
            return i + 1;
        }
    }
}

// 动态分配

// #define InitSize 10

// typedef struct
// {
//     int *data;
//     int MaxSize;
//     int length;
// } SeqList;

// void InitSeqList(SeqList &L)
// {
//     L.data = (int *)malloc(sizeof(int) * InitSize);
//     L.length = 0;
//     L.MaxSize = InitSize;
// }

// void PrintSeqList(SeqList L)
// {
//     for (int i = 0; i < L.length; i++)
//     {
//         printf("%3d", L.data[i]);
//     }
//     printf("\n");
// }

// void IncreaseSeqList(SeqList &L, int n)
// {
//     // 复制临时数组
//     int *t = L.data;
//     // 申请新内存
//     L.data = (int *)malloc(sizeof(int) * (L.MaxSize + n));
//     // 元素拷贝
//     for (int i = 0; i < L.length; i++)
//     {
//         L.data[i] = t[i];
//     }
//     L.MaxSize += n;
//     // 释放临时指针
//     free(t);
// }

bool f1(SqList &L, ElemType &e)
{
    if (L.length == 0)
    {
        printf("L is empty\n");
        return false;
    }

    int min = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < L.data[min])
        {
            min = i;
            e = L.data[i];
        }
    }
    // 放外面 放里面就错了,每次遇到小的值都会被覆盖掉
    L.data[min] = L.data[L.length - 1];
    L.length--;
    return true;
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void f2(SqList &L)
{
    for (int i = 0; i < L.length / 2; i++)
    {
        swap(L.data[i], L.data[L.length - 1 - i]);
    }
}

// 要求时间复杂度O(n)
void f3(SqList &L, ElemType x)
{
    // O(n^2)
    //  for (int i = 0; i < L.length; i++)
    //  {
    //      if ((ElemType)L.data[i] == x)
    //      {
    //          //删除
    //          for (int j = i; j < L.length; j++)
    //          {
    //              L.data[i] = L.data[i + 1];
    //          }
    //          L.length--;
    //      }

    // }

    // O(n)
    int k = 0; // k用于记录不重复元素个数
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k; // 重新赋值length
}

bool f4(SqList &L, int s, int t)
{
    if (s >= t)
    {
        return false;
    }
    if (L.length == 0)
    {
        return false;
    }

    //
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < s || L.data[i] > t)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 去重
void f5(SqList &L)
{
    printf("DelRepeat\n");

    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != L.data[i + 1])
        {
            // 没遇到重复的
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 合并两个数组
// 典型方法需要掌握
void f6(SqList L1, SqList L2, SqList &L)
{
    int k = 0;
    int i, j;
    for (i = 0, j = 0; i < L1.length, j < L2.length;)
    {
        if (L1.data[i] < L2.data[j])
        {
            // L1<L2,插入L1
            L.data[k] = L1.data[i];
            i++;
            k++;
        }
        else if (L1.data[i] >= L2.data[j]) // 边界问题注意,等号得有归属
        {
            // L2<L1,插入L2
            L.data[k] = L2.data[j];
            j++;
            k++;
        }
    }
    while (i <= L1.length - 1)
    {
        L.data[k] = L1.data[i];
        i++;
        k++;
    }
    while (j <= L2.length - 1)
    {
        L.data[k] = L2.data[j];
        j++;
        k++;
    }

    L.length = k;
}

void f7(int *a, int m, int n, int len)
{
    // 翻转整体
    for (int i = 0; i < len / 2; i++)
    {
        swap(a[i], a[len - 1 - i]);
    }

    // 翻转前m部分
    for (int i = 0; i < m / 2; i++)
    {
        swap(a[i], a[m - 1 - i]);
    }

    // 翻转后n部分
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i + m], a[len - 1 - i]);
    }
}

void PrintArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

int BiSearch(SqList L, ElemType e)
{

    int low = 0;
    int high = L.length - 1;
    int mid;
    while (low <= high)
    {
        // 二分
        mid = (low + high) / 2;

        if (L.data[mid] < e)
        {
            // e在右边
            low = mid + 1;
        }
        else if (L.data[mid] > e)
        {
            // e在左边
            high = mid - 1;
        }
        else
        {
            // 找到e
            return mid;
        }
    }
    return -1; // 没找到
}

void Insert1(SqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (e < L.data[i])
        {
            // 插入
            InsertSqList(L, i + 1, e);
            break;
        }
    }
}

int max(int a1, int a2)
{
    return a1 >= a2 ? a1 : a2;
}

void f9(int *a1, int *a2, int *a3, int len)
{
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < len && j < len && k < len;)
    {
        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            printf("%d\n", a1[i]);
            i++;
            j++;
            k++;
        }
        else
        {
            // 找到max
            int t = max(a1[i], max(a2[j], a3[k]));
            // 三次if比较来移动索引
            if (a1[i] < t)
            {
                i++;
            }
            if (a2[j] < t)
            {
                j++;
            }
            if (a3[k] < t)
            {
                k++;
            }
        }
    }
}

// 左移
void f10(int *a, int p, int n)
{
    p = n - p;
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }
    for (int i = 0; i < p / 2; i++)
    {
        swap(a[i], a[p - 1 - i]);
    }
    for (int i = 0; i < (n - p) / 2; i++)
    {
        swap(a[i + p], a[n - 1 - i]);
    }
}

// 右移
void RemoveRight(int *a, int p, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }
    for (int i = 0; i < p / 2; i++)
    {
        swap(a[i], a[p - 1 - i]);
    }
    for (int i = 0; i < (n - p) / 2; i++)
    {
        swap(a[i + p], a[n - 1 - i]);
    }
}

// 找合并后中位数
int f11(int *a1, int *a2, int len)
{
    int a1_low = 0;
    int a1_high = len - 1;
    int a1_mid;
    int a2_low = 0;
    int a2_high = len - 1;
    int a2_mid;
    while (a1_low < a1_high || a2_low < a2_high) // 区别1 < 而不是 <=
    {
        a1_mid = (a1_low + a1_high) / 2;
        a2_mid = (a2_low + a2_high) / 2;
        if (a1[a1_mid] == a2[a2_mid])
        {
            return a1[a1_mid];
        }
        else if (a1[a1_mid] < a2[a2_mid])
        {
            // 区别2 丢弃元素时 要保证剩余元素个数一致性
            //  舍弃a1低位 a2高位
            if ((a1_low + a1_high) % 2 == 0)
            {
                // 代表奇数个
                a1_low = a1_mid;
                a2_high = a2_mid;
            }
            else
            {
                // 代表偶数个
                a1_low = a1_mid + 1;
                a2_high = a2_mid;
            }
        }
        else
        {
            if ((a1_low + a1_high) % 2 == 0)
            {
                // 代表奇数个
                // 舍弃a1高位 a2低位
                a1_high = a1_mid;
                a2_low = a2_mid;
            }
            else
            {
                // 代表偶数个
                a1_high = a1_mid;
                a2_low = a2_mid + 1;
            }
        }
    }
    // 区别3 最后的返回不代表没找到,反而是代表找到了,只不过找到的中位数不相等,不相等时返回较小的
    return a1[a1_low] < a2[a2_low] ? a1[a1_low] : a2[a2_low];
}

// 寻找主元素 主元素最多一个,因为主元素的定义是个数多于总数一半以上的元素 最优解 难理解
int f12(int *a, int len)
{
    int maybe = a[0]; // 标记第一个元素
    int count = 1;    // 初始化出现次数
    for (int i = 1; i < len; i++)
    {
        // 从第二个元素开始,和第一个元素maybe进行比较
        // 相同则count自增1
        if (a[i] == maybe)
        {
            count++;
        }
        else
        {
            // 如果不等
            if (count > 0)
            {
                count--;
            }
            else
            {
                // 如果count次数已经减小到0了,更换一个maybe进行比较
                maybe = a[i];
                // 重新从1开始计数
                count = 1;
            }
        }
    }
    // 再遍历一次 统计maybe的真正次数
    count = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == maybe)
        {
            count++;
        }
    }

    // 判断是否是主元素
    if (count > len / 2)
    {
        return maybe;
    }
    else
    {
        return -1;
    }
}

int Partition(int *a, int low, int high)
{
    int tmp = low;
    while (low < high)
    {
        while (low < high && a[high] >= a[tmp])
        {
            high--;
        }
        while (low < high && a[low] <= a[tmp])
        {
            low++;
        }
        swap(a[low], a[high]);
    }
    swap(a[low], a[tmp]);

    return low;
}

void QuickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pos = Partition(a, low, high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}

int PrimeElem1(int *a, int len)
{
    // 先排序
    QuickSort(a, 0, len - 1);
    // PrintArray(a, len);

    // 再统计
    int current = a[0];
    int count = 1;
    int max_elem = current;
    int max_count = 1;
    for (int i = 1; i < len; i++)
    {
        if (current == a[i])
        {
            count++;
        }
        else
        {
            if (count > max_count)
            {
                max_count = count;  // 更新 max count
                max_elem = current; // 更新 max elem
            }
            // 变更比较元素
            current = a[i];
            count = 1;
        }
    }

    // 最后判断是否是主元素
    if (max_count > len / 2)
    {
        return max_elem;
    }
    else
    {
        return -1;
    }
}

// 时间复杂度 平均O(nlogn) 未优化快排算法
int f13(int *a, int len)
{
    // 先TM排个序
    QuickSort(a, 0, len - 1);
    PrintArray(a, len);

    // 遍历寻找最小正整数
    int expected = 1;
    for (int i = 0; i < len; i++)
    {
        if (a[i] > 0)
        {
            if (a[i] == expected)
            {
                // go on
                expected++;
            }
            else if (a[i] > expected)
            {
                break;
            }
        }
    }

    return expected;
}

// 以空间换时间 时间复杂度 O(n)
int f13_1(int A[], int n)
{
    int i;
    int *B;
    // 分配内存
    B = (int *)malloc(sizeof(int) * n);

    // 初始化
    memset(B, 0, sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
        {
            B[A[i] - 1] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (B[i] == 0)
        {
            break;
        }
    }
    return i + 1;
}

int main()
{
    // SqList L;
    // InitSqList(L);

    // L.data[0] = 0;
    // L.data[1] = 1;
    // L.data[2] = 2;
    // L.data[3] = 3;
    // L.data[4] = 4;
    // L.data[5] = 5;
    // L.length = 5;

    // PrintSqList(L);

    // InsertSqList(L, 3, 33);

    // PrintSqList(L);

    // InsertSqList(L, 7, 77);
    // PrintSqList(L);

    // InsertSqList(L, 8, 88);
    // InsertSqList(L, 9, 99);
    // InsertSqList(L, 10, 102);
    // PrintSqList(L);

    // // bool res = InsertSqList(L, 10, 1);
    // bool res = InsertSqList(L, 9, 1);
    // if (res)
    // {
    //     printf("true\n");
    // }
    // else
    // {
    //     printf("false\n");
    // }
    // PrintSqList(L);

    // int e;
    // DeleteSqList(L, 3, e);
    // PrintSqList(L);

    // printf("%d\n", FindElemByIndex(L, 1));
    // printf("%d\n", FindIndexByElem(L, 102));

    // SeqList L;
    // InitSeqList(L);

    // L.data[0] = 1;
    // L.data[1] = 1;
    // L.data[2] = 1;
    // L.data[3] = 1;
    // L.data[4] = 1;
    // L.data[5] = 1;
    // L.data[6] = 1;
    // L.data[7] = 1;
    // L.data[8] = 1;
    // L.data[9] = 1;
    // L.length = 10;

    // PrintSeqList(L);

    // IncreaseSeqList(L, 5);

    // L.data[10] = 2;
    // L.data[11] = 2;
    // L.length = 12;

    // PrintSeqList(L);

    // 以下习题 2.2.3
    //  SqList L;
    //  InitSqList(L);

    // L.data[0] = 0;
    // L.data[1] = 1;
    // L.data[2] = 2;
    // L.data[3] = 3;
    // L.data[4] = 4;
    // L.length = 5;

    // int e;
    // DelMin(L, e);
    // PrintSqList(L);

    // ReverseList(L);
    // PrintSqList(L);

    // SqList L1;
    // L1.data[0] = 1;
    // L1.data[1] = 0;
    // L1.data[2] = 1;
    // L1.data[3] = 0;
    // L1.data[4] = 1;
    // L1.length = 5;
    // PrintSqList(L1);
    // DelAllX(L1, 0);
    // PrintSqList(L1);

    // SqList L2;
    // L2.data[0] = 1;
    // L2.data[1] = 0;
    // L2.data[2] = 3;
    // L2.data[3] = 0;
    // L2.data[4] = 2;
    // L2.length = 5;
    // PrintSqList(L2);
    // DelRange(L2, 2, 5);
    // PrintSqList(L2);

    // SqList L3;
    // L3.data[0] = 1;
    // L3.data[1] = 2;
    // L3.data[2] = 2;
    // L3.data[3] = 2;
    // L3.data[4] = 2;
    // L3.data[5] = 3;
    // L3.data[6] = 3;
    // L3.data[7] = 3;
    // L3.data[8] = 4;
    // L3.data[9] = 4;
    // L3.data[10] = 5;
    // L3.length = 11;
    // PrintSqList(L3);
    // DelRepeat(L3);
    // PrintSqList(L3);

    // SqList L1;
    // L1.data[0] = 1;
    // L1.data[1] = 4;
    // L1.data[2] = 7;
    // L1.length = 3;
    // SqList L2;
    // L2.data[0] = 1;
    // L2.data[1] = 5;
    // L2.data[2] = 6;
    // L2.length = 3;
    // SqList L3;
    // Merge(L1, L2, L3);
    // PrintSqList(L3);

    // int a[5] = {1, 2, 3, 4, 5};
    // ExchangeAB(a, 4, 1, 5);
    // PrintArray(a, 5);

    // SqList L1;
    // L1.data[0] = 1;
    // L1.data[1] = 4;
    // L1.data[2] = 7;
    // L1.data[3] = 8;
    // L1.data[4] = 11;
    // L1.data[5] = 15;
    // L1.data[6] = 23;
    // L1.length = 7;

    // int index = BiSearch(L1, 10);
    // if (index != -1)
    // {
    //     printf("%d\n", index);
    //     //交换
    //     swap(L1.data[index], L1.data[index + 1]);
    // }else{
    //     //插入
    //     Insert1(L1, L1.data[index]);
    // }
    // PrintSqList(L1);

    // int a1[3] = {1, 2, 3};
    // int a2[3] = {2, 3, 4};
    // int a3[3] = {-1, 0, 2};
    // ThreeEqual(a1, a2, a3, 3);

    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // RemoveLeft(a, 3, 10);
    // PrintArray(a, 10);

    // int a1[5] = {11, 13, 15, 17, 19};
    // int a2[5] = {2, 4, 6, 8, 20};
    // int len = 5;
    // printf("%d\n", MiddleNumber(a1, a2, len));

    // int a[8] = {5, 0, 3, 5, 7, 5, 5, 5};
    // int len = 8;
    // // printf("%d\n", PrimeElem(a, len));
    // printf("%d\n", PrimeElem1(a, len));

    // int a[5] = {6, 3, 2, 1};
    // printf("%d\n", MinNum(a, 4));
    // printf("%d\n", findMissMin(a, 4));

    return 0;
}
