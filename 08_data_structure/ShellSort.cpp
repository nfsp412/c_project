#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 希尔排序

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

void ShellSort(int *a, int n)
{
    int d, i, j;
    int insertVal;
    //外层循环,控制d的变化,每次减半,直到1
    for (d = n / 2; d >= 1; d = d / 2)
    {
        //这层循环相当于插入排序的外层循环
        //假设d=4,那么按照希尔排序规则,索引1和索引5是同一个子表,按照插入排序规则,从索引5开始比较
        // for (i = d + 1; i <= n; i++)
        for (i = d; i <= n; i++)//实际上这里的i++并不符合我们对于该算法的直观理解,但是这样写是正确的
        {
            if (a[i] < a[i - d])
            {
                // a[0] = a[i];//a[0]不是哨兵,只是用来暂存数据的
                insertVal = a[i];//a[0]不是哨兵,只是用来暂存数据的
                //这层循环相当于插入排序的内层循环
                // for (j = i - d; j >= 0 && a[j] > a[0]; j = j - d)
                for (j = i - d; j >= 0 && a[j] > insertVal; j = j - d)
                {
                    a[j + d] = a[j];
                }
                // a[j + d] = a[0]; 
                a[j + d] = insertVal; 
            }
        }
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

    ShellSort(L.elem, L.len);       //12 18 22 64 69 78 79 84 94 95
    
    PrintList(L);
    
    return 0;
}
