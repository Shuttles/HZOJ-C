/*************************************************************************
	> File Name: 113.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 21时30分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
int days[13] = {0,
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};
int main() {
    int y, m;
    cin >> y >> m;
    cout << days[m] + (m == 2 && (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) << endl;
    return 0;
}