/*************************************************************************
	> File Name: 207.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月13日 星期二 20时55分47秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct {
    char name[20];
    double math;
    double chinese;
    double english;
    double geography;
} student;

int main() {
    int n;
    char name[20] = {0};
    double scores[33] = {0};
    double sum_max = 0, max = -1, min = 101;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        student stu;
        scanf("%s", stu.name);
        (i == n) ||scanf("%lf%lf%lf%lf\n", &stu.math, &stu.chinese, &stu.english, &stu.geography);
        (i == n) && scanf("%lf%lf%lf%lf", &stu.math, &stu.chinese, &stu.english, &stu.geography);
        if (stu.math > max) max = stu.math;
        if (stu.math < min) min = stu.math;
        if (stu.chinese > max) max = stu.chinese;
        if (stu.chinese < min) min = stu.chinese;
        if (stu.english > max) max = stu.english;
        if (stu.english < min) min = stu.english;
        if (stu.geography > max) max = stu.geography;
        if (stu.geography < min) min = stu.geography;
        double temp = stu.math + stu.chinese + stu.english + stu.geography;
        scores[i] = temp;
        if (temp > sum_max)  {
            strcpy(name, stu.name);
            sum_max = temp;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%g\n", scores[i]);
    }
    printf("%s\n", name);
    printf("%g %g\n", max, min);
    return 0;
}
