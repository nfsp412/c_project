/**
 * Description

你的任务是计算a+b。



Input

输入包含a和b，通过空格隔开


Output

需要输出a、b的和

Sample Input 1

4
Sample Output 1

5
 */

#include <stdio.h>

int main()
{
    int a;
    int b;
    scanf("%d%d", &a, &b);
    int res = a + b;
    printf("%d\n", res);
    return 0;
}