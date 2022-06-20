#include<iostream>
#include<stdio.h>
using namespace std;

void test(int &x)
{
    x=x+1;
}
void test2(int x)
{
    x=x+1;
}

int main()
{
    int x=1;
    printf(" 1.经过没有&的函数\n");
    test2(x);
    printf("结果为:%d\n",x);
    printf("2.经过&的函数\n");
    test(x);
    printf("结果为:%d",x);
}
/*输出结果：
1.经过没有&的函数
结果为:1
2.经过&的函数
结果为:2
*/