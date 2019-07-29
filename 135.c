/*************************************************************************
	> File Name: 135.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 13时51分21秒
 ************************************************************************/

#include<stdio.h>

int day(int y, int m) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        case 2:
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 29;
        else return 28;
    }
}//tqltqltqltqltqltqltql

int main() {
    int x;
    scanf("%d", &x);
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    d += x;
    while (d > day(y, m)) {
        d -= day(y, m);
        m++;
        if (m == 13) {
            y++;
            m -= 12;
        }
    }
    printf("%d %d %d\n", y, m, d);
    return 0;
}
