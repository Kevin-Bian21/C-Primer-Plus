//
// Created by 边文凯 on 2021/12/27.
//
#include <stdio.h>

int fun(int a, int b);

//gcc (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0
int main() {
    char* p = "Hello World";
    printf("%s\n", p);
    printf("%c\n", *p);
    printf("%p\n", p);
    printf("%p\n", &(*p));
    printf("%c\n", *&(*p));
    printf("%c\n", *&(*(++p)));
    printf("%c\n", *(++p));


    short a = 1;
    printf("%d\n", a);


    int b = 2;
    printf("%d\n", *&b);

    long int c = 3;
    printf("%ld\n", *(&c));

    float d = 4;
    printf("%f\n", d);

    double e = 5;
    printf("%lf\n",e);  // %f 和 %lf 默认保留六位小数，不足六位以 0 补齐，超过六位按四舍五入截断

    long long int f = 6;
    printf("%lld\n",f);

    printf("char所占字节：%llu\n", sizeof(*p));
    printf("short所占字节：%llu\n", sizeof(a));
    printf("int所占字节：%llu\n", sizeof(b));
    printf("long所占字节：%llu\n", sizeof(c));
    printf("float所占字节：%llu\n", sizeof(d));
    printf("double所占字节：%llu\n", sizeof(e));
    printf("long long 所占字节：%llu\n", sizeof(f));

    printf("H的ASCII码：%d\n", *p);
    printf("%d\n",fun(*p, a));


    // 函数指针 ：类型 （*指针变量名）（参数列表);
    int (*pFunc1)() = fun;  //pFunc 是一个指针，指向一个函数
    printf("%d\n", pFunc1(1, 2));

    int (*pFunc2)(int, int) = fun;
    printf("%d\n", pFunc2(3, 4));


    //不带括号和变量列表的函数名，直接表示函数的地址
    printf("%p\n", pFunc1);
    printf("%p\n", pFunc2);
    printf("%p\n", fun);



    int m = 10;
    int* n = &m;
    printf("%d\n", *n);


    //数组
    int arr[] = {1, 3, 5, 7, 9};
    printf("%p\n", arr); //数组名是数组的首地址
    printf("%d\n", *arr);
    printf("%d\n", *(arr + 1)); //数组首地址为arr，是固定的，因此不能使用 ++ 给arr重新赋值

    int* pArr = arr;
    printf("%p\n", pArr);
    printf("%d\n", *(++pArr));
    printf("%d\n", *&(*(++pArr)));

    char aaa = 'a';
    char bbb = 'A';
    printf("%d",bbb - aaa);

    return 0;
}

int fun(int a, int b){
    return a + b;
}

/*
Hello World
H
0000000000405000
0000000000405000
H
e
l
1
2
3
4.000000
5.000000
6
char所占字节：1
short所占字节：2
int所占字节：4
long所占字节：4
float所占字节：4
double所占字节：8
long long 所占字节：8
H的ASCII码：108
109
3
7
00000000004018C1
00000000004018C1
00000000004018C1
10
000000000061FDC0
1
3
000000000061FDC0
3
5

 */