#include <stdio.h>
#include <stdlib.h>

// 分块查找

/**
 * 索引表
 */
typedef struct {
    int maxValue;//最大关键字
    int low;//分块的索引范围
    int high;//分块的索引范围
}Index;

/**
 * 顺序表
 */
typedef struct
{
    int *elem;
    int len;
} SeqList;

int main()
{
    return 0;
}