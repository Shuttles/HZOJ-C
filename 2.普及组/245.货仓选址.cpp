/*************************************************************************
	> File Name: 245.货仓选址.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  5/25 08:37:22 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    int ind = (n + 1) >> 1;/*取中间位置*/
    int A = arr[ind];
    for (int i = 1; i <= n; i++) ans += abs(A - arr[i]);
    cout << ans << endl;
    return 0;
}
