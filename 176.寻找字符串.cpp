/*************************************************************************
	> File Name: 176.寻找字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/ 8 20:03:16 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 1000

char a[MAX_N + 5], b[MAX_N + 6];

int main() {
    int ans = 0;
    scanf("%[^\n]s", a);
    getchar();
    scanf("%s", b);

    int len_a = strlen(a);
    int len_b = strlen(b);

    for (int i = 0; i < len_a - len_b + 1; i++) {
        int flag = 1;
        for (int j = 0; j < len_b; j++) {
            if (a[i + j] - b[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) ans += 1;
    }
    cout << ans << endl;
    return 0;
}
