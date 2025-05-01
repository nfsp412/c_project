#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

// 双亲表示法

typedef struct
{
    int data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int len;
} PTree;

// 孩子表示法

typedef struct
{
    int child;
    CTNode *next;
} CTNode;

typedef struct
{
    int data;
    CTNode *first; // 指向第一个孩子
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int len;
    int r; // 记录根节点地址
} CTree;

// 孩子兄弟表示法

typedef struct CSNode{
    int data;
    CSNode *firstChild, *rightBrother;//注意这里是第一个孩子结点以及右兄弟结点 所以才叫做孩子兄弟表示法
}CSNode,*CSTree;

int main()
{

    return 0;
}
