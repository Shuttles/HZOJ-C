/*************************************************************************
	> File Name: 49.多重背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 17:38:55 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define max_v 100000


#define MIN(a, b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a < _b ? _a : _b;\
})

int main() {
    int n, V;
    cin >> V >> n;

    int f[max_v + 5] = {0};

    int v, w, s;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int l = 1; s >  0; s -= l, l *= 2) {
            l = MIN(l, s);
            for (int j = V; j >= l * v; j--) {
                f[j] = max(f[j], f[j - l * v] + l * w);
            }
        }
    }
    cout << f[V] << endl;
    return 0;
}
