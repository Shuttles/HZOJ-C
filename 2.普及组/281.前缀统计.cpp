/*************************************************************************
	> File Name: 281.前缀统计.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  4/17 20:25:56 2020
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_M 26
#define MAX_N 1000000


struct Node {
    int num;
    Node *next[MAX_M + 5];
};

char str[MAX_N + 5] = {0};

Node *insert(Node *node, char *str);
int search(Node *node, char *str);

int main() {
    Node *root = NULL;
    int N, M;
    cin >> N >> M;
    /*输入*/
    for (int i = 0; i < N; i++) {
        cin >> str;
        root = insert(root, str);
    }
    
    /*查找*/
    while (M--) {
        cin >> str;
        cout << search(root, str) << endl;
    }
    return 0;
}

Node *insert(Node *node, char *str) {
    if (!node) {
        node = new Node();
    }
    if (str[0]) {
        node->next[str[0] - 'a'] = insert(node->next[str[0] - 'a'], str + 1);
    } else {
        node->num++;
    }
    return node;
}

int search(Node *node, char *str) {
    if (!node) return 0;
    if (!str[0]) return node->num;
    int ans = node->num + search(node->next[str[0] - 'a'], str + 1);
    return ans;
}
