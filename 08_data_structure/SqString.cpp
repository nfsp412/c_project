#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255

// 串 即字符串
// 是一种特殊的线性表 可以使用顺序存储实现,如下
// 存储方案和书上保持一致,即舍弃首位ch[0]不用,使用length存储长度
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

// 也可以使用动态数组实现,如下
typedef struct
{
    char *ch;
    int length;
} HString;

// 也可以使用链表实现,如下
// 存储密度低,所以让一个节点存储多个字符,例如ch[4]
// 存储不满则使用特殊字符填充
typedef struct StringNode
{
    char ch[4];
    struct StringNode *next;
} StringNode, *String;

// 待实现的基本操作
// 数组创建字符串
void StrAssign(SString &T, char chars[], int length)
{
    for (int i = 0; i < length; i++)
    {
        T.ch[i + 1] = chars[i];
    }
    T.length = length;
}

// 字符串复制
void StrCopy(SString &T, SString S)
{
    for (int i = 0; i < S.length; i++)
    {
        T.ch[i + 1] = S.ch[i + 1];
    }
    T.length = S.length;
}

// 字符串判空
bool StrEmpty(SString S)
{
    if (S.length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 字符串长度
int StrLength(SString S)
{
    return S.length;
}

// 清空字符串
void ClearString(SString &S)
{
    S.length = 0;
}

// 销毁字符串
void DestroyString(SString &S)
{
}

// 字符串拼接
void Concat(SString &T, SString S1, SString S2)
{
}

// 字符串截取,从pos开始截取len长度,包含pos位置
bool SubString(SString &Sub, SString S, int pos, int len)
{
    // 子串是否越界判断
    if (pos + len - 1 > S.length)
    {
        return true;
    }
    for (int i = pos; i < pos + len; i++)
    {
        // 从索引1开始存储,所以+1
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

// 字符串打印展示
void PrintString(SString S)
{
    for (int i = 1; i <= S.length; i++)
    {
        putchar(S.ch[i]);
    }
    putchar('\n');
}

// 返回正数代表前面字符串大
int StrCompare(SString S, SString T)
{
    // 退出的条件是,只要有一个字符串遍历结束了,就退出循环
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        // 比较的条件是,依次比较同位置上的元素的ASCII值,值大的代表字符串大
        // 前面大的返回正数,相等返回0,前面小的返回负数
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    // 字符都相同,则字符串长的代表字符串大
    // 前面大的返回正数,相等返回0,前面小的返回负数
    return S.length - T.length;
}

// 查找子串
int Index(SString S, SString T)
{
    // 暂存子串
    SString Sub;

    // 每次从头开始取子串出来进行比较
    int pos = 1;

    // 循环退出的条件
    // 若S=T,则能循环一次
    // 若S<T,则一次都无法循环
    // 若S>T,则能够循环
    while (pos <= S.length - T.length + 1)
    {
        // 取子串出来进行比较
        SubString(Sub, S, pos, T.length);

        if (StrCompare(Sub, T) == 0)
        {
            // 相等
            return pos;
        }
        else
        {
            pos++;
        }
    }

    // 循环结束,代表没找到,规定返回0
    return 0;
}

/**
 * 字符串的朴素模式匹配算法
 * 即暴力破解法,找出主串中所有长度和模式串相等的子串,然后让每个子串依次和模式串进行比较,从而进行匹配
 * 例如在S中匹配T
 * 最坏时间复杂度 O(nm) 即每次匹配m字符,一共匹配了n-m+1次 注意很多时候n>>m
 *
 */
int Pattern(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) // 这里发现和字符串比较的循环退出条件是一样的
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2; // 每一次的重新比较,都需要把S子串向后移动一位
            j = 1;         // 每一次的重新比较,都需要把T子串重置到初始位置,即j=1位置
        }
    }
    // 退出循环后,如果j已经超过模式串的长度,代表匹配成功
    if (j > T.length)
    {
        return i - T.length; // 返回匹配到的位置
    }
    else
    {
        // 匹配失败
        return 0;
    }
}

// 滑动距离公式 j - nextval[j]
// 

/**
 * 问题3 如何得到一个next数组?
 *
 * 解决方式: 手动是可以枚举演算出来的,画分界线,依次比较,直到对得上,或者跨过分界线为止
 * 注意
 * next[0] 不存储数据
 * next[1] 一定为0
 * next[2] 一定为1
 *
 * 举例: aaaab
 * next[0] 1 2 3 4 5
 * null    0 1 2 3 4
 *
 * 最坏时间复杂度 O(m+n) 模式匹配O(n) next数组求解O(m)
 *
 * 问题4 如何优化next数组?
 *
 * 优化点1 当next[j]的索引对应的数据值 和j本身位置对应的数据值相等 则可以优化 优化后叫做nextval数组
 * 主串ab? 模式串aba next[3]匹配失败 不优化时应该赋值1
 * 但是由于?处一定不是a,所以从1开始匹配没意义,应该跳过?匹配下一个?,所以我们next[3]赋值0
 *
 * 主串abaa? 模式串abaab next[5]匹配失败 不优化时应该赋值2
 * 但是由于?处一定不是b,所以从2开始匹配,(即a?)没有意义,应该跳过?匹配下一个?,next[5]赋值1
 *
 * 问题5 如何通过next数组求解nextval数组?
 *
 * 解决方式: 先手动求出next数组,再优化为nextval数组
 * 伪代码
 * nextval[1] = 0
 * for j = 2; j <= T.length; j++
 *      if T.ch[next[j]] == T.ch[j] nextval[j] = nextval[next[j]]
 *      else nextval[j] = next[j]
 * 举例: aaaab
 * next[0] 1 2 3 4 5
 * null    0 1 2 3 4
 * T.ch    a a a a b
 * 
 * nextval数组
 * nextval[0] 1 2 3 4 5
 * null       0 0 0 0 4
 * 
 * 代码略
 */
void GetKMPNext()
{
}

/**
 * 字符串的KMP算法
 * 问题1 跳过中间不匹配的字符,如何跳过?不比较怎么能知道是否可以跳过呢?
 * 问题2 跳过开头两个匹配的字符,同样的问题,如何跳过?不比较怎么能知道是否可以跳过?
 * 解决这两个问题后,就可以实现主串指针i不变,模式串指针j不一定非要回归1,从而提示效率
 *
 * 解决方式: 使用next数组,事先将模式串的匹配失败的各自不同的情况都列举出
 * 然后存储失败元素位置和j位置的信息到该数组
 * 伪代码
 * if S[i] != T[j] j = next[j]
 * if j == 0 i++ j++
 *
 * 问题3 如何得到一个next数组?
 *
 */
int KMP(SString S, SString T, int next[])
{
    int i = 1;
    int j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j] || j == 0) // 多了一个j==0判断
        {
            i++;
            j++;
        }
        else
        {
            // 使用next数组而不是回溯
            j = next[j];
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    else
    {
        return 0;
    }
}

int main()
{
    SString S;
    char ch[] = "hello world!";
    StrAssign(S, ch, 12);
    PrintString(S);

    SString Sub;
    SubString(Sub, S, 2, 3);
    PrintString(Sub);

    SString T;
    char ch_1[] = "wor";
    StrAssign(T, ch_1, 3);
    PrintString(T);
    int i_1 = Index(S, T);
    printf("%d\n", i_1);

    int i_2 = StrCompare(Sub, T);
    if (i_2 > 0)
    {
        printf("S1 > S2\n");
    }
    else if (i_2 < 0)
    {
        printf("S1 < S2\n");
    }
    else
    {
        printf("S1 = S2\n");
    }

    // SString S1;
    // StrAssign(S1, "abcdefghijk", 11);
    // SString T1;
    // StrAssign(T1, "eafg", 3);
    // printf("%d\n", Pattern(S1, T1));

    return 0;
}
