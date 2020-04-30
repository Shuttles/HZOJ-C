/*************************************************************************
	> File Name: 590.树塔狂想曲.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/29 20:45:54 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


#define MAX_N 1000

int num[MAX_N + 5][MAX_N + 5], down[MAX_N + 5][MAX_N + 5], up[MAX_N + 5][MAX_N + 5],mmax[MAX_N + 5], mmax_ind[MAX_N + 5], mmax2[MAX_N + 5];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    //从上往下
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= i; j++) {
            down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
        }
    }

    //从下往上
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
        }
    }

    for (int i = 2; i <= n; i++) {
        int ind1 = 0, ind1_max = 0, ind2_max = 0;
        for (int j = 1; j <= i; j++) {
            int temp = down[i][j] + up[i][j] - num[i][j];
            if (temp > ind1_max) {
                //最大值
                ind1_max = temp;
                ind1 = j;
            }
        }
        for (int j = 1; j <= i; j++) {
            int temp = down[i][j] + up[i][j] - num[i][j];
            if (temp > ind2_max && j - ind1) {
                //次大值
                ind2_max = temp;
            }
        }
        mmax[i] = ind1_max;
        mmax_ind[i] = ind1;
        mmax2[i] = ind2_max;
    }


    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1\n");
            continue;
        }
        if (mmax_ind[a] == b) {
            /*如果ban掉的值是最大值的点，就输出次大值*/
            printf("%d\n", mmax2[a]);//次大值
        } else {
            printf("%d\n", mmax[a]);//最大值
        }
    }
    return 0;
}
