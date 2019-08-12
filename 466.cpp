/*************************************************************************
	> File Name: 466.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时31分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int is_val(int x);

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (!is_val(i)) continue;
        sum++;
    }
    printf("%d\n", sum);
    return 0;
}

int is_val(int x) {
    int temp = x, ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return temp == ans;
}
