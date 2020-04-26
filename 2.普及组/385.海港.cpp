/*************************************************************************
	> File Name: 385.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/ 7 16:26:35 2020
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define MAX_N 100000
using namespace std;

int country[MAX_N + 5] = {0};

struct person {
    int time;
    int nation;
};



int main() {
    queue<person> q;
    int n = 0;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t = 0;
        int sum = 0;
        scanf("%d%d", &t, &sum);
        /*每次到达一艘船，将此时刻86400s前的人全部出队列*/
        while (q.empty() != 0) {
            person tmp = q.front();
            if (t - tmp.time < 86400) break;
            q.pop();
            country[tmp.nation]--;
            if (country[tmp.nation] == 0) ans--;
        }

        int j = 0;
        while (j < sum) {
            int tmp;
            scanf("%d", &tmp);
            q.push({t, tmp});
            if (country[tmp] == 0) ans++;
            country[tmp] += 1;

            j++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
