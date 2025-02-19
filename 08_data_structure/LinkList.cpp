#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 头插法创建LinkList链表
 * 每次插入数据都是插入到头部,即打印顺序和输入顺序是相反的
 * @param L 也可以写LNode* &L,和LinkList &L等价
 */
LinkList ListHeadInsert(LinkList &L)
{
    LNode *s;
    ElemType x;

    // 初始化头结点
    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点,地址赋值给LinkList这个指针 不能写LinkList大小,因为只有8字节,这里是易错点

    // 尾部永远指向null
    L->next = NULL;

    // 读取第一个数据
    scanf("%d", &x);

    while (x != 9999)
    {
        // 初始化数据节点,从第一个数据开始
        // 第二个数据到来,再次申请内存
        s = (LNode *)malloc(sizeof(LNode));
        // 第一个数据,插入数据
        // 第二个数据,插入数据
        s->data = x;
        // 第一个数据,插入指针,头插法代表第一个数据实际上在链表的最后一个位置处,所以next指向null
        // 第二个数据,插入指针,第一次数据插入后,此时的L.next不再指向null,而是指向的第一个数据,所以头插法,将第二个数据的next指向第一个数据
        s->next = L->next;
        // 第一个数据,插入指针,L的next指向了这个数据s
        // 第二个数据,插入指针,L的next原本指向第一个数据,此时更改为指向第二个数据
        L->next = s;

        // 再次读取数据,进入第二次循环
        scanf("%d", &x);
    }

    return L;
}

void ListPrint(LinkList L) // 这里打印的时候不能使用&L引用
{
    L = L->next;      // 跳过头结点
    while (L != NULL) // 当L为null时,代表已经到了最后一个数据节点的next所对应的那个节点了,此时就跳出循环
    {
        printf("%3d", L->data);
        // 移动指针打印下一个数据节点
        L = L->next;
    }
    printf("\n");
}

/**
 * 尾插法创建链表
 * 和头插法的区别在于,插入的顺序和打印的顺序一致
 * @param L
 */
LinkList ListTailInsert(LinkList &L)
{
    LNode *s;
    int x;

    L = (LinkList)malloc(sizeof(LNode));

    LNode *r = L; // 尾指针变量r代表尾部节点,初始化时,指向L,以后每一次都手动指向了尾部节点,这样避免每一次都循环到最后节点再插入

    scanf("%d", &x); // 读取数据

    while (x != 9999)
    {
        // 初始化s
        s = (LNode *)malloc(sizeof(LNode));
        // data赋值
        s->data = x;
        // next赋值 将第一个数据节点指向r.next,也就是
        r->next = s;
        // r指向新的尾部节点s,即产生了一个新的数据节点,就移动到指向最新最后的尾部节点
        r = s;

        scanf("%d", &x);
    }

    r->next = NULL; // 最终结束后,尾部节点的next指向null

    return L;
}

/**
 * 按照位置查找
 * @return 返回的是节点指针
 */
LNode *GetElem(LinkList L, int i)
{
    if (i == 0) // 代表要找的是头结点这个节点
    {
        return L;
    }

    if (i < 1)
    {
        return NULL;
    }

    int j = 1; // 从1开始找,这里的1指的是除开头结点外的第一个节点

    LNode *p = L->next; // 从除开头结点开始查找,赋值给临时指针变量p

    // 循环遍历查找
    // 当j进行到等于i时,就代表找到了,跳出循环
    // 当p为null时,代表已经找到最后了,跳出循环
    while (p && j < i)
    {
        // 除开上面两种情况,只要p不为null并且还没进行到i,就一直循环下去
        p = p->next;
        j++;
    }

    // 找到的p节点进行返回
    return p;
}

/**
 * 按照数值查找
 */
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next; // 跳过头指针
    // while (p)
    // {
    //     if (e == p->data)
    //     {
    //         return p;

    //     }
    //     p = p->next;

    // }

    // p不为null并且没有匹配到e就继续循环
    while (p && p->data != e)
    {
        p = p->next;
    }

    return p;
}

/**
 * 指定位置i插入元素e
 */
bool ListFrontInsert(LinkList &L, int i, ElemType e)
{

    // 根据位置查找元素,找到i-1位置对应的节点
    LNode *s;
    s = GetElem(L, i - 1);

    // 此时判断是否异常
    if (s == NULL)
    {
        // i的范围是1到链表元素的个数,i=1也能插入,此时i-1=0,代表获取到的节点指针指向的正好是头结点
        return false; // s指针是null,代表获取到的位置的值已经是null,不在链表内了,就不能再插入了
    }

    // 创建待插入节点
    LNode *t;
    t = (LNode *)malloc(sizeof(LNode));

    // 赋值
    t->data = e;
    t->next = s->next; // 获取s.next,也就是位置i的节点,然后让t的next指向这个节点
    s->next = t;       // 再让原本s.next节点指向t

    return true;
}

int main()
{
    LinkList L;
    // ListHeadInsert(L);
    // ListPrint(L);
    // ListPrint(L);

    ListTailInsert(L);
    ListPrint(L);
    ListPrint(L);

    // 按照位置查找
    // LNode *L1;
    // L1 = GetElem(L, 3);
    // if (L1 != NULL)
    // {
    //     printf("%d\n", L1->data);
    // }

    // LNode *L2;
    // L2 = LocateElem(L, 33);
    // if (L2 != NULL)
    // {
    //     printf("%d\n", L2->data);
    // }

    ListFrontInsert(L, 2, 100);
    ListPrint(L);

    return 0;
}
