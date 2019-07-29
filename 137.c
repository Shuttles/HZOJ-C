/*************************************************************************
	> File Name: 137.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 09时59分29秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char x = 'A';
    int i, j;
    for (i = n; i > 0; i--) {
        for (j = i; j > 0; j--) {
            printf("%c", x++);
            j == 1 && printf("\n");
        }
    }
    return 0;
}
