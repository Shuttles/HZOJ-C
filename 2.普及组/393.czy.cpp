/*************************************************************************
	> File Name: 393.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 10/20 22:31:09 2020
 ************************************************************************/

//这题就是390原木切割的小数版本！！
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 10000

int n, k;
double arr[MAX_N + 5], max_len;

int is_succ(double len);//语义信息：每条绳子长度为len时可不可以切割出k条长度相同的绳子
double bs();

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        max_len = max(max_len, arr[i]);
    }
    double ans = bs();
    //printf("%.2lf\n", ans);不能这么写！！！这么写是四舍五入！！而题目要求直接舍弃！！
    printf("%d.%d%d\n", (int)ans, (int)(ans * 10) % 10, (int)(ans * 100) % 10);
    return 0;
}

int is_succ(double len) {
    int sum = 0;//切出的长度相同的绳子的条数
    for (int i = 1; i <= n; i++) {
        sum += (int)(arr[i] / len);
        if (sum >= k) {
            return 1;
        }
    }
    return 0;
}

double bs() {
    double head = 0.0, tail = max_len;
    while (tail - head > 0.0001) {
        double mid = (head + tail) / 2;
        if (is_succ(mid)) head = mid;
        else tail = mid;//直接等于mid就行！！！！！
    }
    return head;
}

