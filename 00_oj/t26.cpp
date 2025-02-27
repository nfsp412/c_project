#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode, *BiTree;

/**
 * 构建二叉排序树
 */
int InsertBST(BiTree &T, int e)
{
    // 分配内存 构建二叉排序树的新节点
    BSTNode *pnew = (BSTNode *)calloc(1, sizeof(BSTNode));
    pnew->data = e;
    pnew->left = pnew->right = NULL;

    if (T == NULL)
    {
        // 首个新节点赋值给根节点T
        T = pnew;
        return 1;
    }

    // 定义指针p用来遍历树T
    BiTree p = T;

    // 定义指针parent用来指向p节点的父节点
    BiTree parent;

    // 循环遍历p,寻找新节点要添加到的位置,一直循环到p为null
    while (p != NULL)
    {
        // 当循环到p为null时,p的父节点parent就是待添加的节点的位置,后面只需要比较这个parent父节点和待添加节点的数据大小就可以完成添加了
        parent = p;

        if (p->data > e)
        {
            p = p->left;
        }
        else if (p->data < e)
        {
            p = p->right;
        }
        else
        {
            return -1; // 不考虑重复数据因此返回-1代表添加失败
        }
    }

    // 判断parent和待添加节点的数据大小然后进行添加
    if (parent->data > e)
    {
        parent->left = pnew;
    }
    else if (parent->data < e)
    {
        parent->right = pnew;
    }
    else
    {
        return -1; // 不考虑重复数据因此返回-1代表添加失败
    }

    return 1;
}

/**
 * pos使用引用
 */
void InOrder(BiTree T, int arr[], int &pos)
{
    if (T != NULL)
    {
        InOrder(T->left, arr, pos);
        printf("%3d", T->data);
        arr[pos++] = T->data;
        InOrder(T->right, arr, pos);
    }
}

int BiSearch(int arr[], int e, int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        
        if (arr[mid] == e)
        {
            return mid;
        }else if (arr[mid] > e)
        {
            high = mid - 1;
        }else if(arr[mid] < e)
        {
            low = mid + 1;
        }
        
        
    }

    return -1;
    
}

int main()
{
    int a[10];
    int x;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x);
        a[i] = x;
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%3d", a[i]);
    // }
    // printf("\n");

    BiTree T = NULL;
    for (int i = 0; i < 10; i++)
    {
        InsertBST(T, a[i]);
    }

    int arr[10];
    int pos = 0;
    InOrder(T, arr, pos);
    printf("\n");

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%3d", arr[i]);
    // }

    //二分查找
    int index = BiSearch(arr, 21, 10);
    printf("%d\n", index);

    return 0;
}
