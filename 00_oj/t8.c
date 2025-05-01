/**
 * Description

某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？


Input

无输入


Output

一个数，表示共有多少种换法


Sample Input 1 

无
Sample Output 1

不能告知，因为只有一个数，偷偷告诉你小于100
 */

 #include <stdio.h>

 int main()
 {
     int cnt = 0;
     for (int i_10 = 1; i_10 <= 10; i_10++)
     {
         for (int i_5 = 1; i_5 <= 20; i_5++)
         {
             for (int i_2 = 1; i_2 <= 40; i_2++)
             {
                 for (int i_1 = 1; i_1 <= 40; i_1++)
                 {
                     if (i_10 + i_5 + i_2 + i_1 == 40 && i_10 * 10 + i_5 * 5 + i_2 * 2 + i_1 * 1 == 100)
                     {
                         cnt++;
                     }
                 }
             }
         }
     }
     printf("%d\n", cnt);
 
     return 0;
 }
 