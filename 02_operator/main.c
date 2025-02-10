#include <stdio.h>

/**
 * 算数运算符
 * 乘 除 取余优先级高于加 减
 * 除法/,当两个数字都是整数类型,则整除,其他情况下浮点型除法
 */
void arithmeticOperatorFunc()
{
    int i = 5;
    float f1 = i / 2;
    float f2 = (float)i / 2;
    printf("f1 = %f\n", f1); // 2.000000 默认是整除的
    printf("f2 = %f\n", f2); // 2.500000 强制类型转换
}

/**
 * 关系运算符
 * > < == >= <= !=
 * 没有布尔,所以非0真0假,即表达式返回值是整数类型的1或者0
 * 优先级低于算数运算符
 */
void relationalOperatorFunc()
{
    int a = 1;
    // if (1 < a < 3)
    // {
    //     printf("1 < a < 3 \n"); // 这样写是错误的,正确写法如下
    // }

    if (1 < a && a < 3)
    {
        printf("1 < a < 3 \n");
    }
}

/**
 * 逻辑运算符
 * ! && ||
 * 逻辑与 逻辑或优先级低于关系运算符
 * 逻辑非优先级高于算术运算符
 * 表达式返回值是整数类型的1或者0
 */
void logicalOperatorFunc()
{
    // 短路运算
    int d = 0;
    d &&printf("can see\n"); // 短路运算,即d为0假则整个逻辑运算表达式已经是假,所以不再执行后面的部分

    // 逻辑非
    int a = 10;
    // int b = !a;//0
    int b = !!a; // 1
    printf("!a = %d\n", b);

    int i = 0;
    int j = 1;
    // while (scanf("%d", &i)) // 输入非整数类型时会跳出循环
    // {
    //     if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
    //     {
    //         printf("%d is leap year \n", i);
    //     }
    //     else
    //     {
    //         printf("%d is not leap year \n", i);
    //     }
    // }
}

/**
 * 赋值运算符
 * =
 * 左值,指的是能够出现在赋值符号左边的东西
 * 右值,指的是能够出现在赋值符号右边的东西
 *
 * 复合赋值运算符
 * += -= *= /=
 */
void assignmentOperatorFunc()
{
    int a = 1;
    int b = 2;
    // b + 1 = a; // error: lvalue required as left operand of assignment

    int i1 = 1;
    int r1 = 10;
    r1 += i1;
    printf("r1 = %d\n", r1);
    int r2 = 10;
    r2 -= i1;
    printf("r2 = %d\n", r2);
    int r3 = 10;
    r3 *= i1;
    printf("r3 = %d\n", r3);
    int r4 = 10;
    r4 /= i1;
    printf("r4 = %d\n", r4);
}

/**
 * sizeof
 * 是一个运算符而不是函数
 */
void sizeofOperatorFunc()
{
    int i;
    printf("sizeof(i) = %d\n", sizeof(i)); // 4

    float f;
    printf("sizeof(f) = %d\n", sizeof(f)); // 4

    char c;
    printf("sizeof(c) = %d\n", sizeof(c)); // 1
}

int main()
{
    arithmeticOperatorFunc();

    relationalOperatorFunc();

    logicalOperatorFunc();

    assignmentOperatorFunc();

    sizeofOperatorFunc();

    return 0;
}
