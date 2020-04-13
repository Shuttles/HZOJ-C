/*************************************************************************
	> File Name: 240.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/11 18:10:18 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char ans[2200][2200];
//num数组存边长
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};

void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n- 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
}


int main() {
    func(1, 1, 7);
    int n;
    while (~scanf("%d", &n)) {
        if (n == -1) break;
        for (int i = 1; i <= num[n]; i++) {
            for (int j = 1; j <= num[n]; j++) {
                if (ans[i][j] == 'X') printf("X");
                else printf(" ");
            }
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}
