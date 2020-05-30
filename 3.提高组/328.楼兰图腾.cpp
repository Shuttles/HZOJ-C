/*************************************************************************
	> File Name: 328.楼兰图腾.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/29 23:07:09 2020
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#define MAX_N 200000
#define lowbit(x) ((x) & (-x))
using namespace std;

int c[MAX_N + 5] = {0};

void add(int i, int val, int n) {
    while (i <= n) {
        c[i] += val;
        i += lowbit(i);
    }
    return ;
}

int64_t query(int i) {
    /*查询前i位的和*/
    int64_t sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}


int main() {
    int n, a;
    int64_t ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(a + 1, 1, n);
        int64_t x = query(a);//已经出现过的比a小的元素个数
        int64_t xx = i - 1 - x;//已经出现过的比a大的元素个数
        int64_t xxx = n - a - xx;//还未出现的比a大的元素个数
        int64_t xxxx = a - 1 - x;//还未出现的比a小的元素个数
        ans1 += (xx * xxx);
        ans2 += (x * xxxx);//^
    }
    cout << ans1 << " " << ans2 << endl;
    /*
    for (int i = 1; i <= n; i++) {
        cout << i << " : " << c[i] << " ";
        cout << query(i) - query(i - 1) << endl;
    }
    */
    return 0;
}
