#include <stdio.h>

#define PI 3 + 2

/**
 * 宏定义
 * PI整体替换为3 + 2,而不是替换为5
 */
void defineConstantFunc()
{
    int i = PI * 2;
    printf("i = %d\n", i); // 7 = 2*2+3
}

/**
 * 数据类型
 */
void dataTypeFunc()
{
    int i = 4; // 4字节
    printf("i = %d, size = %d\n", i, sizeof(i));

    float f1 = 2.5;  // 2.500000
    float f2 = 3e-3; // 0.003000
    printf("f1 = %f, f2 = %f\n", f1, f2);

    char c1 = 'a';           // 1字节,存储的是ASCII数值
    printf("%c\n", c1);      // a
    printf("%d\n", c1);      // 97
    printf("%c\n", c1 - 32); // A

    printf("%s\n", "username");
    printf("%d\n", sizeof("username")); // 9 最后\0结束
}

/**
 * 强制类型转换
 */
void forceTypeConversionFunc()
{
    int i = 5;
    float f1 = i / 2;
    float f2 = (float)i / 2;
    printf("f1 = %f\n", f1); // 2.000000 默认是整除的
    printf("f2 = %f\n", f1); // 2.000000 强制类型转换??
}

/**
 * 格式化输出
 * %d, %f, %c, %s
 */
void printfFunc()
{
    int i = 3;
    float f = 2.5;
    printf("i = %3d, f = %.2f \n", i, f);
}

/**
 * 二进制数字转换
 * 转换八进制: 3位转换成一位八进制数字,开头补0进行识别
 * 转换十六进制: 4位转换成一位十六进制数字,开头补0x进行识别
 * 转换成十进制: 2的幂次相加的方法
 *
 * 市面上CPU大都是小端方式进行数据存储,所以数据的低位放在前面
 */
void jinzhiFunc()
{
    int i = 123;
    printf("%d\n", i);
    printf("%p\n", &i);
    printf("%x\n", i); // 十六进制是0x7b
}

/**
 * 标准输入: 从键盘输入
 * 输入的数据都是字符串,根据%d转换成了整数类型,即根据不同类型进行转换,实际上scanf函数是很复杂的
 *
 *
 */
void scanfFunc()
{
    int i = 10; // 调试的时候注意,如果变量没有初始化赋值,那么断点不会执行
    char c;
    float f;
    int ret;

    // scanf("%d", &i);
    // printf("i = %d\n", i);

    // fflush(stdin); // 解决不阻塞问题, 注意如果不支持fflush(stdin),使用scanf("%c", &c)来解决\n问题

    // scanf("%c", &c);       // 为啥没有阻塞?因为输入了\n,而i没有读取\n,所以c会读取缓冲区中剩余的\n,所以没有阻塞
    // printf("c = %c\n", c); // 字符1
    // printf("c = %d\n", c); // 对应ASCII 49

    // scanf("%f", &f);
    // printf("f = %f\n", f); // 为啥这个时候不会阻塞?因为scanf函数读取整数,浮点数,字符串,会忽略\n和空格,忽略指的是scanf会首先从缓冲区删除这两个字符再看是否会阻塞

    // 一次性读取多个
    ret = scanf("%d %c%f", &i, &c, &f); //%d和%c之间要有一个空格,因为不会忽略空格,而我们输入的时候是使用空格分隔的
    printf("i = %d, c = %c,f = %f\n", i, c, f);
}

int main()
{
    defineConstantFunc();

    dataTypeFunc();

    forceTypeConversionFunc();

    printfFunc();

    jinzhiFunc();

    scanfFunc();

    return 0;
}