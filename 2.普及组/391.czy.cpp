/*************************************************************************
	> File Name: 391.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 10/20 20:12:44 2020
 ************************************************************************/
 //本质是:00001111找第一个1
 //不过二分答案最关键的在于“是否满足条件”的判断函数
 //当你想不出“每段和的最大值为x可不可以”时，你可以先假设可以，根据这个条件去求能不能分成m段！
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

long long n, m, sum, max_num;
long long arr[MAX_N + 5];

int is_succ(long long x);//语义信息：每段和的最大值为x可不可以
long long bs();

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
        max_num = max(max_num, arr[i]);
    }
    cout << bs() << endl;

    return 0;
}

int is_succ(long long x) {
    //先假设每段和的最大值为x可以，根据x求出最多可以分成几段，再和m对比来判断
    long long now_sum = 0, cnt = 0;//now_sum表示当前求的和, cnt表示当前已经分成几段
    for (int i = 1; i <= n; i++) {
        if (now_sum + arr[i] == x) {
            now_sum = 0;
            cnt += 1;
        } else if (now_sum + arr[i] > x) {
            now_sum = arr[i];
            cnt += 1;
        } else {
            now_sum += arr[i];
        }
    }
    if (now_sum > 0) {
        cnt += 1;//这个一定不能忘！
    }

    //开始判断
    if (cnt <= m) {
        return 1;
    } else {
        return 0;
    }
}

long long bs() {
    long long head = max_num, tail = sum;//上下界寻找一定要正确！！
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (is_succ(mid)) tail = mid;
        else head = mid + 1;
    }
    return tail;
}
