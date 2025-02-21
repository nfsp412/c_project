#include <stdio.h>
#include <stdlib.h>

// 是12.4章节的编码过程

/**
 * 空间复杂度O(1) 代表不能额外申请内存
 * 重排单链表
 * 原本是1 2 3 n-2 n-1 n
 * 重排后应该是1 n 2 n-1 3 n-2
 *
 * 思路
 * 1 找到L的中间节点
 * 2 后半部分赋值给新的头结点L1
 * 3 将L1倒序排列
 * 4 合并前半部分L和后半部分L1
 */

typedef struct node
{
    int data;
    struct node *next;
} NODE, *LinkList; // 这里可以添加一个*LinkList结构体指针

/**
 * 这里使用尾插法初始化
 */
LinkList InitList(LinkList &L)
{
    // 创建变量存储输入数据
    int x;

    // 创建指针存储新建节点
    NODE *s;

    // 初始化头结点
    L = (LinkList)malloc(sizeof(NODE));

    // 定义尾节点
    NODE *r;
    r = L;

    // 第一次读取数据
    scanf("%d", &x);

    while (x != 9999)
    {
        // 新节点初始化
        s = (NODE *)malloc(sizeof(NODE));

        // data赋值
        s->data = x;

        // next赋值
        r->next = s;

        // 尾节点移动
        r = s;

        // 再次读取数据
        scanf("%d", &x);
    }

    r->next = NULL;

    return L;
}

void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

void FindMiddleList(LinkList L, LinkList &L2)
{
    LinkList pcur, ppre;
    pcur = ppre = L->next; // 跳过头结点

    while (pcur != NULL)
    {
        pcur = pcur->next; // 走一步
        if (pcur == NULL)
        {
            break;
        }
        pcur = pcur->next; // 再走一步,一共走两步
        if (pcur == NULL)
        {
            break;
        }

        ppre = ppre->next; // 只走一步
    }

    // 为L2初始化头结点
    L2 = (LinkList)malloc(sizeof(NODE));

    // 让L2指向L链表的后半部分
    // 为什么是ppre.next?
    // 假设链表个数是偶数个,例如6个,那么后半部分指的是4 5 6,触发break时,ppre还指向3,所以应该是ppre.next
    // 假设链表个数是奇数个,例如5个,那么后半部分指的是4 5,触发break时,ppre还指向3,所以应该是ppre.next
    /**
     * 跳过头结点

奇数个
第一轮 pcur 1 -> 3 ppre 1 -> 2
第二轮 pcur 3 -> 5 ppre 2 -> 3
第三轮 pcur 5 -> 6 触发break
此时状态 pcur 是null节点 ppre 指向3
让L2指向后半部分,即指向4 5,那么前半部分就剩下1 2 3

偶数个
第一轮 pcur 1 -> 3 ppre 1 -> 2
第二轮 pcur 3 -> 5 ppre 2 -> 3
第三轮 pcur 5 -> 7 触发break
此时状态 pcur 是null节点 ppre 指向3
让L2指向后半部分,即指向4 5 6,那么前半部分就剩下1 2 3
     */
    L2->next = ppre->next;

    // 让L只保留链表的前半部分
    // 如何保留?只需要让找到的中间节点指向NULL
    // 链表个数是偶数个时,例如6个,此时ppre指向3,ppre.next指向4,所以应该让ppre.next不再指向4而是指向null
    // 链表个数是奇数个时,例如5个,此时ppre指向3,ppre.next指向4,所以应该让ppre.next不再指向4而是指向null
    ppre->next = NULL;
}

/**
 * 初始化后
r 5 6 7 8 null
s 6 7 8 null
t 7 8 null

第一次循环

s.next = r 操作
r 5 6 5...循环
s 6 5 6 5...循环
L2 5 6 5...循环
t不变

r = s 操作
让r不再指向数据5的节点,而是指向数据6的节点,和s指向相同
其余的都不变

s = t 操作
让s不再指向数据6的节点,而是指向t的7 8 null的节点
其余的都不变

t = t.next 操作
这里也说明t的作用就是移动指针一直到最后的,是循环的条件
让t不再指向 7 8 null,而是移动一位,指向8 null

第二次循环

s.next = r 操作
让s的下一节点不再指向8 null,而是指向r的6 5 6的循环,即现在s指向的是7 6 5 6循环

r = s 操作
让r指向和s相同的节点

s = t 操作
让s不再指向7 6 5 6循环,而是指向8 null

t = t.next 操作
t再次向右移动一位节点,此时指向null,退出循环

s目前指向8 null,需要让他的next不指向null,而是指向7才行,此时哪个节点保存了7呢?r,此时r是7 6 5 6的循环

L2.next.next指向null,这代表原本是5 6 5 6循环,现在是5 null
这里改变以后,同步的s里面的5 6 5 6的循环,也改为了5 null
同理,r里面的5 6 5 6循环,也改为了5 null
这一步就是解决循环指针指向的问题的

L2.next指向s,L2原本是5 null,现在改为不指向5 null了,改为指向s,s即翻转后的结果,即8 7 6 5 null


 */
void ReverseList(LinkList &L2)
{

    // 初始化r s t,并且都跳过头指针指向L2的第一个数据节点
    NODE *r, *s, *t;
    r = s = t = L2->next;

    if (r == NULL)
    {
        return; // 代表链表为空,即头结点指向了null
    }

    s = t = t->next;
    if (t == NULL)
    {
        return; // 代表只有一个数据节点,无需翻转
    }

    t = t->next;

    /**
     * 代码执行到这里时,r指向第一个节点,s指向第二个节点,t指向第三个节点
     */

    // 进入循环体,跳出条件是t指向的节点已经到达了null,这代表已经到链表尾部
    while (t != NULL)
    {
        s->next = r;

        r = s;

        s = t;

        t = t->next;
    }

    s->next = r;

    L2->next->next = NULL;

    L2->next = s;
}

/**
 * 合并L1和L2链表
 *
 */
void MergeList(LinkList L1, LinkList L2)
{
    LinkList pcur, p, q;
    pcur = p = L1->next; // 跳过头指针 让pcur永远指向组合后链表的尾部节点
    q = L2->next;        // 跳过头指针 q指向L2第一个节点,用来对L2进行遍历
    p = p->next;         // 直接跳过第一个节点,因为L1作为新链表,第一个数据自然不需要移动 从第二个数据开始 p指向L1的第二个节点,用来对L1进行遍历
    while (q != NULL && p != NULL)
    {
        pcur->next = q;    // 原本pcur指向的是L1的第一个数据节点,现在让他的next指向q的第一个节点
        q = q->next;       // L2链表向右移动
        pcur = pcur->next; // L1链表向右移动,始终指向的是L1尾节点
        pcur->next = p;    // L1的第二个节点给pcur
        p = p->next;       // L1向右移动一位
        pcur = pcur->next; // pcur继续向右移动
    }

    //循环结束后,如果是偶数情况下,p由于是从第二个数据开始的,所以最先到达null,此时q一定还存在一个剩余数据,这个数据正好让pcur的next对应到
    //如果是奇数个情况下,p和q会同时到达null,不再剩余未添加的元素
    if (q != NULL)
    {
        pcur->next = q;
    }

    
}

int main()
{
    LinkList L;
    InitList(L);
    // PrintList(L);

    LinkList L2;
    FindMiddleList(L, L2);
    // PrintList(L);
    // PrintList(L2);

    ReverseList(L2);
    // PrintList(L);
    // PrintList(L2);

    MergeList(L, L2);
    PrintList(L);
    
}
