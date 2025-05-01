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

typedef struct tag
{
    BiTree p;
    struct tag *pnext;
} tag_t, *ptag_t; // 该结构体用来辅助我们构造树 是一个单链表

// 实现层序遍历,也就是广度优先,需要单链表的队列作为辅助
typedef struct LNode
{
    BiTNode *data; // 树的节点作为data数据
    struct LNode *next;
} LNode;

typedef struct
{
    LNode *front, *rear;
} LinkQueue;

// 函数声明:一些常用的单链表的队列的方法
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));

    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EnQueue(LinkQueue &Q, BiTree e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));

    p->data = e;

    p->next = NULL;

    Q.rear->next = p;

    Q.rear = p;
}

bool DeQueue(LinkQueue &Q, BiTree &e)
{
    if (Q.front == Q.rear)
    {
        return false;
    }

    LNode *p = Q.front->next; // 跳过头结点

    e = p->data;

    Q.front->next = p->next;

    // 多一步重要的判断
    if (Q.rear == p)
    {
        Q.rear = Q.front; // 让rear指向front而不是front指向rear,
    }

    free(p);

    return true;
}

/**
 * 初始化二叉树
 */
void InitBiTree(BiTree &tree)
{
    // T = (BiTNode *)malloc(sizeof(BiTNode));
    // T->data = 1;
    // T->lchild = T->rchild = NULL;

    BiTree pnew; // 创建临时的树的结构体指针,存储每一次新增的树的节点
    int c;
    tree = NULL; // 存储整棵树
    ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;

    while (scanf("%d", &c))
    {
        if (c == 9999)
        {
            break;
        }

        // 初始化pnew,即树的节点
        pnew = (BiTree)calloc(1, sizeof(BiTNode));

        // data赋值
        pnew->data = c;

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

void visit(BiTree T)
{
    printf("%4d", T->data);
}

/**
 * 前序遍历
 * 中左右
 * 第一次路过时访问数据
 * 空间复杂度 O(h+1)=O(h) h二叉树高度
 */
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);

    EnQueue(Q, T);

    BiTree tmp;

    while (!isEmpty(Q))
    {
        DeQueue(Q, tmp);
        visit(tmp);

        if (tmp->lchild != NULL)
        {
            EnQueue(Q, tmp->lchild);
        }

        if (tmp->rchild != NULL)
        {
            EnQueue(Q, tmp->rchild);
        }
    }
}

int main()
{
    BiTree tree;
    InitBiTree(tree);

    /**
     *
     *    1
     *  2   3
     * 4 5 6
     *
     */

    PreOrder(tree);
    printf("\n");

    InOrder(tree);
    printf("\n");

    PostOrder(tree);
    printf("\n");

    LevelOrder(tree);
    printf("\n");

    return 0;
}
