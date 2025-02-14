/**
 * Description

假如有n个台阶，一次只能上1个台阶或2个台阶，请问走到第n个台阶有几种走法？为便于读者理解题意，这里举例说明如下：假如有3个台阶，那么总计就有3种走法：第一种为每次上1个台阶，上3次；第二种为先上2个台阶，再上1个台阶；第三种为先上1个台阶，再上2个台阶。输入为n，输出为走到第n个台阶有几种走法


Input

比如输入是3


Output

如果输入是3，走到第3个台阶的走法总计有3种，1,1,1 和  1,2 和2,1，输出为3


Sample Input 1

1
Sample Output 1

1

Sample Input 2

3
Sample Output 2

3
Sample Input 3

4
Sample Output 3

5
 */

#include <stdio.h>

int Fb(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num * Fb(num - 1);
}

int step(int n)
{
    if (n == 1 || n == 2)
    {
        return n; // n=1剩1种走法,n=2剩2种走法
    }
    return step(n - 1) + step(n - 2);
}

int main()
{
    // int num = 5;
    // int res = Fb(num);
    // printf("%d\n", res);

    int n;
    scanf("%d", &n);
    int res1 = step(n);
    printf("%d\n", res1);
}