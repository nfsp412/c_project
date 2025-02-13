#include <iostream>

void func1(int &n)
{
    n++;
}

void func2(int *&p, int *q)
{
    p = q;
}

int main()
{
    // 配置 includePath 避免报错
    std::cout << "Hello World" << std::endl;

    // 修改整数类型变量
    int num = 10;
    printf("before num = %d\n", num);
    func1(num);
    printf("after num = %d\n", num);

    // 修改指针
    int *p = NULL;
    int i = 10;
    int *q = &i;
    // 将p修改为q指向的地址
    func2(p, q);
    printf("%d\n", *p); // 10

    // 布尔类型
    bool a = true;
    bool b = false;
    printf("a %d b %d \n", a, b);//true 1 false 0

    return 0;
}
