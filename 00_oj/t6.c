/**
 * Description

输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，int类型存不下，不用考虑负值；

例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no


Input

一个整型数


Output

输出是yes，或者no

Sample Input 1 

12321
Sample Output 1

yes
 */


 #include <stdio.h>

 int main()
 {
     int i;
     scanf("%d", &i);
 
     int reverse = 0; // 存储反转后的i
     int i_back = i;  // 存储i的备份
     while (i)
     {
         int tmp = i % 10;
         i /= 10;
         reverse = reverse * 10 + tmp;
     }
 
     if (reverse == i)
     {
         printf("yes\n");
     }
     else
     {
         printf("no\n");
     }
 
     return 0;
 }
 