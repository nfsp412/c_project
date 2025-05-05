#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 二叉排序树(二叉查找树)
// 和二叉树相比,每个节点的左右子节点是有排序的

typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode, *BiTree;

/**
 * 二叉排序树的插入元素方法
 * 可以使用递归实现,但是不容易理解,这里使用非递归的方式实现
 * 非递归就是每次插入一个数据,循环插入完毕即可
 */
int InsertTree(BiTree &T, int e)
{
    // 优化下,一进来就先申请内存创建新节点
    BiTree pnew = (BiTree)calloc(1, sizeof(BSTNode));
    pnew->data = e;
    pnew->lchild = pnew->rchild = NULL;

    if (T == NULL)
    {
        // // 根节点为null时,进行初始化工作
        // T = (BiTree)malloc(sizeof(BSTNode));
        // // 根节点赋值
        // T->data = e;
        // // 根节点的左右子节点赋值
        // T->lchild = T->rchild = NULL;
        // return 1;

        T = pnew;
        return 1;
    }

    BiTree parent; // parent存储p的父节点

    BiTree p = T; // 临时变量p用来遍历
    while (p)
    {
        parent = p; // 在p指向null之前,先把p赋给parent,后面p再指向child从而指向null的时候,还保留了parent,后面才能插入数据

        // p不为null
        if (e > p->data)
        {
            // e大于当前节点,代表e应该去右半边,所以让p指向右子节点
            p = p->rchild;
        }
        else if (e < p->data)
        {
            // e小于当前节点,代表e应该去左半边,所以让p指向左子节点
            p = p->lchild;
        }
        else
        {
            return -1; // 这里不考虑相等情况,直接返回-1
        }
    }

    // 创建新的节点
    // BiTree pnew = (BiTree)malloc(sizeof(BSTNode));

    // pnew->data = e;
    // pnew->lchild = pnew->rchild = NULL;

    // 上面已经不断循环p从而找到了新节点应该插入的位置,即parent的左子节点或者右子节点,下面就简单了,判断应该插入到parent的哪边即可
    if (e > parent->data)
    {
        // 代表新节点应该放到parent父节点的右半边
        parent->rchild = pnew;
    }
    else if (e < parent->data)
    {
        //
        parent->lchild = pnew;
    }
    else
    {
        return -1;
    }

    return 1;
}

// 插入元素,递归方法
int BST_Insert(BiTree &T, int e)
{
    if (T == NULL)
    {
        T = (BiTree)calloc(1, sizeof(BSTNode));
        T->data = e;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if (e == T->data)
    {
        return 0; // 不能插入已存在的元素
    }
    else if (e < T->data)
    {
        return BST_Insert(T->lchild, e);
    }
    else if (e > T->data)
    {
        return BST_Insert(T->rchild, e);
    }
}

/**
 * 二叉排序树的创建方法,核心还是插入元素的方法
 */
void CreateTree(BiTree &T, int e[], int n)
{
    T = NULL; // 根节点赋值null,后面进行初始化
    int i = 0;
    while (i < n)
    {
        // 循环遍历数组的元素并构建二叉树
        InsertTree(T, e[i]);
        i++;
    }
}

/**
 * 中序遍历
 */
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        printf("%3d", T->data);
        InOrder(T->rchild);
    }
}

/**
 * 二叉遍历树的元素查找
 * 根据元素查找,查找该节点以及该节点父节点
 * p代表parent,存储找到的节点的父节点
 */
BSTNode *SearchTree(BiTree T, int e, BiTree &p)
{
    p = NULL;
    // 循环匹配
    while (T != NULL && e != T->data)
    {
        p = T;
        if (e > T->data)
        {
            // 待查找元素大于当前节点元素,则应该去当前节点的右半边继续查询
            T = T->rchild;
        }
        else if (e < T->data)
        {
            T = T->lchild;
        }
    }

    return T; // 返回T,实际上是返回的被找到的那个节点,所以如果没找到那么返回的T就是NULL了
}

// 查找,递归实现
BSTNode *BSTSearch(BiTree T, int key)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (key == T->data)
    {
        return T;
    }
    else if (key < T->data)
    {
        return BSTSearch(T->lchild, key);
    }
    else if (key > T->data)
    {
        return BSTSearch(T->rchild, key);
    }
}

/**
 * 二叉排序树 删除某个节点
 */
void DeleteTree(BiTree &T, int e)
{
    if (T == NULL)
    {
        return;
    }

    // 递归找到待删除节点位置
    if (T->data > e)
    {
        DeleteTree(T->lchild, e);
    }
    else if (T->data < e)
    {
        DeleteTree(T->rchild, e);
    }
    else
    {
        // 代表匹配到了待删除节点

        // 待删除节点的左子节点为空,则右边顶上到待删除节点的位置
        if (T->lchild == NULL)
        {
            BSTNode *t = T;
            T = T->rchild;
            free(t);
        }
        else if (T->rchild == NULL)
        {
            // 待删除节点的右子节点为空,则左边顶上到待删除节点的位置
            BSTNode *t = T;
            T = T->lchild;
            free(t);
        }
        else
        {
            // 最麻烦的情况是待删除元素的左子节点和右子节点都不空,例如根节点往往就是这种情况
            //找左子树最大或者右子树最小

            // 存储左子节点
            BSTNode *t = T->lchild;

            // 如何找到左边所有节点中的最大节点?只需要从左子节点开始一直向右遍历,直到null为止
            while (t->rchild != NULL)
            {
                t = t->rchild;
            }

            // 删除策略: 左子节点所在的左子树中,找到最大值所在的节点,来顶上到待删除节点的位置
            // 至于顶上来的方法,实际上是先把被删除节点的数据data替换为找到的节点的data,然后调用删除方法删除掉找到的节点即可
            // 实际上是data值的替换而不是更改了引用
            T->data = t->data; //
            DeleteTree(T->lchild, t->data);
        }
    }
}

int main()
{

    BiTree T;
    int e[] = {33, 24, 18, 46, 20, 21, 25};
    // 创建二叉排序树,根据已有的数组进行创建,而不是使用scanf进行创建,这里注意
    CreateTree(T, e, 7);

    // 校验,中序遍历后按照小到大顺序输出了,中序的顺序是左中右,正好二叉排序树就是左小右大的,怪不得用中序遍历
    InOrder(T);
    printf("\n");

    // 查找
    BSTNode *s;
    BiTree newT = SearchTree(T, 46, s);
    if (newT)
    {
        // printf("%d\n", s->data);    // 18
        printf("%d\n", newT->data); // 15
    }
    else
    {
        printf("not found \n");
    }

    // 校验
    InOrder(T);
    printf("\n");

    // 删除元素
    DeleteTree(T, 46);

    // 校验
    InOrder(T);
    printf("\n");

    // 查找,递归
    newT = BSTSearch(T, 21);
    if (newT)
    {
        // printf("%d\n", s->data);    // 18
        printf("%d\n", newT->data); // 15
    }
    else
    {
        printf("not found \n");
    }

    // 插入,递归
    BST_Insert(T, 30);

    // 校验
    InOrder(T);
    printf("\n");

    return 0;
}
