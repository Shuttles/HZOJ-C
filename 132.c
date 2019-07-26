/*************************************************************************
	> File Name: 132.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时15分01秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int x;
    long long ji = 1;
    while (n--) {
        scanf("%d", &x);
        ji *= x;
    }
    printf("%lld\n", ji);
    return 0;
}
