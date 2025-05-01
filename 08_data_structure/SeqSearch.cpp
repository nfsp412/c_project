#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 使用指针实现顺序表
 * 本质上还是使用数组存储,只不过使用指针来指向这个数组
 */
typedef struct
{
    int *elem;
    int length;
} SSTable;

void Init(SSTable &ST, int len)
{
    // 初始化长度赋值
    // 多申请的位置存储哨兵
    ST.length = len + 1;
    // 申请内存空间存储数据,申请的是一整块内存
    ST.elem = (int *)malloc(sizeof(int) * ST.length);

    // 使用随机数初始化顺序表
    srand(time(NULL));
    int i;
    for (i = 1; i < ST.length; i++)
    {
        ST.elem[i] = rand() % 10; // 随机数赋值
    }
}

/**
 * 打印顺序表
 */
void Print(SSTable ST)
{
    // 跳过哨兵从1开始打印
    // 这样使用者就不用考虑索引从0开始的问题了,比如使用者想打印1位置的元素,实际上数组索引对应的就是ST.elem[1]
    // 又比如使用者初始化长度是5,想打印5位置的元素,ST.elem[5]也没有数组越界,因为默认初始化的大小是6
    for (int i = 1; i < ST.length; i++)
    {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}

/**
 * 顺序表中进行顺序查找,查找key元素对应的索引
 */
int SearchSeq(SSTable ST, int key)
{
    // ST.elem[0] = key; // 待查找的元素存放在哨兵的索引位置上,即0索引位置上

    // int i;
    // // 从后向前遍历,最后一个元素的索引就是长度减一
    // for (i = ST.length - 1; ST.elem[i] != key; i--)
    //     ;
    // // 返回索引位置
    // return i;

    for (int i = 0; i < ST.length; i++)
    {
        if (ST.elem[i] == key)
        {
            return i;
        }
        
    }
    
}

// 顺序查找(王道书上的写法)
int Search_Seq(SSTable ST, int key)
{
    int i;
    for (i = 0; i < ST.length && ST.elem[i] != key; i++)
    {
        return i == ST.length ? -1 : i;
    }
}

// 顺序查找,带哨兵(王道书上的写法)
int Search_Seq_i(SSTable ST, int key)
{
    // 哨兵存储在数组索引0的位置
    ST.elem[0] = key;
    int i;
    for (i = ST.length; i < ST.elem[i] != key; i--)
    {
        return i; // 返回0代表失败(哨兵)
    }
}

void TestInit(SSTable &ST, int len)
{
    ST.length = len + 1;
    ST.elem = (int *) malloc(sizeof(int) * ST.length);
    for (int i = 0; i < ST.length; i++)
    {
        ST.elem[i] = i + 10;
    }
    
}

int main()
{
    SSTable ST;
    // 初始化顺序表 初始5个元素实际上是6个因为默认会多申请一个来存储哨兵 也就是说实际上length是6
    // Init(ST, 5);
    TestInit(ST, 5);
    // 打印
    Print(ST);

    // printf("%d\n", ST.length);
    // printf("%d\n", ST.elem[ST.length - 1]);

    // 顺序查找
    int pos = SearchSeq(ST, 11);
    printf("%d\n", pos);

    return 0;
}
