#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

// 队列

// 顺序表实现

// 队列元素个数 ( rear索引 + max_size - front索引 ) % max_size

typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
    // 单独定义队列元素个数来实现判空判满
    int size;
    // 单独定义tag标签来实现判空判满,
    int tag;
} SqQueue;

bool InitSqQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;

    Q.size = 0;

    Q.tag = 0;
}

// 判空
bool isEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true; // 代表队列为空
    }
    else
    {
        return false;
    }
}

// 判满
bool isFull(SqQueue Q)
{
    // 判满的条件是rear指针差front指针一个距离
    if (Q.front == (Q.rear + 1) % MaxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * 入队列操作rear队尾指针
 */
bool EnQueue(SqQueue &Q, int x)
{
    // 使用size判满 当 Q.size == max_size 代表队列满

    // 使用tag判满,当 Q.front == Q.rear && tag = 1 插入
    // if (Q.front == Q.rear && Q.tag == 1)
    // {
    //     return false;//判满   
    // }
    

    // 判满
    if (isFull(Q))
    {
        return false; // 队满返回false
    }

    Q.data[Q.rear] = x;
    // Q.rear++;//这样写,会导致已经出队列的空闲空间没有办法被利用到
    Q.rear = (Q.rear + 1) % MaxSize; // 这样就能利用到空闲的前面的空间 也就是所谓的循环队列

    Q.size++;

    // 入队列时,插入操作,tag赋值1
    Q.tag = 1;

    return true;
}

/**
 * 出队列操作front队首指针
 */
bool DeQueue(SqQueue &Q, int &x)
{
    // 使用size判空 当 Q.size == 0 代表队列空

    // 使用tag判空,当 Q.front == Q.rear && tag = 0 删除
    if (Q.front == Q.rear && Q.tag == 0)
    {
        return false;//判空
    }
    

    // 判空
    if (isEmpty(Q))
    {
        return false; // 队列为空返回false
    }

    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;

    Q.size--;

    // 出队列时,删除操作,tag赋值0
    Q.tag = 0;

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

/**
 * 获取队列头元素
 */
bool GetHead(SqQueue Q, int &x)
{
    // if (isEmpty(Q))
    // {
    //     return false;
    // }
    x = Q.data[Q.front];
    return true;
}

// 传统方式是队尾指针指向下一个能够插入的索引位置,即先赋值再自增,队首指针指向当前待读取位置
// 一种考题是让队尾指针指向当前队列最后一个元素,所以入队时需要先自增再赋值

// 初始化,让rear不再指向0,而是指向0的前面,即max_size-1位置
void InitSqQueue2(SqQueue &Q)
{
    Q.front = 0;
    Q.rear = MaxSize - 1;
}

// 判满时,如果选择牺牲一个存储单元,那么rear应该落后front两个位置
bool isFull2(SqQueue Q)
{
    if ((Q.rear + 2) % MaxSize == Q.front)
    {
        return true; // 队满
    }
}

// 入队列时先自增再赋值,而不是先赋值再自增
bool EnQueue2(SqQueue &Q, int x)
{
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.data[Q.rear] = x;
}

// 判空时 rear落后front一个位置
bool isEmpty2(SqQueue Q)
{

    if ((Q.rear + 1) % MaxSize == Q.front)
    {
        return true; // 队列空
    }
}

int main()
{
    // SqQueue Q;

    // InitSqQueue(Q);

    // EnQueue(Q, 100);
    // EnQueue(Q, 200);
    // EnQueue(Q, 300);

    // int x;
    // GetHead(Q, x);
    // printf("%d\n", x);

    // DeQueue(Q, x);

    // GetHead(Q, x);
    // printf("%d\n", x);

    SqQueue Q;
    InitSqQueue2(Q);

    if (isEmpty2(Q))
    {
        printf("empty\n");
    }
    else
    {
        printf("not empty\n");
    }

    EnQueue2(Q, 100);
    EnQueue2(Q, 200);
    EnQueue2(Q, 300);
    // EnQueue2(Q, 400);

    if (isFull2(Q))
    {
        printf("full\n");
    }
    else
    {
        printf("not full\n");
    }

    return 0;
}
