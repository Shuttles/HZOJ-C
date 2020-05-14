/*************************************************************************
	> File Name: 503.独木舟.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/13 18:14:11 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 30000
int num[MAX_N + 5];
int ans[MAX_N + 5] = {1};

int main() {
    int w, n;
    cin >> w >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    sort(num + 1, num + 1 + n);
    
    int ans = 0;
    for (int i = n; i > 0; i--) {
        if (!num[i]) continue;
        for (int j = 1; j < i; j++) {
            if (num[j] && num[j] + num[i] <= w) {
                num[j] = 0;
                ans += 1;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
