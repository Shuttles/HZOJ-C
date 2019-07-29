/*************************************************************************
	> File Name: 140.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 11时54分44秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int i, j, k;
    scanf("%d", &n);
    char x = 'B';
    if (!(n - 1)) printf("A\n");
    else {
        for (i = 1; i <= n - 1; i++) {printf(" ");}
        printf("A\n");
        
        for (i = 2; i <= n; i++) {
            for (k = 1; k <= n - i; k++) {printf(" ");}
            for (j = 1; j <= 2 * i - 1; j++) {
                printf("%c", x);
                j == 2 * i - 1 && i != n && x++ && printf("\n");
                j == 2 * i - 1 && i == n && x-- && printf("\n"); 
            } 
         }
        
        for (i = n - 1; i > 1; i--) {
            for (k = 1; k <= n - i; k++) {printf(" ");}
            for (j = 1; j <= 2 * i - 1; j++) {
                printf("%c", x);
                j == 2 * i - 1 && (int)x -- && printf("\n"); 
            }
        }

        for (i = 1; i <= n - 1; i++) {printf(" ");}
        printf("A\n");
    }
    return 0;
}
//光哥的代码如下
#include <iostream>
#include <stdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0, I = 2 * n - 1; i < I; i++) {
        //首先输出每行的空格
        for (int j = 0, J = abs(n - 1 - i); j < J; j++) {
            cout << " ";
        }
        //接着输出字符
        char ch = 'A' + n - 1 - abs(n - 1 - i);
        for (int j = 0, J = 2 * n - 1 - 2 * (n - 1 - i); j < J; j++) {
            cout << ch;
        }

        cout << endl;
    }

    return 0;
}
