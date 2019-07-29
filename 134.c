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
            flag &&  printf(" ");
            printf("%d", i);
            flag = 1;
        } 
    
     }*/
//如何找到一个大于等于ａ的第一个被１１整除的数？？
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = ((a - 1) / 11 + 1) * 11, j = 0; i <= b; i += 11, j++) {
        j && cout << " ";
        cout << i;
    }
    return 0;
}
