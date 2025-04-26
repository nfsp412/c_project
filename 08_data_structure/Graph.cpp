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

