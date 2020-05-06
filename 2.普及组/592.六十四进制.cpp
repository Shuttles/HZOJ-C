/*************************************************************************
	> File Name: 592.六十四进制.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 6 20:50:11 2020
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

#define MAX_N 100000

char str[MAX_N + 5];
int num[64];//转成二进制，里面有多少个1
int num2[10] = {1, 2, 4, 8, 16, 32};
int64_t ans = 1;

int main() {
    cin >> str;
    /*计算每个数字转成二进制有多少个1*/
    for (int i = 0; i <= 63; i++) {
        int t = i;
        for (int j = 5; j >= 0; j--) {
            if (t >= num2[j]) {
                num[i]++;
                t -= num2[j];
            }
        }
    }

    /*最后结果就是计算整个字符串转换成二进制后有多少个0，乘以3就行！*/
    for (int i = 0; str[i]; i++) {
        int t;
        if (str[i] >= '0' && str[i] <= '9') {
            t = str[i] & 15;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            t = str[i] - 'A' + 10;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            t = str[i] - 'a' + 36;
        } else if (str[i] == '-') {
            t = 62;
        } else {
            t = 63;
        }
        t = 6 - num[t];
        for (int i = 0; i < t; i++) {
            ans = ans * 3 % 1000000007;
        }
    }
    cout << ans << endl;

    return 0;
}
