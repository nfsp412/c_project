#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitLinkList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false; // 内存不足时
    }

    L->next = NULL;
    return true;
}

void PrintLinkList(LinkList L)
{
    L = L->next; // 跳过头结点
    while (L != NULL)
    {
        printf("%4d", L->data);
        L = L->next;
    }
    printf("\n");
}

// 头插法,指的是每次插入元素到头部
// 这里的L已经初始化过,带头结点
bool InsertHeadLinkList(LinkList &L, ElemType e)
{

    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    p->next = L->next; // 让新节点插入到头部
    L->next = p;       // 调整头结点指向,指向新节点
    return true;
}

// 尾插法,指的是每次插入元素到尾部
// 这里的L已经初始化过,带头结点
bool InsertTailLinkList(LinkList &L, ElemType e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    p->next = NULL;
    // 尾插法需要先遍历到尾部,遍历到最后一个节点
    LNode *tail = L;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = p;

    return true;
}

// 尾插节点 O(1)
bool InsertTailNode(LNode *front, ElemType e)
{
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = front->next;
    front->next = tmp;

    return true;
}

// 头插节点 O(1)
// 有技巧避免O(n) 先按照尾插法插入节点,再变更数据值
bool InsertHeadNode(LNode *front, ElemType e)
{
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    tmp->next = front->next;
    front->next = tmp;

    // 变更数据值
    tmp->data = front->data;
    front->data = e;

    return true;
}

// 删除指定节点 同样使用变更数据值的方式
// 无法删除最后一个节点,因为del.next是null,空指针
bool DeleteNode(LNode *del)
{
    LNode *rear = del->next;

    // 变更数据值
    del->data = del->next->data;

    del->next = rear->next;

    free(rear);
    return true;
}

// 按位置找到节点并返回节点指针(头结点不算) O(n)
LNode *FindNodeByPos(LinkList L, int pos)
{
    // 先判0后判1,顺序别搞错了
    if (pos == 0)
    {
        return L;
    }

    if (pos < 1)
    {
        return NULL;
    }

    LNode *tmp = L->next;

    int i = 1;
    while (i < pos && tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

// 按值找到节点并返回节点指针
LNode *FindNodeByVal(LinkList L, ElemType val)
{
    LNode *tmp = L->next;
    while (tmp != NULL)
    {
        if (tmp->data == val)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

// 指定位置插入元素 尾插
bool InsertLinkList(LinkList &L, int pos, ElemType val)
{
    // LNode *tmp = (LNode *)malloc(sizeof(LNode));
    // tmp->data = val;

    // // 找到pos-1位置节点
    // LNode *front = FindNodeByPos(L, pos - 1);

    // if (front == NULL)
    // {
    //     return false;
    // }

    // // 修改引用
    // tmp->next = front->next;
    // front->next = tmp;

    // return true;

    // 封装版本
    LNode *front = FindNodeByPos(L, pos - 1);
    if (front == NULL)
    {
        return false;
    }
    return InsertTailNode(front, val);
}

// 删除指定位置元素
bool DeleteLinkList(LinkList &L, int pos)
{
    LNode *front = FindNodeByPos(L, pos - 1);
    if (front == NULL)
    {
        return false;
    }

    LNode *del = front->next;

    // 引用变更
    front->next = del->next;

    free(del);

    return true;

    // 封装
    // LNode *del = FindNodeByPos(L, pos);
    // if (del == NULL)
    // {
    //     return false;
    // }
    // return DeleteNode(del);
}

int ListLength(LinkList L)
{
    int sum = 0;
    L = L->next; // 跳过头结点
    while (L != NULL)
    {
        L = L->next;
        sum++;
    }
    return sum;
}

// 链表已经初始化
// 尾插法初始化链表 多数据手动输入
LinkList InitLinkListTail(LinkList &L)
{
    // 使用尾部指针
    LNode *tail = L;

    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        LNode *tmp = (LNode *)malloc(sizeof(LNode));

        tmp->data = x;

        tail->next = tmp;

        // 每次移动尾节点指针到最后
        tail = tail->next;

        scanf("%d", &x);
    }

    // 赋值结束后尾节点指向null
    tail->next = NULL;

    return L;
}

// 链表已经初始化
// 头插法初始化链表 多数据手动输入
LinkList InitLinkListHead(LinkList &L)
{
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        LNode *tmp = (LNode *)malloc(sizeof(LNode));
        tmp->data = x;

        tmp->next = L->next;

        L->next = tmp;

        scanf("%d", &x);
    }

    return L;
}

// 双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *next, *prior; // 既包含前驱又包含后继
} DNode, *DLinkList;

void PrintDLinkList(DLinkList L)
{
    L = L->next; // 跳过头结点
    while (L != NULL)
    {
        printf("%4d", L->data);
        L = L->next;
    }
    printf("\n");
}

// 初始化双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DLinkList)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = NULL; // 头结点的前驱永远指向null
    L->next = NULL;
    return true;
}

// 尾插,将s插入到p后面,双链表
bool InsertDNodeTail(DNode *p, DNode *s)
{
    // s的后继
    s->next = p->next;

    // 多一个空指针
    if (p->next != NULL)
    {
        // s前驱
        p->next->prior = s;
    }

    // p前驱
    s->prior = p;

    // p的后继
    p->next = s;

    return true;
}

// 构建双链表
void ConstructDLinkList(DLinkList &L)
{
    DNode *tail = L;
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        DNode *s = (DNode *)malloc(sizeof(DNode));
        // InsertDNodeTail(tail, s);

        // 尾插
        s->data = x;
        s->next = tail->next;
        if (tail->next != NULL)
        {
            tail->next->prior = s;
        }
        s->prior = tail;
        tail->next = s;

        tail = tail->next;
        scanf("%d", &x);
    }
    tail->next = NULL;
}

// 头插,将s插入p前面,双链表
bool InsertDNodeHead(DNode *p, DNode *s)
{
    // 头插实际上可以转换成尾插
    // 方法是找到p的前驱节点prior,然后对prior节点执行尾插法
    DNode *t = p->prior;
    return InsertDNodeTail(t, s);
}

DNode *FindDNodeByPos(DLinkList L, int pos)
{
    if (pos == 0)
    {
        return L;
    }
    if (pos < 1)
    {
        return NULL;
    }

    DNode *t = L->next;

    int i = 1;
    while (i < pos && t != NULL)
    {
        t = t->next;
        i++;
    }

    return t;
}

// 指定位置插入
bool InsertDLinkList(DLinkList &L, int pos, ElemType elem)
{
    // 先找到pos-1位置的节点
    DNode *p = FindDNodeByPos(L, pos - 1);
    if (p == NULL)
    {
        return false;
    }

    // 尾插法插入即可
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = elem;
    return InsertDNodeTail(p, s);
}

bool DeleteNextDNode(DNode *p)
{
    DNode *q = p->next;
    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}

bool DeleteDLinkList(DLinkList &L, int pos)
{
    // 先找到pos-1位置节点
    DNode *p = FindDNodeByPos(L, pos - 1);

    // 删除pos节点,即删除pos-1的下一节点
    return DeleteNextDNode(p);
}

bool DestroyDLinkList(DLinkList &L)
{
    // 循环删除
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L); // 释放头结点
    L = NULL;
    return true;
}

// 循环单链表,结构体和单链表一致,只是在初始化时有区别
bool InitCycleLinkList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = L; // 循环单链表,不再指向null,而是指向头结点L
    return true;
}

bool PrintCycleLinkList(LinkList L)
{
    LNode *p = L->next;
    while (p != L)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

void ConstructCycleLinkList(LinkList &L)
{
    LNode *rear = L;
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        LNode *t = (LNode *)malloc(sizeof(LNode));
        t->data = x;
        rear->next = t;
        rear = rear->next;
        scanf("%d", &x);
    }
    rear->next = L;
}

// 循环双链表
bool InitCycleDLinkList(DLinkList &L)
{
    L = (DLinkList)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = L;
    L->next = L;
    return true;
}

// 循环双链表 p之后插入s
bool InsertCycleNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    p->next->prior = s; // 此时就不需要再判断p是否是最后一个节点了,因为是循环的
    s->prior = p;
    p->next = s;
}

// 循环双链表 删除
bool DeleteCycleDLinkList(DLinkList &L, int pos)
{
    // 找到pos-1节点
    DNode *p = FindDNodeByPos(L, pos - 1);

    // 删除pos节点
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p; // 此时无需判断q是不是最后节点了
    free(q);
    return true;
}

// 测试使用,构建循环双链表
void ConstructCycleDLinkList(DLinkList &L, int *a, int len)
{
    DNode *p = L->next;
    for (int i = 0; i < len; i++)
    {
        // 循环插入到双链表中
        DNode *s = (DNode *)malloc(sizeof(DNode));
        s->data = a[i];
        InsertCycleNextDNode(p, s);
    }
}

// 测试使用,打印循环双链表
void PrintCycleDLinkList(DLinkList L)
{
    DNode *p = L->next;
    while (p != L)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

// 静态链表,分配连续内存,使用游标而不是指针,游标-1代表到尾部了,游标代表指向的下一个节点的数组下标
// 代码不实现了
// 数组的方式实现链表,适用于不支持指针的低级语言,或者数据元素个数固定不变的场景
// 缺点容量固定不变,优点增加删除不需要像顺序表那样移动大量元素
typedef struct
{
    ElemType data;
    int next;
} SLinkList[10];

// del所有x
void DeleteAllX(LinkList &L, int x)
{
    LNode *p = L;
    while (p != NULL && p->next != NULL) // 跳过头结点开始比较
    {
        if (p->next->data == x) // 当前节点下一节点的数据值为x
        {
            // 删除代码
            LNode *t = p->next; // 待删除节点
            p->next = t->next;  // 修改当前节点指向
            free(t);
        }
        p = p->next;
    }
}

// 删除所有x,学习一种双指针的写法
void DeleteAllx(LinkList &L, int x)
{
    LNode *pre = L; // 指向p的前驱
    LNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            // del
            LNode *t = p;
            p = p->next;
            pre->next = p; // 跳过t指向p
            free(t);
        }
        else
        {
            // pre和p同步后移
            pre = p;
            p = p->next;
        }
    }
}

// 删除唯一最小值 双指针移动法
void DeleteMinNode(LinkList &L)
{
    LNode *pre = L;
    LNode *p = L->next;
    LNode *min_pre = pre;
    LNode *min_p = p;

    while (p != NULL)
    {
        if (p->data < min_p->data)
        {
            // 保留min_pre和min_p

            min_pre = pre;
            min_p = p;
        }
        // 同步后移
        pre = p;
        p = p->next;
    }
    // 遍历结束后删除最小值节点
    min_pre->next = min_p->next;
    free(min_p);
}

// 单链表的原地逆置 顺序表使用swap交换 单链表使用
LinkList ReverseLinkList(LinkList &L)
{
    // pre p r初始化,p指向节点1,r指向节点2
    LNode *pre, *p = L->next, *r = p->next;
    // 处理第一个节点,指向null,因为第一个节点是逆置后的最后一个节点,自然需要指向null
    p->next = NULL;
    // 当r为空时,代表p是最后一个节点了,不再循环
    while (r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
        // 第一轮循环结束后,pre指向节点1,并且next是null,p指向节点2,r指向节点3,p的next指向pre也就是2指向1
        // 第二轮循环结束后,pre指向节点2,p指向节点3,r指向节点4,p的next指向pre也就是3指向2,1
        // 第三轮循环结束后,pre指向节点3,p指向节点4,r指向null,p的next指向pre也就是4指向3,2,1
    }
    // 当p进展到最后一个节点时,处理让链表的头指针指向p,p就由最后一个节点变成了第一个节点
    // 此时L才改变,循环的时候L是一直没有改变的
    L->next = p;
    return L;
}

// del between a and b
void DeleteAB(LinkList &L, int a, int b)
{
    // 双指针
    LNode *pre = L;
    LNode *p = L->next;
    while (p != NULL)
    {
        if (p->data >= a && p->data <= b)
        {
            LNode *t = p;
            p = p->next;
            pre->next = p;
            free(t);
        }
        else
        {
            // 同步移动
            pre = p;
            p = p->next;
        }
    }
}

// 拆分单链表为两部分 一部分正序 一部分逆序
void Divide2Part(LinkList L, LinkList &L1, LinkList &L2)
{
    LNode *r1 = L1;
    // 尾插法和头插法
    LNode *p = L->next;
    int i = 1;
    while (p != NULL)
    {
        if (i % 2 != 0)
        {
            // 奇数节点使用尾插法
            LNode *l1 = (LNode *)malloc(sizeof(LNode));
            l1->data = p->data;
            l1->next = NULL;
            r1->next = l1;
            r1 = r1->next;
        }
        else
        {
            // 偶数节点使用头插法
            LNode *l2 = (LNode *)malloc(sizeof(LNode));
            l2->data = p->data;
            l2->next = L2->next;
            L2->next = l2;
        }
        p = p->next;
        i++;
    }
}

void DistinctLinkList(LinkList &L)
{
    LNode *pre = L;
    LNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == pre->data)
        {
            // p是重复元素删除
            LNode *t = p;
            p = p->next;
            pre->next = p;
            free(t);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

// 由AB创建C
void CreateCFromAB(LinkList A, LinkList B, LinkList &C)
{
    LNode *tail = C;

    LNode *pa = A->next;
    LNode *pb = B->next;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data == pb->data)
        {
            // 相等,写入C
            LNode *t = (LNode *)malloc(sizeof(LNode));
            t->data = pa->data;
            t->next = NULL;
            tail->next = t;
            tail = tail->next;

            pa = pa->next;
            pb = pb->next;
        }
        else if (pa->data > pb->data)
        {
            pb = pb->next;
        }
        else if (pa->data < pb->data)
        {
            pa = pa->next;
        }
    }
}

// 求AB交集,存储在A中,这里没有释放B
// 归并思想,需要掌握
void UnionAB(LinkList &A, LinkList B)
{
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pc = A; // 用于操作合并后的链表
    LNode *t;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data == pb->data)
        {
            pc->next = pa; // 将交集元素使用pc指针操作
            pc = pa;

            pa = pa->next; // pa向后移动
            pb = pb->next; // pb向后移动
        }
        else if (pa->data < pb->data)
        {
            // 释放节点,pa后移
            t = pa;
            pa = pa->next;
            free(t);
        }
        else if (pa->data > pb->data)
        {
            // pb后移
            pb = pb->next;
        }
    }
    // 结束后如果A有剩余,全部释放
    while (pa != NULL)
    {
        t = pa;
        pa = pa->next;
        free(t);
    }

    pc->next = NULL;
}

// 子串的匹配 从A中是否能匹配到B子串
bool MatchSub(LinkList A, LinkList B)
{
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pre = pa;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data == pb->data)
        {
            pa = pa->next;
            pb = pb->next;
        }
        else
        {
            // 当前节点pa和pb值不等
            pre = pre->next; // pre的作用在于,每次自增1来控制A重新开始比较
            pa = pre;
            pb = B->next; // 每次重新比较,B作为子串都是要从头开始比较的,而A需要从上一次pre重新开始比较(而不是上一次不等的节点开始,that's why we must use pre)
        }
    }
    if (pb == NULL)
    {
        return true; // 如果能够到这里,证明pb已经比较完全,那证明是子串
    }
    else
    {
        return false; // 如果能到这里,证明pb还没比较完,但是pa已经比较完了,那证明pb肯定不是子串
    }
}

// 判断是否对称,带头结点
bool DLL1(DLinkList L)
{
    DNode *head = L->next;
    DNode *tail = L->prior;
    while (head != tail && head->next != tail) // 为啥不能是tail.next!=head 问题是
    {
        if (head->data != tail->data)
        {
            return false;
        }
        else
        {
            head = head->next;
            tail = tail->prior;
        }
    }
    if (head->data == tail->data)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// h2连接到h1后
void Mergeh1h2(LinkList &h1, LinkList h2)
{
    LNode *t1 = h1->next;
    while (t1->next != h1)
    {
        t1 = t1->next;
    }
    t1->next = h2->next;
    LNode *t2 = h2->next;
    while (t2->next != h2)
    {
        t2 = t2->next;
    }
    t2->next = h1;
}

// 双链表 带访问频率 freq 13题
typedef struct DFNode
{
    ElemType data;
    struct DFNode *next, *prior; // 既包含前驱又包含后继
    int freq;
} DFNode, *DFLinkList;

bool InitDFLinkList(DFLinkList &L)
{
    L = (DFLinkList)malloc(sizeof(DFNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    L->prior = NULL;
    L->data = 0;
    L->freq = 0;
    return true;
}

void ConstructDFLinkList(DFLinkList &L)
{
    DFNode *t = L;
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        DFNode *s = (DFNode *)malloc(sizeof(DFNode));
        s->data = x;
        s->freq = 0;

        s->next = t->next;
        if (t->next != NULL)
        {
            t->next->prior = s;
        }
        s->prior = t;
        t->next = s;

        t = t->next;
        scanf("%d", &x);
    }
    t->next = NULL;
}

void PrintDFLinkList(DFLinkList L)
{
    DFNode *p = L->next;
    while (p != NULL)
    {
        printf("(%d,%2d)", p->data, p->freq);
        p = p->next;
    }
    printf("\n");
}

void OrderDFNode(DFLinkList &L, DFNode *p)
{
    // 删除p节点
    DFNode *head = p->prior;
    head->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = head;
    }

    // 头插法插入p节点
    DFNode *t = L->next;
    while (t != NULL)
    {
        if (t->freq <= p->freq)
        {
            // 头插法,p插入到t之前
            DFNode *h = t->prior;
            p->next = h->next;
            if (h->next != NULL)
            {
                h->next->prior = p;
            }
            p->prior = h;
            h->next = p;

            break;
        }

        t = t->next;
    }
}

// 找x节点并返回
DFNode *Locate(DFLinkList &L, int x)
{
    DFNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            // 找到x
            p->freq++;
            // 节点排序
            OrderDFNode(L, p);
            return p;
        }

        p = p->next;
    }
    return NULL;
}

void ConstructLinkListNoHead(LinkList &L)
{
    bool flag = true;
    LNode *tail = L;
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        if (flag)
        {
            // first
            tail->data = x;
            scanf("%d", &x);
            flag = false;
        }
        else
        {
            LNode *s = (LNode *)malloc(sizeof(LNode));
            s->data = x;
            s->next = NULL;
            tail->next = s;
            tail = tail->next;
            scanf("%d", &x);
        }
    }
    tail->next = NULL;
}

void PrintLinkListNoHead(LinkList L)
{
    LNode *tail = L;
    while (tail != NULL)
    {
        printf("%4d", tail->data);
        tail = tail->next;
    }
    printf("\n");
}

// 循环右移动k单位
void CycleMoveRightLinkList(LinkList &L, int k)
{
    // 构建循环链表
    int len = 1;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    p->next = L; // 构建循环链表

    // 找n-k节点的上一节点p
    p = L;
    for (int i = 1; i < len - k; i++)
    {
        p = p->next;
    }
    L = p->next;    // 让L指向p的下一节点即n-k节点
    p->next = NULL; // 让p的下一节点指向null,即p作为尾部节点
}

bool isCycleLinkList(LinkList L)
{
    LNode *fast = L->next;
    LNode *slow = L->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        return false; // 没有环
    }
    else
    {
        return true; // 相遇,有环
    }
}

void no16(LinkList L)
{
    // 遍历构造数组
    LNode *p = L;
    int n = 1;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    int a[n];
    int i = 0;
    p = L;
    while (p != NULL)
    {
        a[i] = p->data;
        p = p->next;
        i++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%4d", a[i]);
    // }
    // printf("\n");
    // 求孪生和
    int sum = a[0] + a[n - 0 - 1];
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = a[i] + a[n - i - 1];
        if (tmp > sum)
        {
            sum = tmp;
        }
    }

    printf("sum is %d\n", sum);
}

// 寻找中间节点,有头结点,奇数的时候后半部分少于前半部分
void FindMiddleNode(LinkList L)
{
    LNode *fast = L->next;
    LNode *slow = L->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }

        slow = slow->next;
    }
    // 中间节点是:
    LNode *middle = slow->next;
    // 构建后半部分新链表,带头结点,方式:
    LinkList newL = (LinkList)malloc(sizeof(LNode));
    newL->next = slow->next;
    // 断开方式:
    slow->next = NULL;
}

// 寻找中间节点,无头结点,奇数时后半部分少
void FindMiddleNodeNoHead(LinkList L)
{
    LNode *fast = L;
    LNode *slow = L;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        slow = slow->next;
    }
    // 中间节点是:
    LNode *middle = slow->next;
    // 构建后半部分新链表方式:
    LinkList newL = slow->next;
    // 断开方式:
    slow->next = NULL;
}

int FindTailK(LinkList L, int k)
{
    // 10分写法
    // LNode *p = L->next;
    // int len = 0;
    // while (p != NULL)
    // {
    //     len++;
    //     p = p->next;
    // }
    // // printf("%d\n", len);
    // p = L->next;
    // int i = 0;
    // while (p != NULL && i != len - k)
    // {
    //     i++;
    //     p = p->next;
    // }
    // return p->data;

    // 15分写法
    LNode *p = L->next;
    LNode *q = L->next;
    int count = 0;
    while (p != NULL)
    {
        if (count < k)
        {
            count++;
        }
        else
        {
            q = q->next;
        }
        p = p->next;
    }
    return q->data;
}

int listlen(LinkList L)
{
    LNode *p = L->next;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }

    return len;
}

int func18(LinkList L1, LinkList L2)
{
    LNode *p1 = L1->next;
    LNode *p2 = L2->next;

    int l1 = listlen(L1);
    int l2 = listlen(L2);
    if (l1 > l2)
    {
        // l1较长,则移动到第l1-l2+1节点处
        for (int i = 1; i < l1 - l2 + 1; i++)
        {
            p1 = p1->next;
        }
    }
    else if (l1 < l2)
    {
        for (int i = 1; i < l2 - l1 + 1; i++)
        {
            p2 = p2->next;
        }
    }
    // l1=l2? 直接比较
    while (p1 != NULL && p2 != NULL && p1->data != p2->data)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1->data;
}

// 空间换时间
void func19(LinkList L)
{
    // 这里假设L长度固定为5,该值可以作为参数传入
    int len = 5;
    LNode *p = L;
    // int *bak = (int *)malloc(sizeof(int) * 6);
    // for (int i = 0; i < 6; i++)
    // {
    //     bak[i] = 0;
    // }
    int *bak = (int *)calloc(6, sizeof(int));

    while (p->next != NULL)
    {
        // 求绝对值
        int abs1 = p->next->data > 0 ? p->next->data : -(p->next->data);

        // 判断辅助空间是否出现该元素,没出现则对应的数组值是0,使用元素作为数组的偏移量
        if (*(bak + abs1) == 0) // 对的
        // if (bak[abs1] == 0)//不对的
        {
            *(bak + abs1) = 1; // 对的
            // bak[abs1] = 1;//不对的
            p = p->next; // 向后移动
        }
        else
        {
            // 删除节点
            LNode *s = p->next;
            p->next = s->next;
            free(s);
        }
    }
    free(bak);
}

void func20(LinkList &L)
{
    // 寻找中间节点
    LNode *fast = L->next;
    LNode *slow = L->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        slow = slow->next;
    }
    LNode *mid = slow->next;

    // 逆置
    LNode *pre;
    LNode *rear = mid->next;
    mid->next = NULL;
    while (rear != NULL)
    {
        pre = mid;
        mid = rear;
        rear = rear->next;
        mid->next = pre;
    }

    // 合并
    LNode *h1 = L->next;
    LNode *h2 = mid;

    while (h2 != NULL)
    {
        rear = h2->next;
        h2->next = h1->next;
        h1->next = h2;
        h1 = h2->next;
        h2 = rear;
    }
    h1->next = NULL;
}

void f1(LinkList L)
{
    // 找到中间节点
    LNode *fast = L->next;
    LNode *slow = L->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        fast = fast->next;
        if (fast == NULL)
        {
            break;
        }
        slow = slow->next;
    }
    LNode *mid = slow->next;

    // 逆置
    LNode *pre;
    LNode *rear = mid->next;
    mid->next = NULL;
    while (rear != NULL)
    {
        pre = mid;
        mid = rear;
        rear = rear->next;
        mid->next = pre;
    }

    // 判断(或者其他操作)
    LNode *h1 = L->next;
    LNode *h2 = mid;
    while (h2 != NULL)
    {
        if (h1->data != h2->data)
        {
            printf("no\n");
            break;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h2 == NULL)
    {
        printf("yes\n");
    }
    
}

int main()
{
    // LinkList L;
    // InitLinkList(L);
    // PrintLinkList(L);

    // InsertHeadLinkList(L, 1);
    // InsertHeadLinkList(L, 2);
    // InsertHeadLinkList(L, 3);
    // PrintLinkList(L);

    // InsertTailLinkList(L, 4);
    // InsertTailLinkList(L, 5);
    // InsertTailLinkList(L, 6);
    // PrintLinkList(L);

    // FindNodeByPos(L, 3);
    // FindNodeByVal(L, 5);

    // InsertLinkList(L, 3, 55);
    // PrintLinkList(L);

    // bool res = InsertLinkList(L, 100, 100);
    // if (res)
    // {
    //     printf("true\n");
    // }
    // else
    // {
    //     printf("false\n");
    // }

    // DeleteLinkList(L, 1);
    // PrintLinkList(L);

    // int len = ListLength(L);
    // printf("%d\n", len);
    // PrintLinkList(L);

    // LinkList L2;
    // InitLinkList(L2);
    // InitLinkListTail(L2);
    // PrintLinkList(L2);

    // LinkList L3;
    // InitLinkList(L3);
    // InitLinkListHead(L3);
    // PrintLinkList(L3);

    // 双链表
    // DLinkList L;
    // InitDLinkList(L);

    // InsertDLinkList(L, 1, 11);
    // InsertDLinkList(L, 2, 22);
    // InsertDLinkList(L, 3, 33);
    // PrintDLinkList(L);

    // InsertDLinkList(L, 2, 78);
    // PrintDLinkList(L);

    // DeleteDLinkList(L, 3);
    // PrintDLinkList(L);

    // 声明静态链表
    // SLinkList S;
    // printf("%d\n", sizeof(S)); // 10*(4+4)=80

    // 习题部分 2.3.7

    // LinkList L;
    // InitLinkList(L);
    // InitLinkListTail(L);

    // // int x = 3;
    // PrintLinkList(L);

    // 1
    //  DeleteAllX(L, x);
    //  // DeleteAllx(L, x);

    // 2
    // DeleteMinNode(L);

    // 3
    // ReverseLinkList(L);

    // 4
    // int a = 3;
    // int b = 6;
    // DeleteAB(L, a, b);

    // 6
    // LinkList L1,L2;
    // InitLinkList(L1);
    // InitLinkList(L2);
    // Divide2Part(L, L1, L2);
    // PrintLinkList(L1);
    // PrintLinkList(L2);

    // 7
    // DistinctLinkList(L);

    // 8
    // LinkList A, B;
    // InitLinkList(A);
    // InitLinkList(B);
    // InitLinkListTail(A);
    // PrintLinkList(A);
    // InitLinkListTail(B);
    // PrintLinkList(B);

    // LinkList C;
    // InitLinkList(C);
    // CreateCFromAB(A, B, C);
    // PrintLinkList(C);

    // 9
    // LinkList A, B;
    // InitLinkList(A);
    // InitLinkList(B);
    // InitLinkListTail(A);
    // PrintLinkList(A);
    // InitLinkListTail(B);
    // PrintLinkList(B);

    // UnionAB(A, B);
    // PrintLinkList(A);

    // 10
    // LinkList A, B;
    // InitLinkList(A);
    // InitLinkList(B);
    // InitLinkListTail(A);
    // // PrintLinkList(A);
    // InitLinkListTail(B);
    // // PrintLinkList(B);

    // bool res = MatchSub(A, B);
    // if (res)
    // {
    //     printf("yes\n");
    // }else{
    //     printf("no\n");
    // }

    // PrintLinkList(L);

    // 11
    // DLinkList L;
    // InitCycleDLinkList(L);
    // int a[5] = {1, 2, 100, 77, 1};
    // ConstructCycleDLinkList(L, a, 5);
    // PrintCycleDLinkList(L); // 逆序打印

    // bool res = DLL1(L);
    // if (res)
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }

    // 12
    // LinkList h1;
    // InitCycleLinkList(h1);
    // ConstructCycleLinkList(h1);
    // PrintCycleLinkList(h1);

    // LinkList h2;
    // InitCycleLinkList(h2);
    // ConstructCycleLinkList(h2);
    // PrintCycleLinkList(h2);

    // Mergeh1h2(h1, h2);
    // PrintCycleLinkList(h1);

    // 13
    // DFLinkList L;
    // InitDFLinkList(L);
    // ConstructDFLinkList(L);
    // PrintDFLinkList(L);

    // int x = 3;
    // Locate(L, x);
    // Locate(L, x);
    // Locate(L, x);

    // Locate(L, 2);
    // Locate(L, 1);
    // Locate(L, 1);
    // Locate(L, 2);
    // PrintDFLinkList(L);

    // 14
    // LinkList L;
    // InitLinkList(L);
    // ConstructLinkListNoHead(L);
    // PrintLinkListNoHead(L);
    // CycleMoveRightLinkList(L, 2);
    // PrintLinkListNoHead(L);

    // 15
    // LinkList L;
    // // InitCycleLinkList(L);
    // // ConstructCycleLinkList(L);
    // // PrintCycleLinkList(L);
    // InitLinkList(L);
    // InitLinkListTail(L);
    // PrintLinkList(L);

    // bool res = isCycleLinkList(L);
    // if (res)
    // {
    //     printf("yes\n");
    // }else{
    //     printf("no\n");
    // }

    // 16
    // LinkList L;
    // InitLinkList(L);
    // ConstructLinkListNoHead(L);
    // PrintLinkListNoHead(L);
    // no16(L);
    // 其他方法是 找到中间节点,链表后半部分逆置,遍历两个链表并求和/构建新链表等等操作

    // 练习找到中间节点
    // LinkList L;
    // InitLinkList(L);
    // InitLinkListTail(L);
    // PrintLinkList(L);
    // FindMiddleNode(L);

    // ConstructLinkListNoHead(L);
    // PrintLinkListNoHead(L);
    // FindMiddleNodeNoHead(L);

    // 17
    // LinkList list;
    // InitLinkList(list);
    // InitLinkListTail(list);
    // PrintLinkList(list);
    // printf("%d\n", FindTailK(list, 3));

    // 18
    // LinkList L1;
    // LinkList L2;
    // InitLinkList(L1);
    // InitLinkList(L2);
    // InitLinkListTail(L1);
    // InitLinkListTail(L2);
    // PrintLinkList(L1);
    // PrintLinkList(L2);

    // int res = func18(L1, L2);
    // printf("%d\n", res);

    // 19
    // LinkList L;
    // InitLinkList(L);
    // InitLinkListTail(L);
    // PrintLinkList(L);
    // func19(L);
    // PrintLinkList(L);

    // 20
    // LinkList L;
    // InitLinkList(L);
    // InitLinkListTail(L);
    // PrintLinkList(L);
    // func20(L);
    // PrintLinkList(L);

    // 68页4题
    LinkList L;
    InitLinkList(L);
    InitLinkListTail(L);
    PrintLinkList(L);
    f1(L);

    return 0;
}
