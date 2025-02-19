#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 打印链表中每个结点的值
void PrintList(LinkList L)
{

    L = L->next;

    while (L != NULL)
    {

        printf("%d", L->data); // 打印当前结点数据

        L = L->next; // 指向下一个结点

        if (L != NULL)
        {

            printf(" ");
        }
    }

    printf("\n");
}

/**
 * 头插法
 */
LinkList HeadInsert(LinkList &L)
{
    //定义变量存储输入数据
    int x;

    //定义结构体指针s代表新插入数据
    LNode *s;

    //初始化L的头结点
    L = (LinkList) malloc(sizeof(LNode));

    //让L指向下一节点NULL
    L->next = NULL;

    //读取数据scanf
    scanf("%d", &x);

    //循环判断
    while (x != 9999)
    {
        //为s申请内存空间
        s = (LNode *) malloc(sizeof(LNode));

        //s.data赋值
        s->data = x;

        //s.next赋值
        s->next = L->next;//而s指向下一节点
        L->next = s;//让L指向下一节点s

        //再次读取数据
        //再次注意这个读取数据是从缓冲区读取,我们一次性输入多个数据,都存在缓冲区,读取的时候可以按照空格分隔
        scanf("%d", &x);
    }

    return L;
    
}

/**
 * 尾插法
 */
LinkList TailInsert(LinkList &L)
{
    //定义变量存储scanf数据
    int x;
    
    //初始化头结点
    L = (LinkList)malloc(sizeof(LNode));

    //初始化时,头结点的下一节点指向NULL
    L->next = NULL;//这一步无用

    //定义尾节点指针,一直指向尾节点
    LNode *r;

    //尾节点指针的初始化,指向L头结点
    r = L;

    //定义新建数据节点s
    LNode *s;

    //读取数据
    scanf("%d", &x);

    //循环判断
    while (x != 9999)
    {
        //新节点分配内存空间
        s = (LNode *)malloc(sizeof(LNode));

        //s.data赋值
        s->data = x;

        //s.next赋值
        // s->next = r;//这步错误
        r->next = s;//只要记住r代表尾部节点,那么每次插入新数据肯定都是让r的下一节点指向新数据,这才叫尾插法
        r = s;//移动r指向最新尾节点s

        //再次读取数据
        scanf("%d", &x);

    }

    //最后结束之前,将r的下一节点指向null
    r->next = NULL;

    //返回L
    return L;//返回L而不是返回r,因为L是完整链表,而r只是单独的一个尾部节点
    
}

int main()
{
    LinkList L;

    HeadInsert(L);
    PrintList(L);

    TailInsert(L);
    PrintList(L);

    return 0;
}
