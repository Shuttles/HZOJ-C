/*************************************************************************
	> File Name: 123.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 09时31分03秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int a, b;
    int c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a >= c && b <= d) {
        printf("YES\n");
    }
    else if (c >= a && d <= b) {
        printf("YES\n");
    } 
    else printf("NO\n");
    return 0;
}

