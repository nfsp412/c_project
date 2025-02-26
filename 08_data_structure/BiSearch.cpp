#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 顺序表,指针定义
 */
typedef struct
{
    int *elem;
    int len;
} SeqList;

/**
 * 初始化顺序表
 * 不使用哨兵
 */
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

/**
 * 遍历顺序表
 */
void PrintList(SeqList L)
{
    for (int i = 0; i < L.len; i++)
    {
        printf("%3d", L.elem[i]);
    }
    printf("\n");
}

/**
 * 比较两个元素大小
 * 前面减去后面,从小到大
 */
int compare(const void *left, const void *right)
{
    return *(int *)left - *(int *)right;
}

/**
 * 二分查找
 *
 */
int BiSearch(SeqList L, int e)
{
    int low = 0;          // 初始化低位索引0
    int high = L.len - 1; // 初始化高位索引len-1
    int mid;              // 定义中间索引
    while (low <= high)
    {
        // 只要low没有超过high就一直二分查找下去

        // 每次的二分查找都需要定义mid,mid就是二分
        mid = (low + high) / 2;

        // 判断是否找到了
        if (L.elem[mid] == e)
        {
            return mid + 1; // 返回mid的是索引,如果想返回位置,则返回mid+1即可
        }
        else if (L.elem[mid] > e)
        {
            // mid对应的数据大于e,代表e应该在左半边

            // 既然e在左半边,应该调整high高位
            high = mid - 1; // 为何减一,是因为既然mid对应的不等于e,那么理应从mid-1作为右边界
        }
        else if (L.elem[mid] < e)
        {
            // mid对应的数据小于e,代表e应该在右半边

            // 既然e在右半边,应该调整low低位
            low = mid + 1; // 为何加一,是因为既然mid对应的不等于e,那么理应从mid+1作为左边界
        }
    }

    // 跳出循环走到这里,证明没找到,返回-1代表没找到即可
    return -1;
}

int main()
{
    SeqList L;
    InitList(L, 10);

    qsort(L.elem, 10, sizeof(int), compare);

    PrintList(L);

    int x;
    scanf("%d", &x);
    int res = BiSearch(L, x);
    printf("%d\n", res);

    return 0;
}
