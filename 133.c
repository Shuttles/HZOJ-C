/*************************************************************************
	> File Name: 133.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时17分53秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            printf("%d*%d=%d", i, j, i*j);
            j == n || printf("\t");
            j == n && printf("\n");
        }
    }
    return 0;
}
//底下是光哥写的程序
#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            j - i && cout << "\t";//当j != i 时输出\t
            cout << i << "*" << j << "=" << i * j;
        }
        cout << endl;//每输出一行就换行
    }
}
