/*************************************************************************
	> File Name: 122.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 22时30分03秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    int h, m, s;
    if (t < 43200) {
        h = t / 3600;
        m = t % 3600 / 60 ;
        s = t % 3600 % 60 ;
        printf("%02d:%02d:%02d am\n", h, m, s);
    }
    else if (t <= 46800) {
        h = t / 3600 ;
        m = t % 3600 / 60 ;
        s = t % 3600 % 60 ;
       printf("%02d:%02d:%02d midnoon\n", h, m, s);
    }
    else {
        h = t / 3600 - 12;
        m = t % 3600 / 60 ;
        s = t % 3600 % 60 ;
      printf("%02d:%02d:%02d pm\n", h, m, s);
    }
    return 0;
}