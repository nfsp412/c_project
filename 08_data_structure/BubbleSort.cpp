#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * 使用指针定义顺序表做演示
 */
typedef struct
{
    int *elem;
    int len;
} SeqList;

void InitList(SeqList &L, int len)
{
    L.len = len;
    srand(time(NULL));
    L.elem = (int *)malloc(sizeof(int) * L.len);
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

void swap(int &i, int &j)
{
    int t;
    t = i;
    i = j;
    j = t;
}

void BubbleSort(int arr[], int n)
{
    // 外层循环代表一共需要比较的轮数,例如1个数字需要比较0轮,2个数字需要比较1轮,3个数字需要比较2轮,n个数字需要比较n-1轮

    for (int i = 1; i <= n - 1; i++)
    {
        // 内层循环代表每一轮需要比较的次数,例如一共3个数字,第一轮的内层循环需要比较2次,第二轮的内层循环需要比较1次,n个数字在第m轮需要比较n-m

        for (int j = 1; j <= n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

int main()
{
    SeqList L;
    InitList(L, 10);

    PrintList(L);

    BubbleSort(L.elem, L.len);

    PrintList(L);

    return 0;
}
