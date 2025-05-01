#include <stdio.h>

/**
 * 表达式的结果
 */
void expressionFunc()
{
    int res = 5 > 3 && 8 < 4 - !0;
    printf("%d\n", res); // 0
}

/**
 * if else语句
 */
void ifElseFunc()
{
    int i;
    while (scanf("%d", &i))
    {
        if (i > 0)
        {
            printf("%d is bigger than 0 \n", i);
        }
        else
        {
            printf("%d is smaller than 0 \n", i);
        }
    }
}

/**
 * while循环
 */
void whileFunc()
{
    int i = 1;
    int total = 0;
    while (i <= 100)
    {
        total += i;
        i++;
    }
    printf("total = %d\n", total);
}

/**
 * for循环
 *
 */
void forFunc()
{
    int total = 0;
    for (int i = 1; i <= 100; i++)
    {
        total += i;
    }
    printf("total = %d\n", total);
}

/**
 * continue的使用
 */
void continueFunc()
{
    int total = 0;
    for (int i = 1; i < 100; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        total += i;
    }
    printf("total = %d\n", total);
}

/**
 * break语句
 */
void breakFunc()
{
    int total = 0;
    for (int i = 1; i < 100; i++)
    {
        if (total > 2000)
        {
            break;
        }

        total += i;
    }
    printf("total = %d\n", total);
}

/**
 * 循环嵌套练习
 */
void practiceFunc()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    
}

int main()
{
    expressionFunc();

    // ifElseFunc();

    whileFunc();

    forFunc();

    continueFunc();

    breakFunc();

    practiceFunc();
    return 0;
}
