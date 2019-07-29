/*************************************************************************
	> File Name: 139.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 10时16分43秒
 ************************************************************************/

#include<stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int i, j, k;
    if (n == 1) printf("AA\n");
    else {
        for (i = 1; i < n; i++) {printf(" ");}
        printf("AA\n");
        for (i = 2; i <=  n; i++) {
            if (i != n) 
            {for (k = 1; k <= n - i; k++) {printf(" ");}}
            for (j = 1; j <= 2 * i; j++ ){
                printf("A");
                j == 2 * i && printf("\n");
            }
        } 
        for (i = n - 1; i >= 2; i--) {
            for (k = 1; k <= n - i; k++) {printf(" ");}
            for (j = 1; j <= 2 * i; j++) {
                printf("A");
                j == 2 * i && printf("\n");
            }
        }
        for (i = 1; i < n; i++) {printf(" ");}
        printf("AA\n");
    }

    return 0;
}


//光哥写的代码
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0, I = 2 * n -1; i < I; i++) {
        //首先输出空格
        for (int j = 0, J = abs(n - 1 - i); j < J; j++) {
            cout << " ";
        }
        //接着输出每行的Ａ，注意规律
        for (int j = 0, J = 2 * n - 2 * abs(n - 1 - i); j < J; j++) {
            cout << 'A';
        }
        cout << endl;
    }

    return 0;
}
