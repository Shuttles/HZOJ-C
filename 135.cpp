/*************************************************************************
	> File Name: 135.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 10时21分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
int days[13] = {0,
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

int Days(int &y, int &m, int &d) {
    return days[m] + (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)));
}

void next_day(int &y, int &m, int &d) {
    d++;
    if (d > Days(y, m, d)) {
        m ++;
        d = 1;
        if (m > 12) {
            y++;
            m = 1;
        }
    }
    return ;
}

int main() {
    int x, y, m, d;
    cin >> x >> y >> m >> d;
    for (int i = 0; i < x; i++) {
        next_day(y, m, d);
    }
    cout << y << " " << m << " " << d << endl;
    return 0;
}
