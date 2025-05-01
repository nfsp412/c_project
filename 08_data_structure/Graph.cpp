#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 11111 // 定义int最大值,或者定义0,来代表不邻接

// 邻接矩阵法

typedef struct
{
    char Vex[MaxVertexNum];               // 存储顶点信息
    int Edge[MaxVertexNum][MaxVertexNum]; // 存储顶点和边对应关系,可以使用bool类型
    int vexnum;                           // 顶点数量
    int arcnum;                           // 边数量(弧数量)
} MGraph;

// 邻接表法

/**
 * 边
 */
typedef struct ArcNode
{
    int adjvex;    // 边指向哪个结点,对应的编号
    ArcNode *next; // 指向下一条边的指针
    int info;      // 边的权值
} ArcNode;

/**
 * 顶点
 */
typedef struct VNode
{
    char data;      // 数据
    ArcNode *first; // 第一条边
} VNode, AdjList[MaxVertexNum];

/**
 * 图
 */
typedef struct
{
    AdjList vertices; // 存储顶点数组
    int vexnum;       // 顶点数量
    int arcnum;       // 边数量
} ALGraph;

// 十字链表法

/**
 * 弧结点
 */
typedef struct E_Node
{
    int tailvex;   // 弧尾顶点的数组索引
    int headvex;   // 弧头顶点的数组索引
    int info;      // 权值
    E_Node *hlink; // 弧头相同的下一条弧
    E_Node *tlink; // 弧尾相同的下一条弧
} E_Node;

/**
 * 顶点结点
 */
typedef struct V_Node
{
    char data;        // 数据
    E_Node *firstin;  // 找入度时使用
    E_Node *firstout; // 找出度时使用
} V_Node, A_List[MaxVertexNum];

/**
 * 图
 */
typedef struct
{
    AdjList vertices; // 存储顶点数组
    int vexnum;       // 顶点数量
    int arcnum;       // 边数量
} G_Graph;

// 邻接多重表法

/**
 * 边结点
 */
typedef struct E2_Node
{
    int i;          // 边的顶点的编号i
    int j;          // 边的顶点的编号j
    int info;       // 权值
    E2_Node *ilink; // 依附于顶点i的下一条边
    E2_Node *jlink; // 依附于顶点j的下一条边
} E2_Node;

/**
 * 顶点结点
 */
typedef struct V2_Node
{
    char data;          // 数据
    E2_Node *firstedge; // 第一条边
} V2_Node, A2_List[MaxVertexNum];

/**
 * 图
 */
typedef struct
{
    A2_List vertices; // 存储顶点数组
    int vexnum;       // 顶点数量
    int arcnum;       // 边数量
} G2_Graph;

// 邻接矩阵的相关方法

/**
 * 判断是否存在边(x,y)/<x,y>
 * O(1)
 */
bool Adjacent(MGraph G, int x, int y)
{
    return true;
}

/**
 * 找到x相邻的边
 * O(|V|)
 */
void Neighbors(MGraph G, int x)
{

}

/**
 * 插入顶点x
 *
 * 新插入一行一列,且都为0
 * O(1)
 */
void InsertVertex(MGraph G, int x)
{

}

/**
 * 删除顶点x
 *
 * 将该顶点的行,列置0
 * 增加一个标记位置,标记该顶点是否是删除的
 *
 * O(|V|)
 */
void DeleteVertex(MGraph G, int x)
{

}

/**
 * 添加(x,y)
 *
 * 修改对应位置的值
 * O(1)
 */
void AddEdge(MGraph G, int x, int y)
{

}

/**
 * 重要
 * 找到顶点x的第一个邻接顶点
 *
 * 寻找当前行从左到右第一个1(邻接的)的节点 O(1)到O(|V|)
 *
 * 有向图场景下,出度需要查询当前行,入度需要查询当前列
 */
void FirstNeighbor(MGraph G, int x)
{
}

/**
 * 重要
 * 寻找顶点y以后的下一个和顶点x邻接的顶点
 *
 * 相当于在寻找第一个邻接顶点基础上再向后寻找一位
 * O(1)到O(|V|)
 */
void NextNeighbor(MGraph G, int x, int y)
{
}

/**
 * 获取边(x,y)的权值
 *
 * 时间复杂度等同于Adjacent方法
 */
void GetEdgeValue(MGraph G, int x, int y)
{
}

/**
 * 设置边(x,y)的权值
 *
 * 时间复杂度等同于Adjacent方法
 */
void SetEdgeValue(MGraph G, int x, int y, int val)
{
}

// 邻接表的相关方法

/**
 * 判断是否存在边(x,y)/<x,y>
 * O(1)到O(|V|)
 * 数组查询元素是O(1),最好情况就是直接查询到而且first就是
 * 一个顶点的边条数最多是n-1,即|V|-1
 */
bool Adjacent_1(ALGraph G, int x, int y)
{
    return true;
}

/**
 * 找到x相邻的边
 * 无向图 O(1)到O(|V|)
 * 数组查询元素是O(1),最好情况就是直接查询到而且first就是
 * 一个顶点的边条数最多是n-1,即|V|-1
 * 有向图 出边 时间复杂度同上
 * 有向图 入边 时间复杂度是O(|V|+|E|)
 */
void Neighbors_1(ALGraph G, int x)
{

}

/**
 * G插入顶点x
 * 插入到数组末尾,没有连接其他边
 * O(1)
 */
void InsertVertex_1(ALGraph G, int x)
{

}

/**
 * G删除顶点x
 * 删除该顶点的信息和边的信息,删除其他顶点中有涉及到的信息
 * 无向图
 * 最好O(1),此时顶点没有连接任何边,那么也无需去其他结点查询涉及的
 * 最坏O(|V|+|E|),此时需要遍历顶点数组,每个边链表遍历,删除边链表尾部结点
 * 有向图
 * 出边 O(1)到O(|V|)
 * 一个顶点的边条数最多是n-1,即|V|-1
 * 入边 时间复杂度O(|V|+|E|)
 */
void DeleteVertex_1(ALGraph G, int x)
{

}

/**
 * G添加(x,y)
 * 无向图
 * 使用头插法,O(1),尾插法,O(|V|)
 * 有向图同上
 */
void AddEdge_1(ALGraph G, int x, int y)
{

}

/**
 * 重要
 * 找到顶点x的第一个邻接顶点
 * 无向图
 * O(1)
 * 有向图
 * 出边 O(1)
 * 入边 O(1)到O(|V|+|E|),最好情况数组第一个节点的第一条边就是,最坏情况遍历所有
 * 一般不考虑找入度
 */
int FirstNeighbor_1(ALGraph G, int x)
{
    // 假设为无向图
    return G.vertices[x].first != NULL ? G.vertices[x].first->adjvex : -1;
}

/**
 * 重要
 * 寻找顶点y以后的下一个和顶点x邻接的顶点
 * 相当于在寻找第一个邻接顶点基础上再向后寻找一位
 * 无向图
 * O(1)
 * 有向图
 * 出边 O(1)
 * 入边略
 */
int NextNeighbor_1(ALGraph G, int x, int y)
{
    // 假设为无向图
    ArcNode *p = G.vertices[x].first;
    while (p->next != NULL)
    {
        if (p->adjvex == y)
        {
            return p->next->adjvex;
        }
        else
        {
            p = p->next;
        }
    }
    if (p->next == NULL)
    {
        return -1;
    }
}

/**
 * 获取边(x,y)的权值
 *
 * 时间复杂度等同于Adjacent_1方法
 */
void GetEdgeValue_1(ALGraph G, int x, int y)
{

}

/**
 * 设置边(x,y)的权值
 *
 * 时间复杂度等同于Adjacent_1方法
 */
void SetEdgeValue_1(ALGraph G, int x, int y, int val)
{
    
}

// 前置
typedef struct LNode
{
    int data; // 存储顶点编号
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

void EnQueue(LinkQueue &Q, int e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));

    p->data = e;

    p->next = NULL;

    Q.rear->next = p;

    Q.rear = p;
}

bool DeQueue(LinkQueue &Q, int &e)
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

// 广度优先遍历 BFS
bool visited[MaxVertexNum]; // 存储访问过的结点

/**
 * 打印顶点结点数据
 */
void visit(VNode v)
{
    printf("%4c", v.data);
}

/**
 * @param v 代表出发的顶点编号
 */
void BFS(ALGraph G, int v)
{
    visit(G.vertices[v]); // 访问顶点结点,打印数据
    visited[v] = true;    // 标记已访问结点

    LinkQueue Q;
    InitQueue(Q); // 初始化辅助队列

    EnQueue(Q, v); // 首个顶点入队

    while (!isEmpty(Q))
    {
        DeQueue(Q, v); // 出队

        int w;
        for (w = FirstNeighbor_1(G, v); w >= 0; w = NextNeighbor_1(G, v, w))
        {
            if (!visited[w])
            {
                // 代表w结点没有访问过
                visit(G.vertices[w]);
                visited[w] = true;

                EnQueue(Q, w); // v的邻结点w入队
            }
        }
    }
}

void BFSTraverse(ALGraph G)
{
    for (int i = 1; i <= G.vexnum; i++)
    {
        visited[i] = false; // 初始化全部为false
    }

    for (int i = 1; i <= G.vexnum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i); // 这里为了解决非连通图的遍历
            printf("\n");
        }
    }
}

#define MaxSize 10

typedef struct
{
    char data[MaxSize];
    int top; // 指向栈顶,一般0开始
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1; // 初始化
}

bool Push(SqStack &S, char x)
{
    // 数组最大元素索引应该是MaxSize-1
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.top++;           // 先移动top
    S.data[S.top] = x; // 再赋值
    return true;
}

bool Pop(SqStack &S, char &x)
{
    if (S.top == -1)
    {
        return false; // 代表栈空
    }
    x = S.data[S.top];
    S.top--;

    return true; // 代表出栈成功
}

bool isEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

typedef struct
{
    int data[MaxSize];
    int top; // 指向栈顶,一般0开始
} SqStack_int;

void InitStack_int(SqStack_int &S)
{
    S.top = -1; // 初始化
}

bool Push_int(SqStack_int &S, int x)
{
    // 数组最大元素索引应该是MaxSize-1
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.top++;           // 先移动top
    S.data[S.top] = x; // 再赋值
    return true;
}

bool Pop_int(SqStack_int &S, int &x)
{
    if (S.top == -1)
    {
        return false; // 代表栈空
    }
    x = S.data[S.top];
    S.top--;

    return true; // 代表出栈成功 
}

bool isEmpty_int(SqStack_int S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 拓扑排序
bool TopologicalSort(ALGraph G)
{
    // indegree数组,记录所有节点的入度
    // mock数据
    int indegree[5] = {0, 1, 0, 2, 2};

    // 映射数组
    // mock数据
    int B[100];
    B['A'] = 0;
    B['B'] = 1;
    B['C'] = 2;
    B['D'] = 3;
    B['E'] = 4;

    // print数组,记录拓扑排序
    char print[5];

    SqStack S;
    InitStack(S);

    for (int i = 0; i < G.vexnum; i++)
    {
        if (indegree[i] == 0)
        {

            Push(S, G.vertices[i].data); // 入度为0的顶点入栈
        }
    }
    int count = 0; // 记录输出的顶点数量
    char c;
    int tmp_i;
    while (!isEmpty(S))
    {
        Pop(S, c); // 出栈

        // 映射
        tmp_i = B[c];

        // print数组来记录拓扑排序
        print[count] = c;
        count++;

        ArcNode *p;
        for (p = G.vertices[tmp_i].first; p; p = p->next)
        {
            // 依次遍历找到下一个邻接顶点
            int v = p->adjvex;
            if (!(--indegree[v])) // 入度减一的操作相当于逻辑上删除了某个节点
            {
                Push(S, G.vertices[v].data);
            }
        }
    }

    if (count < G.vexnum)
    {
        // 有回路
        return false;
    }
    else
    {

        // 打印print数组
        for (int i = 0; i < 5; i++)
        {
            printf("%4c", print[i]);
        }
        printf("\n");

        return true;
    }
}

// 逆向拓扑排序
bool TopologicalSortReverse(ALGraph G)
{
    // outdegree数组,记录所有节点的出度
    //  mock数据
    int outdegree[5] = {1, 1, 2, 1, 0};

    // 映射数组
    // mock数据
    int B[100];
    B['A'] = 0;
    B['B'] = 1;
    B['C'] = 2;
    B['D'] = 3;
    B['E'] = 4;

    // print数组,记录拓扑排序
    char print[5];

    SqStack S;
    InitStack(S);

    for (int i = 0; i < G.vexnum; i++)
    {
        if (outdegree[i] == 0)
        {

            Push(S, G.vertices[i].data); // 入度为0的顶点入栈
        }
    }
    int count = 0; // 记录输出的顶点数量
    char c;
    int tmp_i;
    while (!isEmpty(S))
    {
        Pop(S, c); // 出栈

        // 映射
        tmp_i = B[c];

        // print数组来记录拓扑排序
        print[count] = c;
        count++;

        ArcNode *p;
        for (p = G.vertices[tmp_i].first; p; p = p->next)
        {
            // 依次遍历找到下一个邻接顶点
            int v = p->adjvex;
            if (!(--outdegree[v])) // 入度减一的操作相当于逻辑上删除了某个节点
            {
                Push(S, G.vertices[v].data);
            }
        }
    }

    if (count < G.vexnum)
    {
        // 有回路
        return false;
    }
    else
    {

        // 打印print数组
        for (int i = 0; i < 5; i++)
        {
            printf("%4c", print[i]);
        }
        printf("\n");

        return true;
    }
}

// 手动构建1
void init1(ALGraph &G)
{
    ArcNode *a1 = (ArcNode *)malloc(sizeof(ArcNode));
    a1->adjvex = 2;
    ArcNode *a2 = (ArcNode *)malloc(sizeof(ArcNode));
    a2->adjvex = 5;
    a1->next = a2;
    a2->next = NULL;
    ArcNode *b1 = (ArcNode *)malloc(sizeof(ArcNode));
    b1->adjvex = 1;
    ArcNode *b2 = (ArcNode *)malloc(sizeof(ArcNode));
    b2->adjvex = 6;
    b1->next = b2;
    b2->next = NULL;
    ArcNode *c1 = (ArcNode *)malloc(sizeof(ArcNode));
    c1->adjvex = 4;
    ArcNode *c2 = (ArcNode *)malloc(sizeof(ArcNode));
    c2->adjvex = 6;
    ArcNode *c3 = (ArcNode *)malloc(sizeof(ArcNode));
    c3->adjvex = 7;
    c1->next = c2;
    c2->next = c3;
    c3->next = NULL;
    ArcNode *d1 = (ArcNode *)malloc(sizeof(ArcNode));
    d1->adjvex = 3;
    ArcNode *d2 = (ArcNode *)malloc(sizeof(ArcNode));
    d2->adjvex = 7;
    ArcNode *d3 = (ArcNode *)malloc(sizeof(ArcNode));
    d3->adjvex = 8;
    d1->next = d2;
    d2->next = d3;
    d3->next = NULL;
    ArcNode *e1 = (ArcNode *)malloc(sizeof(ArcNode));
    e1->adjvex = 1;
    e1->next = NULL;
    ArcNode *f1 = (ArcNode *)malloc(sizeof(ArcNode));
    f1->adjvex = 2;
    ArcNode *f2 = (ArcNode *)malloc(sizeof(ArcNode));
    f2->adjvex = 3;
    ArcNode *f3 = (ArcNode *)malloc(sizeof(ArcNode));
    f3->adjvex = 7;
    f1->next = f2;
    f2->next = f3;
    f3->next = NULL;
    ArcNode *g1 = (ArcNode *)malloc(sizeof(ArcNode));
    g1->adjvex = 3;
    ArcNode *g2 = (ArcNode *)malloc(sizeof(ArcNode));
    g2->adjvex = 4;
    ArcNode *g3 = (ArcNode *)malloc(sizeof(ArcNode));
    g3->adjvex = 6;
    ArcNode *g4 = (ArcNode *)malloc(sizeof(ArcNode));
    g4->adjvex = 8;
    g1->next = g2;
    g2->next = g3;
    g3->next = g4;
    g4->next = NULL;
    ArcNode *h1 = (ArcNode *)malloc(sizeof(ArcNode));
    h1->adjvex = 4;
    ArcNode *h2 = (ArcNode *)malloc(sizeof(ArcNode));
    h2->adjvex = 7;
    h1->next = h2;
    h2->next = NULL;
    G.vertices[1].first = a1;
    G.vertices[1].data = 'A';
    G.vertices[2].first = b1;
    G.vertices[2].data = 'B';
    G.vertices[3].first = c1;
    G.vertices[3].data = 'C';
    G.vertices[4].first = d1;
    G.vertices[4].data = 'D';
    G.vertices[5].first = e1;
    G.vertices[5].data = 'E';
    G.vertices[6].first = f1;
    G.vertices[6].data = 'F';
    G.vertices[7].first = g1;
    G.vertices[7].data = 'G';
    G.vertices[8].first = h1;
    G.vertices[8].data = 'H';

    G.vexnum = 8;
    G.arcnum = 10;
}

// 非连通图构建
void init2(ALGraph &G)
{
    ArcNode *a1 = (ArcNode *)malloc(sizeof(ArcNode));
    a1->adjvex = 10;
    ArcNode *a2 = (ArcNode *)malloc(sizeof(ArcNode));
    a2->adjvex = 11;
    a1->next = a2;
    a2->next = NULL;
    ArcNode *b1 = (ArcNode *)malloc(sizeof(ArcNode));
    b1->adjvex = 9;
    ArcNode *b2 = (ArcNode *)malloc(sizeof(ArcNode));
    b2->adjvex = 11;
    b1->next = b2;
    b2->next = NULL;
    ArcNode *c1 = (ArcNode *)malloc(sizeof(ArcNode));
    c1->adjvex = 9;
    ArcNode *c2 = (ArcNode *)malloc(sizeof(ArcNode));
    c2->adjvex = 11;
    c1->next = c2;
    c2->next = NULL;
    G.vertices[9].first = a1;
    G.vertices[9].data = 'I';
    G.vertices[10].first = b1;
    G.vertices[10].data = 'J';
    G.vertices[11].first = c1;
    G.vertices[11].data = 'K';

    G.vexnum += 3;
    G.arcnum += 3;
}

// 拓扑排序mock
void init3(ALGraph &G)
{
    ArcNode *a1 = (ArcNode *)malloc(sizeof(ArcNode));
    a1->adjvex = 1;
    a1->next = NULL;
    ArcNode *b1 = (ArcNode *)malloc(sizeof(ArcNode));
    b1->adjvex = 3;
    b1->next = NULL;
    ArcNode *c1 = (ArcNode *)malloc(sizeof(ArcNode));
    c1->adjvex = 3;
    ArcNode *c2 = (ArcNode *)malloc(sizeof(ArcNode));
    c2->adjvex = 4;
    c1->next = c2;
    c2->next = NULL;
    ArcNode *d1 = (ArcNode *)malloc(sizeof(ArcNode));
    d1->adjvex = 4;
    d1->next = NULL;
    G.vertices[0].first = a1;
    G.vertices[0].data = 'A';
    G.vertices[1].first = b1;
    G.vertices[1].data = 'B';
    G.vertices[2].first = c1;
    G.vertices[2].data = 'C';
    G.vertices[3].first = d1;
    G.vertices[3].data = 'D';
    G.vertices[4].first = NULL;
    G.vertices[4].data = 'E';

    G.vexnum = 5;
    G.arcnum = 5;
}

// 逆向拓扑排序mock数据
void init4(ALGraph &G)
{
    ArcNode *a1 = (ArcNode *)malloc(sizeof(ArcNode));
    a1->adjvex = 0;
    a1->next = NULL;
    ArcNode *b1 = (ArcNode *)malloc(sizeof(ArcNode));
    b1->adjvex = 2;
    ArcNode *b2 = (ArcNode *)malloc(sizeof(ArcNode));
    b2->adjvex = 1;
    b1->next = b2;
    b2->next = NULL;
    ArcNode *c1 = (ArcNode *)malloc(sizeof(ArcNode));
    c1->adjvex = 3;
    ArcNode *c2 = (ArcNode *)malloc(sizeof(ArcNode));
    c2->adjvex = 2;
    c1->next = c2;
    c2->next = NULL;

    G.vertices[0].first = NULL;
    G.vertices[0].data = 'A';
    G.vertices[1].first = a1;
    G.vertices[1].data = 'B';
    G.vertices[2].first = NULL;
    G.vertices[2].data = 'C';
    G.vertices[3].first = b1;
    G.vertices[3].data = 'D';
    G.vertices[4].first = c1;
    G.vertices[4].data = 'E';

    G.vexnum = 5;
    G.arcnum = 5;
}

// 深度优先遍历 DFS
void DFS(ALGraph G, int v)
{
    visit(G.vertices[v]);
    visited[v] = true;

    int w;
    for (w = FirstNeighbor_1(G, v); w >= 0; w = NextNeighbor_1(G, v, w))
    {
        if (!visited[w])
        {
            // 代表w结点没有访问过
            DFS(G, w); // 递归深度
        }
    }
}

void DFSTraverse(ALGraph G)
{
    for (int i = 1; i <= G.vexnum; i++)
    {
        visited[i] = false; // 初始化全部为false
    }

    for (int i = 1; i <= G.vexnum; i++)
    {
        if (!visited[i])
        {
            DFS(G, i); // 这里为了解决非连通图的遍历
            printf("\n");
        }
    }
}

// DFS实现逆向拓扑排序(不使用逆向邻接表),将输出语句移动到退出递归前面,即执行输出语句后立即退出递归
bool visited1[5];

void DFS1(ALGraph G, int v)
{
    visited1[v] = true;

    int w;
    for (w = FirstNeighbor_1(G, v); w >= 0; w = NextNeighbor_1(G, v, w))
    {
        if (!visited1[w])
        {
            // 代表w结点没有访问过
            DFS1(G, w); // 递归深度
        }
    }

    visit(G.vertices[v]);
}

void TopologicalSortReverse_DFS(ALGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited1[i] = false; // 初始化全部为false
    }

    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited1[i])
        {
            DFS1(G, i); // 这里为了解决非连通图的遍历
        }
    }
}

int main()
{
    // 手动构建
    ALGraph G;
    init1(G);

    // printf("%d",FirstNeighbor_1(G, 8));
    // printf("%d",NextNeighbor_1(G, 5, 1));

    // A   B   E   F   C   G   D   H
    // 1   2   5   6   3   7   4   8
    // BFSTraverse(G);

    // 非连通图
    //  A   B   E   F   C   G   D   H   I   J   K
    //  1   2   5   6   3   7   4   8   9   10  11
    init2(G);
    // BFSTraverse(G);

    // A   B   F   C   D   G   H   E   I   J   K
    // 1   2   6   3   4   7   8   5   9   10  11
    DFSTraverse(G);

    // 拓扑排序
    ALGraph G1;
    init3(G1);

    // C   A   B   D   E
    // 2   0   1   3   4
    TopologicalSort(G1);

    // 逆向拓扑排序
    // 这里使用逆向邻接表
    ALGraph G2;
    init4(G2);

    // E   D   B   A   C
    // 4   3   1   0   2
    TopologicalSortReverse(G2);

    // DFS实现逆向拓扑排序(不使用逆向邻接表)
    TopologicalSortReverse_DFS(G1);

    return 0;
}
