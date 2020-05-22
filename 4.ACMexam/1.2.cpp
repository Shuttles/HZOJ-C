/*************************************************************************
	> File Name: 1.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/22 20:12:15 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 3000

int stu[MAX_N + 5][MAX_N + 5], les[MAX_N + 5][MAX_N + 5];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, max_s = 0, max_l = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int  a, b;
            cin >> a >> b;
            stu[a][b] = 1;
            les[b][a] = 1;
            max_s = max(max_s, a);
            max_l = max(max_l, b);
        }
        /*处理第一组输出*/
        for (int i = 1; i <= max_s; i++) {
            int flag = 1;
            for (int j = 1; j <= max_l; j++) {
                if (!stu[i][j]) continue;
                if (flag) {
                    printf("S %d", i);
                    flag = 0;
                }
                printf(" %d", j);
            }
            if (!flag) printf("\n");
        }

        /*处理第二组输出*/
        for (int i = 1; i <= max_l; i++) {
            int flag = 1;
            for (int j = 1; j <= max_s; j++) {
                if (!les[i][j]) continue;
                if (flag) {
                    printf("L %d", i);
                    flag = 0;
                }
                printf(" %d", j);
            }
            if (!flag) printf("\n");
        }

        memset(stu, 0, sizeof(stu));
        memset(les, 0, sizeof(les));
    }

    return 0;
}
