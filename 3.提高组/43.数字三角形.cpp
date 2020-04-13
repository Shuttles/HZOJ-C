/*************************************************************************
	> File Name: 43.数字三角形.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/13 23:15:27 2020
 ************************************************************************/

#include <iostream>
#define max_n 1000
using namespace std;

int val[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5];

int dfs(int i, int j, int n) {
    if(i + 1 == n) return val[i][j];
    if(keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = max(val1, val2) + val[i][j];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, n) << endl;
    return 0;
}
