//
// Created by 14672 on 2022/7/16.
//
/**
 * sizeof是C语言的内置运算符，以字节为单位给出指定类型的大小。C99
    和C11提供%zd转换说明匹配sizeof的返回类型[2]。一些不支持C99和C11的
    编译器可用%u或%lu代替%zd。
strlen()获取字符串的长度。
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int gcd(int a, int b);

void func(char *str) {
    printf("%d\n",sizeof(str));
    printf("%d\n",strlen(str));
}
typedef struct name {
    char str;
    int num;
    short x;
}name;
/**
 * strcpy()接受两个字符串指针作为参数，可以把指向源字符串的
    第2个指针声明为指针、数组名或字符串常量；而指向源字符串副本的第1个
    指针应指向一个数据对象（如，数组），且该对象有足够的空间储存源字符
    串的副本。记住，声明数组将分配储存数据的空间，而声明指针只分配储存
    一个地址的空间。
 * @return
 *
 * sprintf()函数声明在stdio.h中，而不是在string.h中。该函数和printf()类
    似，但是它是把数据写入字符串，而不是打印在显示器上。因此，该函数可
    以把多个元素组合成一个字符串。sprintf()的第1个参数是目标字符串的地
    址。其余参数和printf()相同，即格式字符串和待写入项的列表。

    这两个函数都从 s2 指向的位置拷贝 n 字节到 s1 指向的位置，而且都返
    回 s1 的值。所不同的是， memcpy()的参数带关键字restrict，即memcpy()假
    设两个内存区域之间没有重叠；而memmove()不作这样的假设，所以拷贝过
    程类似于先把所有字节拷贝到一个临时缓冲区，然后再拷贝到最终目的地。
    如果使用 memcpy()时，两区域出现重叠会怎样？其行为是未定义的，这意
    味着该函数可能正常工作，也可能失败。
 */

int main() {
    int num = 0;
    printf("%d\n", sizeof(num));
    char a[] = "123456789";
    printf("%s\n", &a[8]);
    char b[6];
    char *p = (char *) malloc(10);
    printf("%d\n", sizeof(p));
    strcpy(p, a);
    printf("%s\n", p);
    memcpy(b, a, 5);
    printf("%s\n", b);
    printf("%d\n",sizeof(a));
    printf("%d\n",strlen(a));
    func(a);
    printf("%d\n" , gcd(6,5));
    printf("%d\n",sizeof(name));
    return 0;
}

int gcd(int a, int b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
