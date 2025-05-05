#include <stdio.h>
#include <stdlib.h>

// 红黑树RBT
typedef struct RBTNode
{
    int data;
    RBTNode *parent;
    RBTNode *lchild;
    RBTNode *rchild;
    int color;//表示红色和黑色
}RBTNode, * RBTree;

// 插入
void RBT_Insert(RBTree &T, int e)
{

}

int main()
{
    return 0;
}