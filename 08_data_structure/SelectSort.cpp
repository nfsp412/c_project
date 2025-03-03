#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 选择排序

// 简单选择排序

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
    // n个元素只需要比较n-1轮,这里初始化i=0
    for (int i = 0; i < n - 1; i++)
    {
        // 每一轮的比较,默认初始化设置min的值是首个数据,例如第一轮,i=0
        int min = i;
        // 每一轮的选择,实际上从i+1开始,例如第一轮的选择,j从1开始,第二轮时,j从2开始
        for (int j = i + 1; j < n; j++)
        {
            // 对于升序场景,如果出现了新的min数据,就把min数据对应的索引进行变更
            if (a[min] > a[j])
            {
                // min索引进行变更,这就是选择排序,每次都能选择出来最小的数据的索引
                min = j;
            }
        }

        // 如果min没发生过变更,就不用交换
        if (min != i)
        {
            // 结束一轮的比较后,交换首个数据和min对应数据
            swap(a[min], a[i]);
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

    SelectSort(L.elem, L.len);

    PrintList(L);

    return 0;
}
