/*************************************************************************
	> File Name: 195.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月22日 星期四 09时56分15秒
 ************************************************************************/

#include <iostream>
#define max_n 100000
using namespace std;

int arr[max_n + 5];
int n;
int binary_search(int *arr, int l, int r, int x);

int main() {
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    int flag = 0;
    while (m--) {
        int temp;
        scanf("%d", &temp);
        flag && printf(" ");
        printf("%d", arr[binary_search(arr, 1, n, temp)]);
        flag = 1;
    }
    return 0;
}

int binary_search(int *arr, int x) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (arr[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}
