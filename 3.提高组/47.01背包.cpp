/*************************************************************************
	> File Name: 01背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 16:43:12 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_V 10000

int f[MAX_N + 5][MAX_V + 5] = {0};


int main() {
    int V, n;
    cin >> V >> n;
    
    int v, w;

    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if (j < v) continue;
            f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
        }
    }

    cout << f[n][V] << endl;
    return 0;
}
