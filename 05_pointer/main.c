#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * define pointer
 */
void definePointer()
{
    printf(">>>definePointer\n");
    int num = 1;
    int *p1 = &num;
    int *p2;
    char str[] = "hello";
    char *p3 = str;
    short *p4 = (short *)0x1234; // 直接赋值一个地址值
    int *p5 = NULL;              // <stdio.h>  #define NULL 0

    // 指针大小,64位系统固定8字节,32位系统固定4字节
    printf("%d\n", sizeof(p5));  // 4
    printf("%d\n", sizeof(num)); // 4
}

/**
 * address & value
 * 取址和取值
 */
void addressValue()
{
    printf(">>>address & value\n");
    int num = 1;
    printf("value is %d\n", num);
    printf("address is %p\n", &num);
    int *p = &num;
    printf("address is %p\n", p);
    printf("value is %d\n", *p);

    //*和&顺序从右向左
}

/**
 * pointer calc
 * 指针运算
 */
void pointerCalc()
{
    printf(">>>pointer calc\n");
    // 加减整数
    int *p1 = (int *)0x1000;
    printf("%x\n", (p1 + 1)); // 1004

    // 遍历数组
    int arr[] = {1, 2, 3};
    int *p2 = arr;
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        // printf("%d\n", *(p2 + i)); // 数组取下标实际上也是通过指针操作的
        printf("%d\n", p2[i]); // 等价写法
    }

    // 逆向输出
    p2 = &arr[2]; // 指向最后元素地址
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(p2 - i));
    }

    // 自增自减
    int arr3[] = {1, 2, 3};
    int *p3 = arr3;
    // printf("%d\n", *(p3++));
    printf("%d\n", *(++p3)); // 2

    // 指针相减
    int arr4[3];
    int *p4 = &arr4[0];
    int *p5 = &arr4[1];
    ptrdiff_t dist = p5 - p4;     //<stddef.h>
    printf("dist is %d\n", dist); // 1
}

/**
 * null pointer
 */
void nullPointer()
{
    printf(">>>null pointer\n");
    int *p = NULL;
    if (p == NULL)
    {
        printf("p is null pointer\n");
    }
}

/**
 * define multi pointer
 * 二级指针
 */
void defineMultiPointer()
{
    printf(">>>define multi pointer\n");
    int num = 1;
    int *p = &num;
    printf("%p\n", p);  // 0061FEE8
    printf("%d\n", *p); // 1
    int **p1 = &p;
    printf("%p\n", p1);   // 0061FEE4
    printf("%p\n", *p1);  // 0061FEE8
    printf("%d\n", **p1); // 1
}

/**
 * 数组指针,指的是指针,只不过这个指针指向的是数组首地址
 */
void pointerToArray()
{
    printf(">>>pointer => array\n");
    int *p1 = NULL;
    int arr[] = {0};
    p1 = arr; // 等价的p1 = &arr[0];
    // p1 = &arr[0];
    printf("%p\n", p1);  // 0061FF18
    printf("%d\n", *p1); // 0

    // 指针访问数组元素,例如遍历数组,这种方式速度优于传统方式
    int arr2[] = {1, 2, 3};
    int *p2 = arr2;
    int length = sizeof(arr2) / sizeof(arr2[0]);
    printf("%p\n", (arr2));          // 0061FED4
    printf("%p\n", (arr2 + length)); // 0061FEE0
    // for (p2; p2 < (arr2 + length); p2++)
    // {
    //     printf("%d\n", *p2);
    // }
    // 或者
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", *(p2 + i));
    }

    // 指针的索引下标使用,实际上 p3[1] 等价于 *(p3 + 1)
    int arr3[] = {1, 2, 3};
    int *p3 = arr3;
    printf("%d\n", *(p3 + 1)); // 2
    printf("%d\n", p3[1]);     // 2
}

/**
 * 指针数组,指的是数组,只不过数组中的元素是指针变量
 */
void arrayToPointer()
{
    printf(">>>array of pointers\n");
    int a1[5];
    int *a2[5];
    //
    int a, b, c;
    a = b = c = 1;
    int *a3[] = {&a, &b, &c};
    for (int i = 0; i < 3; i++)
    {
        printf("%p\n", &a3[i]); // 数组元素的地址值
        printf("%p\n", a3[i]);  // 数组元素的值
        printf("%d\n", *a3[i]); // 数组元素的值的值
    }
}

/**
 * 字符串再次学习
 */
void stringFunc()
{
    printf(">>>string and array and pointer\n");
    // 字符串的定义方式
    char s1[] = "hello";
    char *s2 = "hello";
    // 使用指针的形式的好处是,可以更改
    s2 = "hi";

    // 字符串字面量是不可变的
    //  s1 = "hi";//不可以
    s1[0] = 'A';        // 可以,即能修改数组某个元素,但是不能直接修改字面量
    printf("%s\n", s1); // Aello

    s2 = "nihao"; // 可以
    // s2[0] = 'A';//不可以
    printf("%s\n", s2); // nihao

    // 字符串数组
    printf(">>>array of strings\n");
    char ss1[][10] = {"hello", "hi"}; // 长度10必须写,但是有点浪费空间,解决方式是使用指针数组
    char *ss2[] = {"hi", "hello", "nihao"};
    printf("%d\n", sizeof(ss2));    // 12
    printf("%d\n", sizeof(ss2[0])); // 4
    for (int i = 0; i < sizeof(ss2) / sizeof(ss2[0]); i++)
    {
        printf("%s\n", ss2[i]);
    }
}

/**
 * 指向固定长度数组的指针变量
 */
void pointerVariableArray()
{
    printf(">pointerVariableArray\n");
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};
    int(*q)[4];
    q = arr;

    printf("%p\n", q);     // 0061FEDC
    printf("%p\n", q + 1); // 0061FEEC = 0061FEDC + 4 * 4
    // 下面两个写法是等价的
    printf("%p\n", *(arr + 1) + 1); // 0061FEF0 = 0061FEDC + 4 * 4 + 4
    printf("%p\n", *(q + 1) + 1);   // 0061FEF0 = 0061FEDC + 4 * 4 + 4
}

/**
 * 形参中使用指针
 */
void func1(int *p)
{
    *p = 10;
}

void func2(int a[5])
{
    a[0] = 100;
}

void func3(int *p)
{
    // p[0] = 101;
    *p = 101;
}

/**
 * 栈是计算机系统提供的数据结构,效率更高,释放后局部变量消失
 * 堆是c/c++提供的数据结构,需要自行free释放,只有free释放才消失
 *
 */
void func4()
{
    int i;
    char *p;
    scanf("%d", &i); // 动态输入要申请的内存空间大小
    p = (char *)malloc(i);
    strcpy(p, "success");
    puts(p);
    // free(p); // 释放的必须是malloc申请时候的指针的值,不能有偏移
    // 并且由于free接受的是void指针,由于所有指针可以自动转换成void指针,所以不需要强制类型转换

    // 尝试偏移指针
    p += 1;
    // puts(p); //uccess
    free(p);
}

char *func5()
{
    char c[20] = "p1";
    puts(c);
    return c; // function returns address of local variable
}

char *func6()
{
    char *p;
    p = (char *)malloc(20);
    strcpy(p, "p2");
    puts(p);
    return p;
}

int main()
{
    // 指针,即地址;指针变量,即存储了指针(地址)的变量

    // define pointer
    // definePointer();

    // address & value
    // addressValue();

    // pointer calc
    // pointerCalc();

    // null pointer
    // nullPointer();

    // define multi pointer
    // defineMultiPointer();

    // 数组指针,指的是指针,只不过这个指针指向的是数组首地址
    // pointerToArray();

    // 指针数组,指的是数组,只不过数组中的元素是指针变量
    // arrayToPointer();

    // 字符串再次学习
    // stringFunc();

    // 指向固定长度数组的指针变量
    // pointerVariableArray();

    // 形参中使用指针
    // int i = 1;
    // printf("%d\n", i);
    // func1(&i);
    // printf("%d\n", i);

    // 数组作为形参传递,实际上就是指针操作
    // int a[5] = {0};
    // // func2(a);
    // int *p = a;
    // func3(p);
    // printf("%d\n", a[0]);

    // 动态内存分配
    // func4();

    // 栈和堆
    // char *p1;
    // char *p2;
    // p1 = func5();
    // printf("%s\n", p1); // 打印 (null)
    // p2 = func6();
    // puts(p2);
}
