/*************************************************************************
	> File Name: 3.44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月17日 星期六 14时45分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 1000000
using namespace std;

int arr[max_n + 5];
int len[max_n + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        len[i] = 1;
    }
    int longest_len = 0;
    for (int i = 1; i < n; i++) {
        int temp = -1, temp_len = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            if (len[j] >= temp_len) temp_len = len[j], temp = j;
        }
        //上面的len[j] > temp_len可行否？到底有无影响?
        //答案是没有影响！！！比如1 2 3 7 5 9 最长子序列选7或5都没关系因为下一个数一定比9大！！
        //printf("temp_len = %d temp = %d\n", temp_len, temp);
        if (temp != -1 )len[i] += len[temp];
        if (len[i] > longest_len) longest_len = len[i];
    }
    printf("%d\n", longest_len);
    return 0;
}
