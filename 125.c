/*************************************************************************
	> File Name: 125.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 09时48分03秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int h, m, s, t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    int h1, m1, s1;
    h1 = t / 3600;
    m1 = t % 3600 / 60;
    s1 = t % 3600 % 60;
    s1 = s + s1;
    if (s1 >= 60) {
        m1++;
        s1 -= 60;
    }
    m1 = m + m1;
    if (m1 >= 60) {
        h1++;
        m1 -=60;
    }
     if (h + h1 >= 24) {
        h1 = h + h1 -24;
        if (h1 == 0) {
             
             printf("12:%d:%dam\n%.2f%%\n", m1, s1, t/86400.0 *100);
        }
        else if (h1 > 0 && h1 < 12) {

             printf("%d:%d:%dam\n%.2f%%\n", h1, m1, s1, t/86400.0 * 100);
        }
        else if (h1 == 12) {

             printf("%d:%d:%dpm\n%.2f%%\n", h1, m1, s1, t/86400.0 * 100);
        }
        else {
            h1 = h1 - 12;
            printf("%d:%d:%dpm\n%.2f%%\n", h1, m1, s1, t/86400.0 * 100);
        } 
    }
    else {
        h1 = h + h1;
        if (h1 == 0) {
             
             printf("12:%d:%dam\n%.2f%%\n", m1, s1, t/86400.0 * 100);
        }
        else if (h1 > 0 && h1 < 12) {

             printf("%d:%d:%dam\n%.2f%%\n", h1, m1, s1, t/86400.0 * 100);
        }
        else if (h1 == 12) {

             printf("%d:%d:%dpm\n%.2f%%\n", h1, m1, s1, t/86400.0 * 100);
        }
        else {
            h1 = h1 - 12;
            printf("%d:%d:%dpm\n%.2f%%\n", h1, m1, s1, t/86400.0 * 100);
        }   }
    return 0;
    
}
