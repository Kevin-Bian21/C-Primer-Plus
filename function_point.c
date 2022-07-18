//
// Created by 14672 on 2022/7/18.
//

#include <stdio.h>

int *fun(int a, int b) {
    int c = a + b;
    int *p;
    p = &c;
    return p;
}

int func(int a, int b) {
    return a - b;
}

int main() {
    //指针函数，函数返回类型是某个类型的指针 int *f(x, y)
    int *p = fun(1, 2);
    printf("%d\n", *p);

    //函数指针，指向函数代码首地址的指针变量 int (*f)(x, y)
    int (*pt)();
    pt = func;
    printf("%d\n", (*pt)(3, 1));



}