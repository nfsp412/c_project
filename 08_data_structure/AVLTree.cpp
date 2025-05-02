#include <stdio.h>
#include <stdlib.h>

// 平衡二叉树
typedef struct AVLNode
{
    int data;
    int balance; // 平衡因子
    AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;

// 右旋
void LL(AVLTree &T)
{
    AVLNode *grandfather;
    AVLNode *father;
    AVLNode *child;
    // 核心代码
    father->lchild = child->rchild;
    child->rchild = father;
    grandfather->lchild = child;//或者是rchild
}

// 左旋
void RR(AVLTree &T)
{
    AVLNode *grandfather;
    AVLNode *father;
    AVLNode *child;
    // 核心代码
    father->rchild = child->lchild;
    child->lchild = father;
    grandfather->lchild = child;//或者是rchild
}

void LR(AVLTree &T)
{
    // 先左旋再右旋
    RR(T);
    LL(T);
}

void RL(AVLTree &T)
{
    // 先右旋再左旋
    LL(T);
    RR(T);
}

// 删除
void AVL_Delete(AVLTree &T, int key)
{
}

int main()
{
    return 0;
}