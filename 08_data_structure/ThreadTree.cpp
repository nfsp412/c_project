#include <stdio.h>
#include <stdlib.h>

/**
 * 线索二叉树版本
 */
typedef struct ThreadNode
{
    int data;
    ThreadNode *lchild;
    ThreadNode *rchild;

    // 方便寻找父结点,可以定义下面的指针,构建三叉链表,一般不使用这种方式,而是使用其他方式
    //  ThreadNode *parent;

    int ltag, rtag; // 当ltag或者rtag为0时,表是指向的孩子,当为1时表是指向的线索

} ThreadNode, *ThreadTree;

typedef struct tag
{
    ThreadTree p;
    struct tag *pnext;
} tag_t, *ptag_t; // 该结构体用来辅助我们构造树 是一个单链表

/**
 * 初始化二叉树
 */
void InitThreadTree(ThreadTree &tree)
{
    // T = (ThreadNode *)malloc(sizeof(ThreadNode));
    // T->data = 1;
    // T->lchild = T->rchild = NULL;

    ThreadTree pnew; // 创建临时的树的结构体指针,存储每一次新增的树的节点
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
        pnew = (ThreadTree)calloc(1, sizeof(ThreadNode));

        // data赋值
        pnew->data = c;
        pnew->ltag = 0;
        pnew->rtag = 0;

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

// 全局声明pre
ThreadNode *pre = NULL;

/**
 * 打印结点元素以及构建线索方法
 */
void visit(ThreadTree T)
{
    printf("%4d", T->data);

    // 线索化
    ThreadNode *q = T;
    if (q->lchild == NULL) // 当前节点的左子树为空,那么就让左子树指向前驱节点,构建线索 对于首个结点来说,指向的是pre=null
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) // 当前结点的前驱pre结点的右子树为空,那么就让它指向后继结点,构建线索,
    // 对于pre结点来说,其后继结点也就是当前p结点
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q; // pre指针需要向后移动
}

/**
 * 前序遍历
 */
void PreThread(ThreadTree T)
{
    if (T != NULL)
    {
        visit(T);
        if (T->ltag == 0) // 意思是lchild不是前驱线索而是前驱结点才执行该方法 避免死循环问题
        {
            PreThread(T->lchild);
        }

        if (T->rtag == 0)
        {
            PreThread(T->rchild);
        }
    }
}

/**
 * 前序序列线索化
 */
void CreatePreThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PreThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1;
        }
    }
}

/**
 * 中序遍历
 */
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

/**
 * 中序序列线索化
 */
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
        {
            // 处理最后一个结点
            pre->rtag = 1;
        }
    }
}

/**
 * 后序遍历
 */
void PostThread(ThreadTree T)
{
    if (T != NULL)
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

/**
 * 后序序列线索化
 */
void CreatePostThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PostThread(T);
        if (pre->rchild == NULL)
        {
            // 处理最后一个结点
            pre->rtag = 1;
        }
    }
}

// 线索二叉树寻找结点

/**
 * 中序下 寻找首个被遍历的结点
 */
ThreadNode *InOrderFirstNode(ThreadNode *p)
{
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}

/**
 * 中序下 寻找下一个结点
 */
ThreadNode *InOrderNextNode(ThreadNode *p)
{
    // 中序下 如果右子树是线索结点那么直接返回右子树即可
    // 但如果右子树是孩子结点,那么需要从右子树中一直找到最左下角第一个节点
    if (p->rtag == 0)
    {
        return InOrderFirstNode(p->rchild);
    }
    else
    {
        return p->rchild;
    }
}

/**
 * 中序下 寻找最后一个被遍历的节点
 */
ThreadNode *InOrderLastNode(ThreadNode *p)
{
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    return p;
}

/**
 * 中序下 寻找上一个节点
 */
ThreadNode *InOrderPreNode(ThreadNode *p)
{
    // 中序下 如果左子树是线索结点那么直接返回左子树即可
    // 但如果左子树是孩子结点,那么需要从左子树中一直找到最右下角第一个节点
    if (p->ltag == 0)
    {
        return InOrderLastNode(p->lchild);
    }
    else
    {
        return p->lchild;
    }
}

/**
 * 中序线索二叉树的中序遍历
 */
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = InOrderFirstNode(T); p != NULL; p = InOrderNextNode(p))
    {
        printf("%4d", p->data);
    }
    printf("\n");
}

/**
 * 逆序遍历
 */
void RevInOrder(ThreadNode *T)
{
    for (ThreadNode *p = InOrderLastNode(T); p != NULL; p = InOrderPreNode(p))
    {
        printf("%4d", p->data);
    }
    printf("\n");
}

/**
 * 前序线索二叉树 找后继结点
 */
ThreadNode *PreOrderNextNode(ThreadNode *p)
{
    if (p->rtag == 1)
    {
        return p->rchild;
    }
    else
    {
        // 前序线索二叉树 有右孩子 但是左孩子不一定有
        // 如果没有左孩子 那直接遍历右子树第一个遍历的节点
        if (p->lchild != NULL)
        {
            // 如果有左孩子 那按照遍历顺序 后继结点就是左子树中第一个遍历的节点
            return p->lchild;
        }
        else
        {
            return p->rchild;
        }
    }
}

/**
 * 前序线索二叉树遍历
 */
void PreOrder(ThreadNode *T)
{
    for (ThreadNode *p = T; p != NULL; p = PreOrderNextNode(p))
    {
        printf("%4d", p->data);
    }
    printf("\n");
}

/**
 * 后序线索二叉树 找前驱结点
 */
ThreadNode *PostOrderPreNode(ThreadNode *p)
{
    if (p->ltag == 1)
    {
        return p->lchild;
    }
    else
    {
        // 当前节点存在左孩子 如果右孩子也存在 那按照遍历顺序结点的前驱一定是右孩子中最后遍历的结点
        if (p->rchild != NULL && p->rtag == 0)
        {
            return p->rchild;
        }
        else
        {
            // 只存在左孩子不存在右孩子时 前驱结点是左孩子中最后遍历的结点
            return p->lchild;
        }
    }
}

/**
 * 后序线索二叉树 逆向遍历
 */
void RevPostOrder(ThreadNode *T)
{
    for (ThreadNode *p = T; p != NULL; p = PostOrderPreNode(p))
    {
        printf("%4d", p->data);
    }
    printf("\n");
}

int main()
{
    ThreadTree tree;
    InitThreadTree(tree);

    /**
     *
     *    1
     *  2   3
     * 4 5 6
     *
     */

    // CreatePreThread(tree); // 1   2   4   5   3   6
    // printf("\n");

    // PreOrder(tree);

    // CreateInThread(tree); // 4   2   5   1   6   3
    // printf("\n");

    // InOrder(tree);
    // RevInOrder(tree);

    CreatePostThread(tree); // 4   5   2   6   3   1
    printf("\n");

    RevPostOrder(tree);

    return 0;
}
