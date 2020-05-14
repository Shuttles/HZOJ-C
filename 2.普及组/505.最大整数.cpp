/*************************************************************************
	> File Name: 505.最大整数.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/13 18:57:06 2020
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int n;
string str[MAX_N + 5];

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n,  cmp);
    for (int i = 0; i < n; i++) {
        cout << str[i];
    } 
    cout << endl;
    return 0;
}
