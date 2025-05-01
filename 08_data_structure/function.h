#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType; // 定义树节点存储的数据类型

typedef struct BiTNode
{
    BiElemType c; // 这里存储字符类型
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree; // 定义树节点的结构体类型,一个节点包含数据,左子节点,右子节点

typedef struct tag
{
    BiTree p;
    struct tag *pnext;
} tag_t, *ptag_t; // 该结构体用来辅助我们构造树 是一个单链表

// 实现层序遍历,也就是广度优先,需要单链表的队列作为辅助
typedef BiTree ElemType;
typedef struct LNode
{
    BiTree data; // 树的节点作为data数据
    struct LNode *next;
} LNode;

typedef struct
{
    LNode *front, *rear;
} LinkQueue;

// 函数声明:一些常用的单链表的队列的方法
void InitQueue(LinkQueue &Q);

bool isEmpty(LinkQueue Q);

void EnQueue(LinkQueue &Q, BiTree e);

bool DeQueue(LinkQueue &Q, BiTree &e);