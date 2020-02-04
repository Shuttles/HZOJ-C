/*************************************************************************
	> File Name: 212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 14时11分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#define max_n 20
using namespace std;

char name[10][max_n + 5];
bool cmp(char a[], char b[]) {
    return strcmp(a, b);
}

int main() {
    for (int i = 0; i < 10; i++) scanf("%s", name[i]);
    sort(name[0], name[9], cmp);
    for (int i = 0; i < 10; i++) printf("%s\n", name[i]);
    return 0;
}
