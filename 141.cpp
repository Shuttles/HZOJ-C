/*************************************************************************
	> File Name: 141.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 14时43分12秒
 ************************************************************************/
//光哥的代码如下，我没做出来。。。
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0, I = 2 * n + 1; i < I; i++) {
        //首先输出每行的空格
        for (int j = 0, J = n - abs(n - i); j < J; j++) {
            cout << " ";
        }
        //接着输出字符，但是一行里的字符是不同的，而且和列号有关，所以字符复制得放在ｆｏｒ循环里；
        int J = n - abs(n - i);//每行的起始列号;
        for (int j = 0, M = 1 + 2 * abs(n - i); j < M; j++,J++) {
            char ch = 'A' + n - abs(n - J);//每次输出的字符和列号有关
            cout << ch;
        }
        cout << endl;//每行结束要换行
    }
    return 0;
}
