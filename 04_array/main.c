#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

/**
 * define array
 */
void defineArray()
{
    printf(">>>defineArray\n");
    int n;
    scanf("%d", &n);
    int a[n]; // 最新标准下是可以的,但是最好不要这样书写,因为复试时可能标准陈旧
    printf("a %d\n", sizeof(a));

    int a1[3];
    printf("a1 %d\n", sizeof(a1));

    int a2[NUM];
    printf("a2 %d\n", sizeof(a2));

    int a3[3] = {1, 2, 3};
    printf("a3 %d\n", sizeof(a3));

    int a4[] = {1, 2, 3}; // auto 可以不指定数组长度,因为元素个数已经是确定的
    printf("a4 %d\n", sizeof(a4));

    int a5[10] = {1, 2, 3};        // auto init 0 只给部分元素赋值,其余默认0
    printf("a5 %d\n", sizeof(a5)); // 40

    int a6[3] = {0};               // auto init 0 初始化0数组的方法
    printf("a6 %d\n", sizeof(a6)); // 12

    int a7[10] = {[1] = 10, [5] = 50, [3] = 30}; // define with index
    printf("a7 %d\n", sizeof(a7));               // 40

    int a8[10] = {1, [3] = 3};     // mixed define
    printf("a8 %d\n", sizeof(a8)); // 40

    int a9[] = {[2] = 6, [9] = 11};
    printf("a9 length is %zd\n", sizeof(a9) / sizeof(a9[0])); // 10 because [9] + 1
}

/**
 * array's index
 * 赋值和取值
 */
void arrayIndex()
{
    printf(">>>arrayIndex\n");
    int a1[5];
    int a2[5];
    a1[0] = 1;
    a2[1] = 2;
    int i1 = a1[0];
    printf("%d\n", i1); // 1
    int i2 = a2[1];
    printf("%d\n", i2); // 2
}

/**
 * sizeof , return type is size_t
 */
void sizeofFunc()
{
    printf(">>>sizeofFunc\n");
    int a1[10];
    printf("%zd\n", sizeof(a1));    // 40
    printf("%zd\n", sizeof(a1[0])); // 4
    char a2[10];
    printf("%zd\n", sizeof(a2));    // 10
    printf("%zd\n", sizeof(a2[0])); // 1
}

/**
 * get array's length
 */
void getLength()
{
    printf(">>>getLength\n");
    int arr[3];
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    printf("%zd\n", arrLength); // 3
}

/**
 * foreach
 * 遍历数组
 */
void foreachArray()
{
    printf(">>>foreachArray\n");
    int arr[3];
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        arr[i] = i + 1;
        printf("%d\n", arr[i]); // 1 2 3
    }
}

/**
 * variable array
 * 可变数组,指的是数组长度在运行时才能确定
 */
void variableArray()
{
    printf(">>>variableArray\n");
    int variableLength = 1;
    int variableArray[variableLength + 1];
    printf("array's length is %zd\n", sizeof(variableArray) / sizeof(variableArray[0])); // 2
    for (size_t i = 0; i < sizeof(variableArray) / sizeof(variableArray[0]); i++)
    {
        variableArray[i] = i + 1;
        printf("%d\n", variableArray[i]);
    }

    // 使用malloc创建
    printf(">>>usage of malloc\n");
    int length = 3;
    int *arr = (int *)malloc(length * sizeof(int)); //<stdlib.h>
    for (int i = 0; i < length; i++)
    {
        arr[i] = i + 10;
        printf("%d\n", arr[i]);
    }
    free(arr);
}

void arrayMax()
{
    int arr[] = {1, 2, 3};
    // max
    int max = arr[0];
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("max is %d\n", max);
}

void arrayMin()
{
    int arr[] = {1, 2, 3};
    // min
    int min = arr[0];
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("min is %d\n", min);
}

void arraySum()
{
    int arr[] = {1, 2, 3};
    // sum
    int sum = 0;
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        sum += arr[i];
    }
    printf("sum is %d\n", sum);
}

void arrayCopy()
{
    printf(">>>copy array\n");
    int a[] = {1,
               2,
               3};
    int length = sizeof(a) / sizeof(a[0]);
    // 1 foreach
    int b[length];
    for (int i = 0; i < length; i++)
    {
        b[i] = a[i];
        printf("%d\n", b[i]);
    }

    // 2 memcpy <string.h>
    printf(">>>memcpy\n");
    int c[length];
    memcpy(c, a, length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", c[i]);
    }
}

void arrayReverse()
{
    int a[] = {1, 2, 3};
    int length = sizeof(a) / sizeof(a[0]);
    printf("before exchange\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", a[i]);
    }
    for (int i = 0; i < length / 2; i++)
    {
        // exchange
        int temp = a[i];
        a[i] = a[length - 1 - i];
        a[length - 1 - i] = temp;
    }
    printf("after exchange\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", a[i]);
    }
}

/**
 * define string with char array
 * 定义字符串
 */
void makeString()
{
    printf(">>>makeString\n");
    char s1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", s1);
    char s2[] = {"hello"};
    printf("%s\n", s2);
    char s3[] = "hello";
    printf("%s\n", s3);

    // 乱码问题
    // char s4[5] = "hello"; // 输出了乱码或者多余的内容
    // char s4[5] = {'h', 'e', 'l', 'l', 'o'};// 输出了乱码或者多余的内容
    // printf("s4 = %s\n", s4);

    // 使用scanf读取字符串
    // 和整数类型一致,会忽略回车换行
    // 无需取地址&,因为本身数组名就存储了首地址
    char s5[1];
    scanf("%s", s5);
    printf("s5 = %s\n", s5);
}

/**
 * string's length
 */
void stringLength()
{
    printf(">>>string's length\n");
    char str1[10] = "hello";
    int length = sizeof(str1) / sizeof(char);
    for (size_t i = 0; i < length; i++)
    {
        printf("%c,", str1[i]); // 多余位置填充\0,打印出来是空的
    }
    printf("\n");

    // 求字符串不包含\0的实际长度,不能使用sizeof(str1) / sizeof(char)
    // 而应该使用strlen方法,<string.h>
    printf("str1 length is %d\n", strlen(str1)); // 5

    char s1[] = "hello";
    char s2[10];
    strcpy(s2, s1);          // 后者赋值给前者
    printf("s2 = %s\n", s2); // hello

    strcat(s2, s1);          // 后者拼接到前者中
    printf("s2 = %s\n", s2); // hellohello

    int res = strcmp(s1, s2);
    printf("%d\n", res); // 前者大于后者,返回1,否则返回-1,相等返回0 实际上是按照位数进行字符的ASCII值比较,
}

/**
 * define multi array
 * 定义二维数组
 */
void defineMultiArray()
{
    printf(">>>defineMultiArray\n");
    int a1[3][3];
    int a2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    // 下面是错误的
    //  int a3[][] = {
    //      {1, 2, 3},
    //      {4, 5, 6},
    //      {7, 8, 9}};
    int a3[3][3] = {[0][0] = 1, 2};
    printf("%d\n", a3[0][1]); // a3[0][1]位置就是2
    int a4[3][3] = {1, 2, 3};
    printf("%d\n", a4[0][2]); // a4[0][2]位置就是3
    int a5[][3] = {1};        // 第一维的长度可以省略,但是第二维必须指定长度
}

void multiArraySum()
{
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    printf("%d\n", sum);
}

void multiArrayMax()
{
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    int max = arr[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
    }
    printf("%d\n", max);
}

void matrixExchange()
{
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    int arr1[3][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr1[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\n", arr1[i][j]);
        }
    }
}

/**
 * foreach multi array
 */
void foreachMultiArray()
{
    printf(">>>foreachMultiArray\n");
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\n", arr[i][j]);
        }
    }

    // 字符串数组的遍历
    char strArray[][10] = {
        "hello",
        "hi",
        "nihao"};
    for (int i = 0; i < sizeof(strArray) / sizeof(strArray[0]); i++)
    {
        printf("%s\n", strArray[i]);
    }
}

/**
 * array address
 * 数组地址和数组首地址
 */
void arrayAddress()
{
    printf(">>>array address\n");
    int arr[] = {1, 2, 3, 4};
    printf("%p\n", arr);      // 0061FEF0
    printf("%p\n", &arr);     // 0061FEF0
    printf("%p\n", arr + 1);  // 0061FEF4 指的是数组首个元素地址值加1,只跨越了一个元素
    printf("%p\n", &arr + 1); // 0061FF00 指的是数组地址加1,跨越了整个数组的长度
}

/**
 * multi array address
 */
void multiArrayAddress()
{
    printf(">>>multi array address\n");
    int a[3][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12}};
    printf("%d\n", a[0][0]);
    printf("%p\n", &a[0][0]);
    printf("%p\n", a[0]); // 代表a[0][0]的地址
    printf("%p\n", a);    // 代表a[0]的地址
    printf("%p\n", &a);   // 理解为a数组的地址,虽然值和a[0]地址值相同

    // 0行0列地址值
    printf("0 row 0 col address\n");
    printf("%p\n", &a[0][0]);
    printf("%p\n", a[0]);
    printf("%p\n", *a);

    //
    printf("%p\n", *(a + 1));       // 0061FEDC
    printf("%p\n", *(a + 1) + 1);   // 0061FEE0 = 0061FEDC + 4
    printf("%p\n", *((a + 1) + 1)); // 0061FEEC = 0061FEDC + 4 * 4

    // 指针变量访问二维数组
    // 假设指针变量指向首个元素,数组是连续存储的,所以指针的操作加1实际上就是加一个元素
    // int *p = &a[0][0];
    // int *p = a[0];
    int *p = *a;
    printf("%p\n", p);     // 0061FECC
    printf("%p\n", p + 1); // 0061FED0 = 0061FECC + 4

    printf("%p\n", &a[1][1]);      // 0061FEE0
    printf("%p\n", *(a + 1) + 1);  // 0061FEE0
    printf("%p\n", p + 1 * 4 + 1); // 0061FEE0
}

/**
 * 数组越界
 * 查看i j a的地址
 * debug时调试控制台输入&i即可查看
 */
void arrayCrossBorderFunc()
{
    int a[5] = {1, 2, 3, 4, 5}; // 0x61fee4
    int j = 20;                 // 0x61fefc
    int i = 10;                 // 0x61fef8
    a[5] = 6;                   // &a[5] = 0x61fef8
    a[6] = 7;
    printf("i = %d\n", i);
}

/**
 * 直接这样传递,实际上数组的长度是传递不过去的,因为传递的其实是数组首地址
 * 所以可以传递额外一个参数代表数组长度
 *
 * 但是数组元素的查询和修改是能够同步的
 */
void func1(int arr[], int length)
{
    // printf("sizeof = %d\n", sizeof(arr) / sizeof(int)); // 1

    printf("arr[0] = %d\n", arr[0]);
    printf("arr[3] = %d\n", arr[3]);

    arr[4] = 100;
}

/**
 * 模拟print打印字符串
 * 读取到\0结束,因为\0也相当于0假
 */
void func2(char s[])
{
    int i = 0;
    while (s[i])
    {
        printf("%c", s[i]);
        i++;
    }
}

/**
 * gets和puts
 * gets 遇到\n结束,读取字符串,可以有空格,将\n翻译为\0
 *
 * puts等价于printf("%s\n",c),即只能打印字符串,并且最后携带一个\n
 *
 */
void func3()
{
    char s1[1];
    gets(s1);
    printf("%s\n", s1);
    // puts(s1);
}

int main()
{
    // define array
    // defineArray();

    // 数组越界
    // arrayCrossBorderFunc();

    // array's index
    // arrayIndex();

    // sizeof , return type is size_t
    // sizeofFunc();

    // get array's length
    // getLength();

    // for in array
    // foreachArray();

    // variable array
    // variableArray();

    // methods
    // printf(">>>array's methods\n");
    // arrayMax();
    // arrayMin();
    // arraySum();
    // arrayCopy();
    // arrayReverse();

    // define string with char array
    // makeString();

    // string's length
    stringLength();

    // define multi array
    // defineMultiArray();

    // foreach multi array
    // foreachMultiArray();

    // multi array's methods
    // printf(">>>multi array's methods\n");
    // multiArraySum();
    // multiArrayMax();
    // matrixExchange();

    // array address
    // arrayAddress();

    // multi array address
    // multiArrayAddress();

    // 数组作为函数形参
    // int arr1[5] = {1, 2, 3, 4, 5};
    // func1(arr1, 5);
    // printf("arr[4] = %d\n", arr1[4]);

    // 模拟print打印字符串
    // char s1[] = "hello";
    // func2(s1);

    // gets和puts
    // func3();
}
