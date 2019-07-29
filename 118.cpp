/*************************************************************************
	> File Name: 118.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 22时21分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

char str[][13] = {
    "rat", "ox", "tiger", "rabbit",
    "dragon", "snake", "horse", "sheep",
    "monkey", "rooster", "dog", "pig"
};//用一个数字存起来十二生肖

int main() {
    int y;
    cin >> y;
    cout << str[(((y - 1900) % 12 + 12) % 12)] << endl;
    return 0;
}
