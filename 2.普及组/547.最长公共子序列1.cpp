/*************************************************************************
	> File Name: 547.最长公共子序列1.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 11:57:44 2020
 ************************************************************************/

#include <iostream>
#include <cstring>
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
    char X[MAX_N + 5] = {0};
    char Y[MAX_N + 5] = {0};
    scanf("%s", (X + 1));
    getchar();
    scanf("%s", (Y + 1));
    int len1, len2;
    len1 = strlen(X);
    len2 = strlen(Y);
     int f[MAX_N + 5][MAX_N + 5] = {0};
    //if (str1[0] == str2[0]) f[0][0] = 1;
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (X[i] == Y[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    printf("%d\n", f[len1 - 1][len2 - 1]);
    return 0;
}
