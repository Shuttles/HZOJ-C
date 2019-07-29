/*************************************************************************
	> File Name: 119.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 22时28分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
int days[13] = {0,
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

int Days(int y, int m) {
    return days[m] + (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)));
}

void prev_day(int &y, int &m, int &d) {
    d --;
    if (d == 0) {
        m --;
        if (m == 0) {
            y --;
            m = 12;
        }
        d = Days(y, m);
    }
}

void next_day(int &y, int &m, int &d) {
    d++;
    if (d > Days(y, m)) {
        m++;
        if (m == 13) {
            y++;
            m = 1;
        }
        d = 1;
    }
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    prev_day(y, m, d);
    cout << y << " " << m << " " << d << endl;
    next_day(y, m, d);
    next_day(y, m, d);
    cout << y << " " << m << " " << d << endl;
    return 0;
}
