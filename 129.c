/*************************************************************************
	> File Name: 129.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 19时58分37秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int x, min = 10001;
    while (n--) {
        scanf("%d", &x);
        if (x < min) min = x;
    }
    printf("%d\n", min);

    return 0;
}
