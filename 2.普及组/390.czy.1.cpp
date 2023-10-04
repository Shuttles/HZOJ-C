#include <iostream>
using namespace std;
//111110000

#define MAX_N 100000
int n, m;
int arr[MAX_N + 5];
int maxX = 0;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxX = max(maxX, arr[i]);
    }
    return ;
}

bool couldX(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (arr[i] / x);
        if (cnt >= m) {
            return true;
        }
    }
    return false;
}

int bs() {
    int l = 0, r = maxX;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (couldX(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void output() {
    cout << bs() << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}