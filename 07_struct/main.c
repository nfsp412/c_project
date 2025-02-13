#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义1
struct Student
{
    int id;
    char name[20];
    char gender;
};

// 定义2
struct Teacher
{
    int tid;
    char code;
} t1;

// 定义3 匿名形式
struct
{
    int id;
} ss2;

// 定义4 typedef 最常用数据结构中
typedef struct Node
{
    int number;
} LNode, *LinkList;

// 定义5
typedef struct
{
    int number;
} n1;

/**
 * 定义结构体
 */
void func1()
{
    struct Student s1;
    t1.tid = 1;
    ss2.id = 1;
    LNode L;
    struct n1;
    // 定义3 匿名形式
    struct
    {
        int id;
    } ss3;
}

/**
 * 声明初始化结构体
 */
void func2()
{
    // 声明1
    struct Student s1;
    s1.id = 1;
    s1.gender = 'M';
    strcpy(s1.name, "Sp");
    printf("s1 id = %d,name = %s,gender = %c\n", s1.id, s1.name, s1.gender);

    // 备注,下面这样是错误的
    //  struct Student ss1;
    //  ss1 = {1, 'M', "Sp"};

    // 声明2
    struct Student s2 = {2, "Ls", 'F'};
    printf("s2 id = %d,name = %s,gender = %c\n", s2.id, s2.name, s2.gender);

    // 声明3
    struct Student s3 = {.id = 3, .name = "Ww", .gender = 'M'};
    printf("s3 id = %d,name = %s,gender = %c\n", s3.id, s3.name, s3.gender);

    // 声明4 使用别名进行赋值
    t1.tid = 1;
    t1.code = 'A';
    printf("t1 tid = %d,code = %c\n", t1.tid, t1.code);

    // 声明5 匿名结构体
    // 根据变量的作用域,ss2全局变量,ss4当前大括号内局部变量,所以能调用和赋值,ss3是其他函数的,所以无法调用,这是显然的
    struct
    {
        int id;
    } ss4 = {.id = 1};
    printf("%d\n", ss4.id);
    ss4.id = 2;
    printf("%d\n", ss4.id);

    // 声明6 typedef
    LNode L = {.number = 10086};
    printf("%d\n", L.number);
    L.number = 10010;
    printf("%d\n", L.number);

    // 声明7
}

/**
 * scanf输入赋值
 */
void func3()
{
    struct Student s1;
    scanf("%d", &s1.id);
    char c;
    scanf("%c", &c);

    scanf("%s", &s1.name);
    scanf("%c", &c);

    scanf("%c", &s1.gender);
    scanf("%c", &c);

    printf("scanf s1 %d %s %c", s1.id, s1.name, s1.gender);
}

struct S1
{
    double score; // 8字节
    int height;   // 4字节
    short age;    // 2字节
};

struct S2
{
    int height; // 4字节
    short age;  // 2字节
    char sex;   // 1字节
};

/**
 * 结构体的大小
 */
void func4()
{
    struct S1 s1 = {1.1, 1, 1};
    struct S2 s2 = {1, 1, 'a'};
    printf("s1 size %d\n", sizeof(s1)); // 16
    printf("s2 size %d\n", sizeof(s2)); // 8
}

/**
 * 结构体数组,指的是数组中存储的是结构体数据
 */
void func5()
{
    // -> 操作符 结构体数组中
    struct Student s[3] = {{101, "zs", 'f'}, {102, "ls", 'm'}, {103, "ww", 'f'}};
    printf("%s\n", s[0].name);     // zs
    printf("%s\n", (s + 1)->name); // ls
}

/**
 * 结构体指针
 */
void func6()
{
    struct Student s = {101, "zs", 'f'};
    struct Student *p;
    p = &s;
    printf("%d\n", (*p).id); // 因为.的优先级高于*,所以要加括号
    printf("%d\n", p->id);

    // 结构体数组和结构体指针
    struct Student s1[3] = {{101, "zs", 'f'}, {102, "ls", 'm'}, {103, "ww", 'f'}};
    struct Student *p2;
    p2 = s1;
    printf("p2 %d\n", p2->id);
    printf("p2 %d\n", (p2 + 1)->id);

    // 使用malloc动态的创建
    struct Student *p1;
    p1 = (struct Student *)malloc(sizeof(struct Student));
    p1->id = 1;
    printf("%d\n", p1->id);
}

typedef int Integer;

/**
 * 使用typedef
 */
void func7()
{
    // 如下 代替原本的struct LNode L
    LNode L;
    L.number = 100;
    // Node L;//这样反而是不对的

    // typedef
    Integer i1 = 1;
    printf("%d\n", i1); // 1

    // 结构体指针
    LinkList list;
    list = &L;                    // 这里注意要使用&取址,因为结构体是传值的,和数组不同
    printf("%d\n", list->number); // 100
}

void func8(int *p)
{
    *p = *p + 1;
}

void func9(int **p, int *q)
{
    *p = q;
}

int main()
{
    // 定义方法
    // func1();

    // 声明方法
    // func2();

    // scanf输入
    // func3();

    // 结构体大小
    // func4();

    // 结构体数组
    // func5();

    // 结构体指针
    // func6();

    // typedef
    // func7();

    // 修改整数类型变量的值
    int num = 10;
    printf("before num = %d\n", num);
    func8(&num);
    printf("after num = %d\n", num);

    // 修改指针
    int *p = NULL;
    int i = 10;
    int *q = &i;
    // 将p修改为q指向的地址
    func9(&p, q);
    printf("%d\n", *p); // 10
}
