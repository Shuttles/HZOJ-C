/*************************************************************************
	> File Name: 547.最长公共子序列1.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 11:57:44 2020
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX_N 5000

#define MAX(a, b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
})

int f[MAX_N + 5][MAX_N + 5];
string str1, str2;

int lengthOfLCS(char *str1, char *str2, int len1, int len2) {
    int f[MAX_N + 5][MAX_N + 5] = {0};
    //if (str1[0] == str2[0]) f[0][0] = 1;
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (str1[i] == str2[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[len1 - 1][len2 - 1];
}

int main() {
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
    for (int i = 1; i < str1.size(); i++) {
        for (int j = 1; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[str1.size() - 1][str2.size() - 1] << endl;
    return 0;
}
