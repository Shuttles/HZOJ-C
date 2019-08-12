/*************************************************************************
	> File Name: 462.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 16时33分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cinttypes>
using namespace std;
typedef struct {
    char id[10000];
    int64_t qq;
}user;

int main() {
    int n;
    int64_t k = 0;
    scanf("%d\n", &n);
    int64_t ave = 0;
    int male = 0, female = 0;
    for (int i = 1; i <= n; i++) {
        char x;
        scanf("%c ", &x);
        user person;
        if (x == 'i') {
            scanf("%s\n", person.id);
            int len = strlen(person.id);
            if ((person.id[len - 2] & 15) & 1) male++;
            else female++;
        } else  {
            scanf("%" PRId64 "\n", &person.qq);
            ave += person.qq;
            k++;
        }
    }
    if (k == 0) ave = 0;
    else ave /= k;
    printf("%d %d " "%" PRId64 "\n", male, female, ave);
    return 0;
}

