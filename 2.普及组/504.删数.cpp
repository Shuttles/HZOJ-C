/*************************************************************************
	> File Name: 504.删数.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/13 18:42:05 2020
 ************************************************************************/

#include <cstring>
#include <string>
#include<iostream>
using namespace std;

string str;
int n;

int main() {
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') flag = 1;
        if (flag) cout << str[i];
    }
    cout << endl;
    return 0;
}
