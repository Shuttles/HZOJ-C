/*************************************************************************
	> File Name: 48.完全背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 17:05:24 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;




int main() {
    #define max_v 10000
    int f[max_v + 5] = {0};//直接采用优化过的一维形式
    int V, n;
    cin >> n >> V;

    int v, w;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = v; j <= V; j++) {
            f[j] = max(f[j], f[j - v] + w);
        }
    }

    printf("%d\n", f[V]);
    return 0;
}
