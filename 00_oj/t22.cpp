#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int weight;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

/**
 * 使用单链表来辅助构建二叉树
 */
typedef struct tag
{
    BiTree data;
    struct tag *next;
} tag_t, *ptag_t;

void PreOrder(BiTree Q)
{
    if (Q != NULL)
    {
        putchar(Q->weight);
        PreOrder(Q->left);
        PreOrder(Q->right);
    }
}

/**
 * deep参数代表当前树节点的深度,root根节点深度为0
 * 返回当前叶子节点计算后的wpl值
 * 对于某个叶子节点的wpl值,等于深度deep乘以weight权重
 * Q代表传入的二叉树,从root根节点开始递归计算wpl
 */
int WplPreOrder(BiTree Q, int deep)
{
    static int wpl = 0;

    if (Q->left == NULL && Q->right == NULL)
    {
        // 代表是叶子节点,计算wpl值
        wpl += deep * Q->weight;
    }
    if (Q->left != NULL)
    {
        // 左节点不为null,递归左节点继续计算wpl,deep自增
        WplPreOrder(Q->left, deep + 1);
    }
    if (Q->right != NULL)
    {
        WplPreOrder(Q->right, deep + 1);
    }

    return wpl;
}

int Wpl(BiTree Q)
{
    return WplPreOrder(Q, 0);
}

int main()
{
    // 以下代码无需掌握,构建二叉树
    BiTree pnew;
    char c;
    BiTree tree = NULL;
    ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;

    while (scanf("%c", &c))
    {
        if (c == '\n')
        {
            break;
        }
        // 初始化pnew
        pnew = (BiTree)calloc(1, sizeof(BiTNode));

        // data赋值
        pnew->weight = c; // weight是int类型,但是这里就使用字符类型对应ASCII值进行赋值即可,演示而已

        // 初始化listpnew
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));

        // data赋值
        listpnew->data = pnew;

        // 尾插法将listpnew插入单链表中
        if (tree == NULL)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        }
        else
        {
            ptail->next = listpnew;
            ptail = listpnew;
        }

        // 操作pcur将pnew插入二叉树中
        if (pcur->data->left == NULL)
        {
            pcur->data->left = pnew;
        }
        else if (pcur->data->right == NULL)
        {
            pcur->data->right = pnew;
            pcur = pcur->next;
        }
    }

    // 深度优先遍历
    PreOrder(tree);
    printf("\n");

    int res = Wpl(tree);
    printf("res = %d\n", res);

    return 0;
}
