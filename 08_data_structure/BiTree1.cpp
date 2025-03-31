#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    BiTNode *lchild;
    BiTNode *rchild;

    // 方便寻找父结点,可以定义下面的指针,构建三叉链表,一般不使用这种方式,而是使用其他方式
    //  BiTNode *parent;
} BiTNode, *BiTree;

/**
 * 初始化二叉树
 */
void InitBiTree(BiTree &T)
{
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = 1;
    T->lchild = T->rchild = NULL;
}

/**
 * 插入一个左子节点
 */
void InsertBiTree(BiTree &T, int x)
{
    BiTNode *t = (BiTNode *)malloc(sizeof(BiTNode));
    t->data = x;
    t->lchild = t->rchild = NULL;

    T->lchild = t;
}

int main()
{
    return 0;
}
