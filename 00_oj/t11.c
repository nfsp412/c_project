/**
 * Description

输入一个整型数，存入变量i，通过子函数change把主函数的变量i除2，然后打印i，例如如果输入的为10，打印出5，如果输入的为7，打印出3


Input

一个整型数


Output

对应整型数除2后的商


Sample Input 1

10
Sample Output 1

5
 */

#include <stdio.h>

void change(int *p)
{
    *p /= 2;
}

int main()
{
    int i;
    scanf("%d", &i);
    // printf("%d\n", i);

    change(&i);

    printf("%d\n", i);

    return 0;
}
