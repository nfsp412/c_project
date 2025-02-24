#include <stdio.h>
#include <stdlib.h>

// 队列的重复使用,则使用循环队列实现的
// 允许增加队列占用空间,则使用链式存储结构实现
// 所以使用循环队列+链式存储

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 入队列
 */
void EnQueue(LinkList front, LinkList &rear, ElemType val)
{
    LinkList pnew;
    if (rear->next == front)
    {
        // 队列满
        // 申请内存
        pnew = (LinkList)malloc(sizeof(LNode));

        // data赋值
        rear->data = val;

        // next赋值
        rear->next = pnew;

        // 循环队列,让新增加的pnew指向front,这样就循环起来
        pnew->next = front;

        // rear永远指向尾节点
        rear = pnew;
    }
    else
    {
        // 队列不满
        rear->data = val; // 直接用新值替换掉旧值

        // 仍然要移动到尾节点
        rear = rear->next;
    }
}

/**
 * 出队列
 */
void DeQueue(LinkList &front, LinkList rear)
{
    if (front == rear)
    {
        printf("empty \n"); // 队列为空的条件
    }
    else
    {
        // 队列不空
        int e = front->data;
        printf("e = %d\n", e);

        // front移动一位
        front = front->next;
    }
}

int main()
{
    LinkList front, rear;

    //初始化front和rear
    front = rear = (LinkList) malloc(sizeof(LNode));

    //初始化时让rear的next指向front,构成一个圆圈
    rear->next = front;

    //入队列
    EnQueue(front, rear, 3);
    EnQueue(front, rear, 4);

    //出队列
    DeQueue(front, rear);

    return 0;
}