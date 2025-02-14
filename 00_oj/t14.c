/**
 * Description

输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出


Input

学号，姓名，性别，例如输入 101 xiongda m


Output

输出和输入的内容一致，如果输入的是101 xiongda m，那么输出也是101 xiongda m


Sample Input 1

101 xiongda m
Sample Output 1

101 xiongda m
 */

#include <stdio.h>

typedef struct Student
{
    int number;
    char username[20];
    char gender;
} Student;

int main()
{
    Student s1;
    scanf("%d%s %c", &(s1.number), s1.username, &(s1.gender));

    printf("%d %s %c\n", s1.number, s1.username, s1.gender);

    return 0;
}
