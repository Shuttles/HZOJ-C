/*************************************************************************
	> File Name: 138.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 10时07分16秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int i, j;
    for (i = n; i > 0; i--) {
        for (j = 1; j <= 2 * n; j++) {
            printf("A");
            j == 2 * n && printf("\n");
        }
        n--;
    }
    return 0;
}

//光哥写的代码经我改良之后
#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, J = 2 + 2 * abs(n - i); j <= J; j++) {
            cout << 'A';
        }
        cout << endl;//每输出完一行要换行
    }
    return 0;
}
