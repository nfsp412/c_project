#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 堆排序

// 时间复杂度 最好平均最坏O(nlogn) 
// 空间复杂度 O(1)
// 不稳定,算法复杂


// 1.大根堆 父节点值恒大于子节点值
// 2.层次建树法创建二叉树 演示方便使用数组代替 元素输入顺序即构建二叉树顺序即数组顺序
// 3.二叉树每个元素对应到数组索引这种数据结构就是 堆
// 4.二叉树和数组有关系: 最后父元素的对应的数组索引是(n/2)-1,例如n=10时,索引是4,n=9时,索引是3
// 5.二叉树和数组有关系: 父节点索引是d,则对应的左子节点索引是2*d+1
// 6.堆排序的步骤就是: 先调整为大根堆,

typedef struct BiTNode
{
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

// 辅助链表 用于层次建树
typedef struct tag
{
    BiTree p;
    struct tag *next;
} tag, *ptag;

// 辅助链表 用于广度优先遍历
typedef struct LNode
{
    BiTree data;
    struct LNode *next;
} LNode;

// 辅助队列 用于广度优先遍历
typedef struct
{
    LNode *front, *rear;
} LinkQueue;

// 队列方法
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
    // 初始化
    LNode *t = (LNode *)malloc(sizeof(LNode));

    // data和next赋值
    t->data = e;
    t->next = NULL;

    // 尾插法入队列
    Q.rear->next = t;
    Q.rear = t;
}

bool DeQueue(LinkQueue &Q, BiTree &e)
{
    // 判断队列是否为空
    if (isEmpty(Q))
    {
        return false;
    }

    // 跳过头结点
    LNode *t = Q.front->next;

    // data赋值
    e = t->data;

    // 移动front
    Q.front->next = t->next;

    if (Q.rear == t)
    {
        Q.rear = Q.front;
    }

    free(t);

    return true;
}

void LevelOrder(BiTree T, int *a, int pos)
{
    LinkQueue Q;
    InitQueue(Q);

    // 存储出队列节点
    BiTree p;

    EnQueue(Q, T);

    while (!isEmpty(Q))
    {
        DeQueue(Q, p);
        // printf("%3d", p->data);
        a[pos++] = p->data;

        // 注意左子节点和右子节点都需要判断进入,所以是两个if,而不是else if
        if (p->left != NULL)
        {
            EnQueue(Q, p->left);
        }

        if (p->right != NULL)
        {
            EnQueue(Q, p->right);
        }
    }
}

void InOrder(BiTree T, int *a, int &pos)
{
    if (T != NULL)
    {
        InOrder(T->left, a, pos);
        printf("%3d", T->data);
        // 数组赋值,先赋值后++
        a[pos++] = T->data;
        InOrder(T->right, a, pos);
    }
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

/**
 * 堆排序的核心 调整大根堆
 * 将某个子树调整为大根堆的方法
 * @param a 整个数组
 * @param i 要调整为大根堆的子树的根节点的索引 这样能算出左子节点的索引为2*dad+1
 * @param len 数组长度
 */
void AdjustDown(int *a, int i, int len)
{
    //这里注意索引从0开始时对应的父节点和子节点的索引
    // 第一次的dad和son的赋值
    int dad = i;//i节点
    int son = 2 * dad + 1;//i节点的左孩子结点
    // 循环是因为某个子树可能还包含其他的子树,我们调整以后要保证所有的子树都保持大根堆
    // 那如何进入二次循环继续进行比较呢?我们可以让son和dad交换后,让son索引变成下游子树的dad索引即可
    // 循环退出的条件是什么呢?当一直调整到最下游的子树的时候,当调整完成时,计算出来的son的索引值已经大于len了,就证明调整完成该退出了
    while (son < len)
    {
        // 比较左子节点和右子节点的大小
        if (son + 1 < len && a[son] < a[son + 1])//这里有一次关键字对比
        {
            // 如果右子节点大,那就让son索引指向右子节点
            // 如果左子节点大,那么不会执行这个
            son++;
        }

        // 调整dad和son
        if (a[son] > a[dad])//这里有一次关键字对比
        {
            // 如果子节点大于父节点(根节点) 进行交换
            swap(a[son], a[dad]);
            // 那如何进入二次循环继续进行比较呢?我们可以让son和dad交换后,让son索引变成下游子树的dad索引,然后重新赋值新的son索引
            dad = son;
            son = 2 * dad + 1;
        }
        else
        {
            // 如果没有发生交换,证明这个子树不变动,那么自然也不需要循环去判断后续的子树
            //也就是父节点比子节点都大,自然就不需要继续下坠了
            break;
        }
    }
}

void HeapSort(int *a, int len)
{
    // 创建大根堆 一共有多少子树需要调整为大根堆?从索引0到索引len/2-1个,也就是非叶子节点嘛
    int i;
    // 从后向前调整子树成为大根堆,即从最底层的分支结点开始向上调整
    for (i = len / 2 - 1; i >= 0; i--)
    {
        AdjustDown(a, i, len);
    }

    // 当调整完大根堆后,把根节点数据和尾部节点数据进行交换,目的是为了让最大值放到最后去
    //因为执行过完整的大根堆调整后,堆顶元素(也就是根节点元素),就是最大值
    //放在后面是因为我们需要升序排序
    swap(a[0], a[len - 1]);

    // 不使用递归,而是直接循环继续调整大根堆,继续将根节点数据放到最后
    // i代表无序元素的个数,所以边界是>1,剩下两个元素的时候也找一次大根堆然后交换一次首尾元素
    //即只有1个元素时,不需要调整,也就是不需要进入循环
    for (i = len - 1; i > 1; i--)
    {
        // 当交换了a[0]和a[尾部]的数据的时候,实际上整个数组,只有a[0]这个子树不满足大根堆了(因为上面调整大根堆的方法已经调整完大根堆了)
        // 所以这里调整大根堆,调整的是0索引这个子树的大根堆
        //实际上由于交换了0索引元素以及尾部索引元素,导致这个for循环每次调整大根堆的参数2都是0固定的
        // 而i=len-1正好代表数组的无序的元素的个数,正好作为参数3传入
        AdjustDown(a, 0, i);
        // 交换首元素和尾元素时注意,由于数组长度是i=len-1,所以尾元素的索引应该是i-1
        swap(a[0], a[i - 1]);
    }
}

void PrintArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

int main()
{
    // // 使用层次建树来创建一个二叉树
    // // 固定元素 3 87 2 93 78 56 61 38 12 40 9999

    // // 存储整个树
    // BiTree tree = NULL;

    // // 存储新增节点
    // BiTree pnew;

    // // 辅助构造
    // ptag phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;

    // // 循环读取数据
    // int x;
    // while (scanf("%d", &x))
    // {
    //     if (x == 9999)
    //     {
    //         break;
    //     }

    //     // 初始化pnew节点
    //     pnew = (BiTree)calloc(1, sizeof(BiTNode));

    //     // data
    //     pnew->data = x;

    //     // 初始化辅助构造
    //     listpnew = (ptag)calloc(1, sizeof(tag));

    //     // p
    //     listpnew->p = pnew;

    //     if (tree == NULL)
    //     {
    //         // 首次添加数据
    //         tree = pnew;
    //         phead = listpnew;
    //         ptail = listpnew;
    //         pcur = listpnew;
    //         continue;
    //     }
    //     else
    //     {
    //         // 尾插法将节点插入单链表
    //         ptail->next = listpnew;
    //         ptail = listpnew;
    //     }

    //     // 构建二叉树
    //     if (pcur->p->left == NULL)
    //     {
    //         // 左子树为空就插入到左子树
    //         pcur->p->left = pnew;
    //     }
    //     else if (pcur->p->right == NULL)
    //     {
    //         // 右子树为空就插入右子树
    //         pcur->p->right = pnew;
    //         // 移动pcur
    //         pcur = pcur->next;
    //     }
    // }

    // int a[10];
    // int pos = 0;
    // LevelOrder(tree, a, pos);
    // printf("\n");

    // 方便调试,使用固定数组
    int a[10] = {3, 87, 2, 93, 78, 56, 61, 38, 12, 40};
    HeapSort(a, 10);

    // 第一次调整大根堆后 93  87  61  38  78  56   2   3  12  40
    // 第一次swap后 40  87  61  38  78  56   2   3  12 93
    PrintArray(a, 10);//2   3  12  38  40  56  61  78  87  93
}
