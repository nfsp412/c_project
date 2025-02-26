#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct tag_t
{
    BiTree data;
    struct tag_t *next;
} tag_t, *ptag_t;

typedef struct LNode
{
    BiTree data;
    struct LNode *next;
} LNode;

typedef struct LinkQueue
{
    struct LNode *front, *rear;
} LinkQueue;

/**
 * 初始化队列
 */
void InitQueue(LinkQueue &Q)
{
    // 申请内存,初始化front和rear节点
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
    Q.front->next = NULL;
}

/**
 * 队列判空
 */
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

/**
 * 入队列
 */
void EnQueue(LinkQueue &Q, BiTree e)
{
    // 分配内存创建节点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // data赋值
    s->data = e;
    // next赋值
    s->next = NULL;
    // 尾插法入队列
    Q.rear->next = s;
    Q.rear = s;
}

/**
 * 出队列
 */
bool DeQueue(LinkQueue &Q, BiTree &e)
{
    if (isEmpty(Q))
    {
        return false; // 队列为空返回false
    }
    // 获取要出队列的节点
    LNode *s = Q.front->next; // 跳过头结点获取一个
    // data赋值
    e = s->data;

    // 移动front
    Q.front->next = s->next;

    // 重要判断
    // 如果出队列的元素正好是队尾的元素,即出队列后队列为空了,那么应该重置指针,让队尾指针rear重新指向队头front
    if (s == Q.rear)
    {
        Q.rear = Q.front;
    }

    // 内存释放
    free(s);

    return true;
}

/**
 * 层次建树
 */
void CreateBiTree(BiTree &tree)
{
    tree = NULL;
    BiTree pnew;
    ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;
    char c;
    while (scanf("%c", &c))
    {
        if (c == '\n')
        {
            break;
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->data = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->data = pnew;
        if (tree == NULL)
        {
            tree = pnew;
            phead = ptail = pcur = listpnew;
            continue;
        }
        else
        {
            // 尾插法
            ptail->next = listpnew;
            ptail = listpnew;
        }
        if (pcur->data->lchild == NULL)
        {
            pcur->data->lchild = pnew;
        }
        else if (pcur->data->rchild == NULL)
        {
            pcur->data->rchild = pnew;
            pcur = pcur->next;
        }
    }
}

/**
 * 中序遍历 左中右
 */
void InOrder(BiTree Q)
{
    if (Q != NULL)
    {
        InOrder(Q->lchild);
        putchar(Q->data);
        InOrder(Q->rchild);
    }
}

/**
 * 后序遍历 左右中
 */
void PostOrder(BiTree Q)
{
    if (Q != NULL)
    {
        PostOrder(Q->lchild);
        PostOrder(Q->rchild);
        putchar(Q->data);
    }
}

void LevelOrder(BiTree T)
{
    // 创建辅助队列
    LinkQueue Q;

    // 初始化
    InitQueue(Q);

    // 创建二叉树节点存储出队的节点数据,并进行打印
    BiTree p;

    // 首次,根节点入队
    EnQueue(Q, T);

    // 循环判空
    while (!isEmpty(Q))
    {
        // 只要队列不为空,就出队并打印节点数据
        // 每一次的出队,都是按照每一层从左到右的顺序出队并且打印
        DeQueue(Q, p);
        putchar(p->data);

        // 左右子节点判空并继续入队,顺序要左右,不能颠倒,因为层序遍历每一层都是从左到右的
        // 注意是两个if,而不是if else,即左右都需要判断并且入队
        if (p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }
}

int main()
{
    // 层次建树
    BiTree tree;
    CreateBiTree(tree);

    InOrder(tree);
    printf("\n");

    PostOrder(tree);
    printf("\n");

    // 广度优先遍历
    LevelOrder(tree);
    printf("\n");

    return 0;
}