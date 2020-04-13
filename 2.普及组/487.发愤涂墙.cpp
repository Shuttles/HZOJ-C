/*************************************************************************
	> File Name: 487.发愤涂墙.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/13 23:19:00 2020
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

int64_t f(int n) {
    int64_t arr[50] = {0, 2, 2};
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];        /*这个递推关系式是靠枚举出来的....orz*/
    }
    return arr[n];
}


int main() {
    int n;
    scanf("%d", &n);
    printf("%" PRId64 "\n", f(n));
    return 0;
}
