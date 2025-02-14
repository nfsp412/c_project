/**
 * Description

利用while或者for循环计算n！的值。

提示：n！＝1*2*3…*n


Input

一个正整数n，1≤n≤10。


Output

n！的值。


Sample Input 1

2
Sample Output 1

2
 */

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int res = 1;
    while (n)
    {
        res *= n;
        n--;
    }
    printf("%d\n", res);

    return 0;
}
