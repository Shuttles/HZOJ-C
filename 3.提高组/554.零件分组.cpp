/*************************************************************************
	> File Name: 554.零件分组.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/14 17:16:59 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_N 1000

struct Part {
    int x;
    int y;
} num[MAX_N + 5];

int len[MAX_N + 5];/*记录分成的每组末尾的元素值*/
int ans = 0;/*用来记录最终的组数*/


bool cmp(const Part &a, const Part &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}



int main() {
    /*读入*/
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i].x >> num[i].y;
    }

    sort(num + 1, num + n + 1, cmp);/*先排序,这样x序列一定是不下降的*/
    len[++ans] = num[1].y;/*先初始化第一个组*/

    for (int i = 2; i <= n; i++) {/*给2~n个零件依次分配组别*/
        int temp = 0;
        for (int j = 1; j <= ans; j++) {
            if (len[j] > num[i].y) continue;
            /*可插入某个组*/
            /*找可插入的组末尾值元素的最大值*/
            if (temp == 0) temp = j;
            else if (len[temp] < len[j]) {
                temp = j;
            }
        }
        if (!temp) {/*如果没找到可以插入的组*/
            ans += 1;
            len[ans] = num[i].y;
        } else {
            len[temp] = num[i].y;
        }
    }
    printf("%d\n", ans);
    return 0;
}
