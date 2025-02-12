#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "func.h"

/**
 * 该函数实现两个整数相加
 * @param num1
 * @param num2
 * @return num1 + num2
 */
int sum(int num1, int num2)
{
    return num1 + num2;
}

/**
 * 函数形参在函数调用的时候才会分配内存空间
 * 形参相当于局部变量
 * 局部变量也叫做内部变量
 */
void f1(int a[][3], int n)
{
}

void exitFunc()
{
    printf(">>>atexit\n");
}

// 函数原型
int sub(int num1, int num2);

void argsTransformFunc();

void variableArrayDefine();

void sumArray(int n, int a[n]);

void variableArgumentsFunction(int cnt, ...);

/**
 * 指针函数,返回指针
 */
char *maxStringLength(char *str1, char *str2)
{
    printf(">>>maxStringLength\n");
    if (strlen(str1) >= strlen(str2))
    {
        return str1;
    }
    else
    {
        return str2;
    }
}

/**
 * 返回局部变量的地址,使用static修饰
 */
int *staticFunction()
{
    static int n = 100; // static关键字的使用
    return &n;
}

/**
 * static关键字
 */
void staticDemo()
{
    printf(">>>staticDemo\n");
    int *res = staticFunction();
    printf("%p\n", &res); // 0061FECC
    printf("%d\n", *res); // 100
}

void printfCustom(int a)
{
    printf("%d\n", a);
}

/**
 * 函数指针,指的是将函数代码的内存首地址赋值给一个指针,即指向函数的指针
 */
void functionPointer()
{
    printf(">>>functionPointer\n");
    // 直接调用函数
    printfCustom(100);
    // 通过函数指针调用函数
    void (*printfPointer)(int a) = printfCustom; // 写printfCustom和&printfCustom是一样的,函数名本身就是指向函数代码的指针
    printfPointer(100);
}

void initArray(int *arr, int arrLen, int (*f)())
{
    for (int i = 0; i < arrLen; i++)
    {
        arr[i] = (*f)();
    }
}

/**
 * 回调函数
 * 当函数a的入口地址(使用函数指针存储该地址),作为参数传递到函数b中,即函数b称之为回调函数
 */
void callbackFunction()
{
    printf(">>>callbackFunction\n");
    int arrLength = 3;
    int arr[arrLength];
    int (*getRand)() = rand; // 将函数指针作为参数3传递到其他函数中
    initArray(arr, arrLength, getRand);
    for (int i = 0; i < arrLength; i++)
    {
        printf("%d\n", arr[i]);
    }
}

/**
 * 内部函数,使用static关键字修饰的函数定义,只在本文件内使用
 */
static void innerFunction()
{
    printf(">>>inner Function\n");
}

/**
 * 外部函数,使用extern关键字修饰的函数定义,能在整个源程序生效,不写关键字默认都是外部函数
 */
extern void outerFunction()
{
    printf(">>>outer Function\n");
}

/**
 * c11去除了gets
 */
void func1()
{
    int i;
    scanf("%d", &i);

    char c;
    scanf("%c", &c); // 这里把上面输入整数类型最后的\n读取掉

    char *p = (char *)malloc(i);

    // gets(p);
    fgets(p, i, stdin); // 如果不支持gets,则使用fgets,fgets更安全,保证不越界

    puts(p);
}

int A = 10; // 全局变量存储在数据段,也叫外部变量

void printA(int A)
{
    // 局部变量在栈空间
    printf("... %d\n", A); // 重名了,使用就近原则
}

int main(int argc, char *argv[])
{
    // fgets
    //  func1();

    // 头文件中函数的调用
    //  int i = 10;
    //  print1(i);

    // 递归调用

    // 全局变量
    // int a = 1;
    // printA(a);

    // // 函数的定义和使用
    // int res = sum(1, 2);
    // printf("result is %d\n", res);

    // // 函数的形参
    // int a[][3] = {0};
    // int n = 1;
    // f1(a, n);

    // /**
    //  * main函数
    //  * 形参argc，全称是argument count，表示传给程序的参数个数，其值至少是1；
    //  * argv，全称是argument value，argv[] 则是指向字符串的指针数组
    //  */
    // printf("argc = %d\n", argc); // 3
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("%s\n", argv[i]); // D:\project\build\main.exe --help help info
    // }

    // // exit退出
    // //  atexit(exitFunc);

    // // 函数原型
    // int res1 = sub(1, 2);
    // printf("res1 is %d\n", res1);

    // // 参数传递
    // argsTransformFunc();

    // // 变长数组的定义
    // variableArrayDefine();

    // // 可变参数演示
    // variableArgumentsFunction(3, 10, 20, 30);

    // // 指针函数,指的是返回值是一个指针
    // char *str1 = "hello";
    // char *str2 = "hi";
    // char *resultString = maxStringLength(str1, str2);
    // printf("%s\n", resultString); // hello

    // // static关键字
    // staticDemo();

    // // 函数指针,指的是将函数代码的内存首地址赋值给一个指针,即指向函数的指针
    // functionPointer();

    // // 回调函数
    // callbackFunction();

    // // 内部函数,使用static关键字修饰的函数定义,只在本文件内使用
    // innerFunction();

    // // 外部函数,使用extern关键字修饰的函数定义,能在整个源程序生效,不写关键字默认都是外部函数
    // outerFunction();

    return 0;
}

int sub(int num1, int num2)
{
    return num1 - num2;
}

/**
 * 参数传递
 */
void argsTransformFunc()
{
    printf(">>>args transform demo\n");

    // 数据值传递: 基本数据类型存储的数据值
    int a = 10;
    printf("a = %d\n", a); // 10
    int b = a;
    b = 20;
    printf("a = %d\n", a); // 10

    // 地址值传递: 数组的地址值; 指针保存的地址值
    int a1[] = {1, 2, 3};
    printf("a1[0] = %d\n", a1[0]); // 1
    int *b1 = a1;
    b1[0] = 10;
    printf("a1[0] = %d\n", a1[0]); // 10

    int a2 = 3;
    int *b2 = &a2;
    printf("a2 = %d\n", *b2); // 3
    int *b3 = b2;
    *b3 = 13;
    printf("a2 = %d\n", *b2); // 13
}

/**
 * 变长数组的定义
 */
void variableArrayDefine()
{
    printf(">>>variableArrayDefine\n");
    int a[3] = {1, 2, 3};
    sumArray(3, a);
}

/**
 * 变长数组作为形参时,应该写在数组长度形参的后面
 * @param n 代表数组的长度
 * @param a[n] 代表一个变长数组,长度是n
 */
void sumArray(int n, int a[n])
{
    printf("sumArray\n");
}

/**
 * 可变参数演示
 */
void variableArgumentsFunction(int cnt, ...)
{
    printf(">>>variableArgumentsFunction\n");
    va_list args;        // 定义变量存储可变参数
    va_start(args, cnt); // 初始化可变参数
    double sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        int tmp = va_arg(args, int);
        sum += tmp;
    }
    va_end(args);
    printf("%f\n", sum);
}
