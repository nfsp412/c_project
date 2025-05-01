#include "function.h"
#include "queue"

/**
 * 前序遍历,也就是深度优先遍历
 * 遍历的顺序是中左右(每个节点),先打印中,再递归左节点,再递归右节点
 * 递归左节点的过程,也是先打印中,再递归左节点,再递归右节点
 * 递归实现
 */
void PreOrder(BiTree p)
{
    if (p != NULL)
    {
        putchar(p->c);       // 打印自身的数据c
        PreOrder(p->lchild); // 打印左
        PreOrder(p->rchild); // 打印右
    }
}

/**
 * 中序遍历,
 * 遍历的顺序是左中右(每个节点)
 */
void InOrder(BiTree p)
{
    if (p != NULL)
    {
        InOrder(p->lchild); // 左
        putchar(p->c);      // 中
        InOrder(p->rchild); // 右
    }
}

/**
 * 后续遍历
 * 遍历的顺序是左右中(每个节点)
 */
void PostOrder(BiTree p)
{
    if (p != NULL)
    {
        PostOrder(p->lchild); // 左
        PostOrder(p->rchild); // 右
        putchar(p->c);        // 中
    }
}

/**
 * 层序遍历,也就是广度优先遍历
 * 一层一层的顺序从左到右遍历
 */
void LevelOrder(BiTree T)
{
    LinkQueue Q; // 辅助单链表队列
    InitQueue(Q);

    BiTree p;
    EnQueue(Q, T); // 树根进入队列

    while (!isEmpty(Q))
    {
        // 只要Q队列不为空,就循环
        DeQueue(Q, p); // 出队列
        putchar(p->c); // 打印c

        if (p->lchild != NULL)
        {
            // 左节点不为空
            EnQueue(Q, p->lchild); // 左节点进入队列
        }

        if (p->rchild != NULL)
        {
            // 右节点不为空
            EnQueue(Q, p->rchild); // 右节点进入队列
        }
    }
}

int main()
{
    BiTree pnew; // 创建临时的树的结构体指针,存储每一次新增的树的节点
    char c;
    BiTree tree = NULL; // 存储整棵树
    ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;

    while (scanf("%c", &c))
    {
        if (c == '\n')
        {
            break;
        }

        // 初始化pnew,即树的节点
        pnew = (BiTree)calloc(1, sizeof(BiTNode));

        // data赋值
        pnew->c = c;

        // 初始化单链表的新节点,该单链表省略了头结点,用来存储每次新创建的树节点pnew
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));

        // p赋值
        listpnew->p = pnew;

        if (tree == NULL)
        {
            // 第一次赋值
            tree = pnew;
            phead = listpnew; //
            ptail = listpnew; // 该指针一直指向的是辅助单链表的尾节点
            pcur = listpnew;  // 该指针一直指向的是辅助单链表对应的当前的节点
            continue;
        }
        else
        {
            // 尾插法放入新节点
            ptail->pnext = listpnew;
            ptail = listpnew; // 让尾节点指针一直指向的是单链表的节点尾部
        }

        // pcur指向待插入节点位置
        if (NULL == pcur->p->lchild)
        {
            pcur->p->lchild = pnew; // 新的树的节点放到待插入节点的位置的左边
        }
        else if (NULL == pcur->p->rchild)
        {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext; // 左右树已满,移动pcur
        }
    }

    //添加辅助队列验证无问题
    // LinkQueue Q; // 辅助单链表队列
    // InitQueue(Q);

    // EnQueue(Q, tree);
    // EnQueue(Q, tree->lchild);
    // EnQueue(Q, tree->rchild);

    // BiTree e1;
    // DeQueue(Q, e1);
    // printf("%c\n", e1->c);
    // DeQueue(Q, e1);
    // printf("%c\n", e1->c);

    // printf("pre order \n");
    // PreOrder(tree); // a-b-d-e-c
    // printf("\n");

    // printf("in order \n");
    // InOrder(tree); // d-b-e-a-c
    // printf("\n");

    // printf("post order \n");
    // PostOrder(tree); // d-e-b-c-a
    // printf("\n");

    printf("level order \n");
    LevelOrder(tree); // a-b-c-d-e
    printf("\n");
}
