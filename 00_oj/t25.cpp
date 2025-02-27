#include <stdio.h>
#include <stdlib.h>

/**
 * 查找两个数组合并后的中位数
 * @param S1 数组1
 * @param S2 数组2
 * @param n 两个数组的长度
 */
int BiSearch(int S1[], int S2[], int n)
{
    // 针对S1和S2都使用二分查找
    int S1_low = 0;
    int S1_high = n - 1;
    int S1_mid;
    int S2_low = 0;
    int S2_high = n - 1;
    int S2_mid;

    while (S1_low < S1_high || S2_low < S2_high)
    {
        // 每次循环都进行二分
        S1_mid = (S1_low + S1_high) / 2;
        S2_mid = (S2_low + S2_high) / 2;

        if (S1[S1_mid] == S2[S2_mid])
        {
            // 中位数相等,退出循环
            return S1[S1_mid];
        }
        else if (S1[S1_mid] < S2[S2_mid])
        {
            //注意奇数个元素的舍弃方式
            if ((S1_low + S1_high) % 2 == 0)//例如0+4=4 4%2==0 4/2=2 即mid=2 正好是奇数个的中间位置的元素
            {
                //奇数个
                // 舍弃S1的低位以及S2的高位,这里和二分查找的区别在于,不要丢掉各自mid位置上的元素
                S1_low = S1_mid;
                S2_high = S2_mid;
            }else{
                //偶数个
                //为啥+1 找个例子说明即可,假设偶数个6个元素,那么首次时low是0,high是6-1=5
                //mid是(0+5)/2=2,这也代表着偶数个时的中间位置是偏靠前位置的
                //由于我们要保证丢掉的元素个数一致,那么low从0到2+1,丢掉了0 1 2 三个元素
                //high从5到2,丢掉了5 4 3 三个元素
                //刚好相等,如果不加1,那么丢掉的元素个数就不相等了,low从0到2丢掉了2个,而high从5到2丢掉了3个
                S1_low = S1_mid + 1;
                S2_high = S2_mid;

            }
        
        }else if (S1[S1_mid] > S2[S2_mid])
        {
            //S1大于S2,则丢掉S1的高位和S2的低位
            if ((S1_low + S1_high) % 2 == 0)
            {
                //奇数个
                S1_high = S1_mid;
                S2_low = S2_mid;
            }else{
                //偶数个
                S1_high = S1_mid;
                S2_low = S2_mid + 1;
            }
            
        }
        
    }

    //循环结束后输出,因为奇数个的和是偶数,偶数个的和还是偶数,所以肯定会剩余两个,选择较小的返回即可
    //注意是使用low下标而不是mid下标,否则结果错误,记住得了
    return S1[S1_low] < S2[S2_low] ? S1[S1_low] : S2[S2_low] ;
}

int main()
{

    int S1[] = {11, 13, 15, 17, 19, 33};
    int S2[] = {2, 4, 6, 8, 20, 22};

    // 找到中位数
    int res = BiSearch(S1, S2, 6);
    printf("%d\n", res);

    return 0;
}
