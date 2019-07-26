/*************************************************************************
	> File Name: 131.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时08分37秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int x;
    scanf("%d", &n);
    int min, max;
    min = 10001;
    max = 0;
    while (n--) {
        scanf("%d", &x);
        if (x < min) min = x;
        if (x > max) max = x;
    }
    printf("%d\n", max - min);
    return 0;
}
