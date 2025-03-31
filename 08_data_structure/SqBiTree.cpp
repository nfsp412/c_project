#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct TreeNode
{
    int value;
    bool isEmpty;
} TreeNode;

void InitTreeNode(TreeNode t[])
{
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
    
}

int main()
{
    //声明
    TreeNode t[MaxSize];

    //初始化
    InitTreeNode(t);

    //建议从数组t[1]开始,保持和二叉树编号一致
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].value = i;
    }
    
    //二叉树的顺序存储 只适合应用在完全二叉树上
    

    return 0;
}
