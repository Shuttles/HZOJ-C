/*************************************************************************
	> File Name: 588.数列.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 18:27:28 2020
 ************************************************************************/
 //纯逻辑题.....

#include<iostream>
using namespace std;

#define MAX_N 30

int ans[MAX_N + 5][10005] = {{}, {1}}, n;

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int ind = 0;
        for (int j = 0; ans[i - 1][j]; j++) {
            int x = 1;
            while (ans[i - 1][j] == ans[i - 1][j + 1]) {
                x++;
                j++;
            }
            ans[i][ind++] = x;
            ans[i][ind++] = ans[i - 1][j];
        }
    }

    for (int i = 0; ans[n][i]; i++) {
        cout << ans[n][i];
    }
    cout << endl;
    return 0;
}
