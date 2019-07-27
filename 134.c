/*************************************************************************
	> File Name: 134.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时26分37秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int i;
    int sum = 0;
    for (i = a; i <= b; i++) {
       (sum == 0) && !(i % 11) && printf("%d", i);
       (sum != 0) && !(i % 11) && printf(" %d", i);
       !(i % 11) && sum++;
    }
    return 0;
}
/*
    int flag = 0;
    for (i = a; i <= b; i++) {
        if (!(i % 11)) {
            if (flag) {
                printf(" ");
            }
            printf("%d", i);
            flag = 1;
        } 
    
     }*/
