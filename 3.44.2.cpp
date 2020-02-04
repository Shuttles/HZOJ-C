/*************************************************************************
	> File Name: 3.44.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月17日 星期六 21时37分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 1000000
#define INF 0x7f7f7f7f
using namespace std;

int low[max_n + 5];
int arr[max_n + 5];
int binary_search(int *arr, int r, int x);

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);      
    }
    //low[0] = 1; 
    int len = 1;
    low[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        if (arr[i] < low[len]) low[binary_search(low, len, arr[i])] = arr[i];
        else if (arr[i] > low[len])low[++len] = arr[i];
    }
    printf("%d\n", len);
    return 0;
}

int binary_search(int *arr, int r, int x) {
    int l = 1, mid;
    while (l <= r) {
        mid = (r + l) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
//返回arr数组中第一个 >= x的位置
