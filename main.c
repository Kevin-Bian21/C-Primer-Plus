//
// Created by 14672 on 2022/7/16.
//

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
