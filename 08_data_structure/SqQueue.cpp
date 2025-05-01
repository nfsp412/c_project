#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true; // 只有在初始化时front和rear才会相等,其余的时间不会相等,rear指向的是当前队列最后元素的下一个位置,front指向的是当前队列第一个元素
    }
    else
    {
        return false;
    }
}

bool EnQueue(SqQueue &Q, ElemType e)
{
    // 判断是否已满的条件,假设front一直为0没有出队列,rear最多也要和front差一位,所以当rear计算后和front相等时,代表队列已满
    if (Q.front == (Q.rear + 1) % MaxSize)
    {
        return false;
    }

    Q.data[Q.rear] = e;              // 入队列
    Q.rear = (Q.rear + 1) % MaxSize; // 由0改为1
    return true;
}

/**
 * 使用引用把出队列元素带回
 */
bool DeQueue(SqQueue &Q, ElemType &e)
{
    if (Q.front == Q.rear)
    {
        return false; // 代表刚初始化,还未添加元素,只要添加哪怕一个元素,front和rear就不会再相等
    }

    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; // 由0改为1,和rear是一样的计算方式
    return true;
}

void PrintQueue(SqQueue Q)
{
    for (int i = 0; i < MaxSize; i++)
    {
        printf("%3d", Q.data[i]);
    }
    printf("\n");
    
}

int main()
{
    // 删除的一端叫队头,front,或者说出队列的一端
    // 插入的一端叫队尾,rear,或者说入队列的一端
    // 先进先出
    // 如果用顺序表,即数组实现,那么看似是一个管道的队列,实际上是数组的循环赋值取值这样使用的,也就是循环队列

    SqQueue Q;

    InitQueue(Q);

    EnQueue(Q, 33);
    EnQueue(Q, 24);
    EnQueue(Q, 57);

    // PrintQueue(Q);

    int e1;
    DeQueue(Q, e1);
    printf("%d\n", e1);
    // PrintQueue(Q);

    return 0;
}
