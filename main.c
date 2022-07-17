//
// Created by 14672 on 2022/7/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int gcd(int a, int b);

void func(char *str) {
    printf("%llu\n",sizeof(str));
    printf("%llu\n",strlen(str));
}
typedef struct People {
    char *str;
    int num;
    short x;
}p;

typedef union Student {
    int num;
    char *str;
}s;

int main() {
    //初始化结构体
    struct People people = {"bwk", 22, 18};
    //初始化联合体
    union Student student = {.str = "bwk"};

    int num = 0;
    printf("%llu\n", sizeof(num));
    char a[] = "123456789";
    printf("%s\n", &a[8]);
    char b[6];
    char *p = (char *) malloc(10);
    printf("%llu\n", sizeof(p));
    strcpy(p, a);
    printf("%s\n", p);
    memcpy(b, a, 5);
    printf("%s\n", b);
    printf("%llu\n",sizeof(a));
    printf("%llu\n",strlen(a));
    func(a);
    printf("%d\n" , gcd(6,5));
    printf("%llu\n",sizeof(p));
    return 0;
}

int gcd(int a, int b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
