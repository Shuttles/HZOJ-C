/*************************************************************************
	> File Name: 127.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 14时13分18秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int i, x, n;
    double x1;
    scanf("%lf%d", &x1, &n);
    for (i = 1; i <= n; ++i) {
        
        x1 *= 1.06;
        
    }
   // x = (int) (x1);
    printf("%lf\n", x1);
   

    return 0;
}
