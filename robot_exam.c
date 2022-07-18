//
// Created by 14672 on 2022/7/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_target();
struct test {
    char array[10];
    char *name;
    int x;
    int y;
    long timestamp;
};

char * func() {
    char p[] = "software";
    char *ch = &p[0];
    return ch;
}

int main() {
    printf("%d\n", sizeof(struct test));  //40
    int array[] = {0, 5, 6, 7, 9};
    int len = sizeof(array) / sizeof(array[0]);
    printf("%d\n",find_target(array, len, 9) );

    char *str = NULL;
    printf("%s\n", str);
    return 0;
}

int find_target(int array[], int len, int x) {
    int left = 0;
    int right = len;
    printf("%d\n",right );
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] < x) {
            left = mid + 1;
        }else if (array[mid] > x) {
            right  = mid -1;
        } else {
            return mid;
        }
    }
    return -1;
}
