#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

typedef struct tag_t
{
    BiTree data;
    struct tag_t *next;
} tag_t, *ptag_t;

void PreOrder(BiTree Q)
{
    if (Q != NULL)
    {
        putchar(Q->data);
        PreOrder(Q->lchild);
        PreOrder(Q->rchild);
    }
    
}

int main()
{
    //定义节点存储新建二叉树节点
    BiTree pnew;
    //定义完整二叉树
    BiTree tree = NULL;
    //定义变量存储二叉树节点data
    char c;
    //定义辅助单链表
    ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;
    //循环读取数据
    while (scanf("%c", &c))
    {
        //break判断
        if (c == '\n')
        {
            break;
        }
        //初始化pnew
        pnew = (BiTree) calloc(1, sizeof(BiTNode));
        //data赋值
        pnew->data = c;
        //初始化listpnew
        listpnew = (ptag_t) calloc(1, sizeof(tag_t));
        //data赋值
        listpnew->data = pnew;
        //尾插法插入单链表
        if (tree == NULL)
        {
            tree = pnew;
            phead = ptail = pcur = listpnew;
            continue;//注意continue,否则一直在输入的首个字符处进行无限循环
        }else{
            ptail->next = listpnew;
            ptail = listpnew;
        }
        //操作pcur构建二叉树
        if (pcur->data->lchild == NULL)
        {
            pcur->data->lchild = pnew;
        }else if (pcur->data->rchild == NULL)
        {
            pcur->data->rchild = pnew;
            pcur = pcur->next;//移动一个节点
        }
        
        
    }

    PreOrder(tree);
    printf("\n");
    

    return 0;
}