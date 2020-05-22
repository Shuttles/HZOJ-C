/*************************************************************************
	> File Name: 1.小k的课设.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  5/22 18:37:57 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 3000

struct Info {
    int s_id, l_id;
};

Info arr[MAX_N + 5];

bool cmp1(Info a, Info b) {
    if (a.s_id == b.s_id) return a.l_id < b.l_id;
    return a.s_id < b.s_id;
}

bool cmp2(Info a, Info b) {
    if (a.l_id == b.l_id) return a.s_id < b.s_id;
    return a.l_id < b.l_id;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        /*输入数据*/
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            arr[i].s_id = a;
            arr[i].l_id = b;
        }
        /*处理数据*/
        /*第一组输出*/
        sort(arr + 1, arr + 1 + n, cmp1);
        int i = 1;
        while (arr[i].s_id) {
            //printf("S %d %d", arr[i].s_id, arr[i].l_id);
            cout << "S " << arr[i].s_id << " " << arr[i].l_id;
            int temp = arr[i].s_id;
            i += 1;
            while (arr[i].s_id && arr[i].s_id == temp) {
                //printf(" %d", arr[i].l_id);
                cout << " " << arr[i].l_id;
                i++;
            }
            //printf("\n");
            cout << endl;
        }

        /*第二组输出*/
        sort(arr + 1, arr + 1 + n, cmp2);
        i = 1;
        while (arr[i].s_id) {
            //printf("L %d %d", arr[i].l_id, arr[i].s_id);
            cout << "L " << arr[i].l_id << " " << arr[i].s_id;
            int temp = arr[i].l_id;
            i += 1;
            while (arr[i].s_id && arr[i].l_id == temp) {
                //printf(" %d", arr[i].s_id);
                cout << " " << arr[i].s_id;
                i++;
            }
            //printf("\n");
            cout << endl;
        }

    }

    return 0;
}
