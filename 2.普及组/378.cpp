/*************************************************************************
	> File Name: 378.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/ 6 16:58:52 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

#define MAX_N 300

int main() {
    char str[MAX_N + 5] = {0};
    cin >> str;

    stack<char> s;
    int i = 0;
    while (str[i] && str[i] != '@') {
        switch (str[i]) {
            case '(':
            case '[':
            case '{': {
                s.push(str[i]);
           } break;
            case ')': {
                if (s.empty() || s.top() != '(') {
                    cout << "NO" << endl;
                    return 0;
                }
                s.pop();
            } break;
            case ']': {
                if (s.empty() || s.top() != '[') {
                    cout << "NO" << endl;
                    return 0;
                }
                s.pop();
            } break;
            case '}': {
                if (s.empty() || s.top() != '{') {
                    cout << "NO" << endl;
                    return 0;
                }         
                s.pop();
            } break;
        }
        
        i++;
    }
    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
