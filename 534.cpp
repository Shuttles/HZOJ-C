/*************************************************************************
	> File Name: 534.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/18 20:29:27 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[25], check[1005] = {1}, ans;

void dfs(int s, int sum) {//sum表示到这为止选的数加在一起的和是多少
    if (check[sum] == 0) {
        ans++;
        check[sum] = 1;
    }
    for (int i = s; i < n; i++) {//也可以 <= n，因为去重的时候会解决掉这个问题
        sum += num[i];
        dfs(i + 1, sum);
        sum -= num[i];
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
