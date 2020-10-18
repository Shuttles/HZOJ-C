/*************************************************************************
	> File Name: 537.门票问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 10/10 15:05:03 2020
 ************************************************************************/

//这就是个组合数问题！！！！！
//不过加了一些剪枝！！
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 26

int l, c;
int vowel;//元音
int consonant;//辅音
char alph[MAX_N + 5], psw[MAX_N + 5]; 
bool used[MAX_N + 5];
int cnt;

void dfs(int depth);
bool is_vowel(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> alph[i];
    }
    
    sort(alph, alph + c);
    dfs(0);

    return 0;
}

void dfs(int depth) {
    if (cnt >= 25000) return ;//如果超过25000个密码，算都别算了！！浪费时间(反正也不输出！)
    if (depth >= l) {
        if (vowel < 1 || consonant < 2) {
            return ;
        }
        cnt += 1;
        for (int i = 0; i < depth; i++) {
            cout << psw[i];
        }
        cout << endl;
        return ;
    }

    for (int i = 0; i < c; i++) {
        if (depth != 0) {
            if (alph[i] < psw[depth - 1]) continue;           //剪枝
        }
        if (used[i] == true) continue;

        //选择成功
        if (is_vowel(alph[i])) {
            vowel += 1;
        } else {
            consonant += 1;
        }
        

        used[i] = true;
        psw[depth] = alph[i];
        dfs(depth + 1);
        used[i] = false;

        if (is_vowel(alph[i])) {
            vowel -= 1;
        } else {
            consonant -= 1;
        }
    }
    return ;
}
