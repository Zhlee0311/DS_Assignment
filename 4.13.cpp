#include <iostream>

using namespace std;

const int N = 100010;
int ne[N];//next数组
char s[N], t[N];//s表示原字符串，t表示待匹配的串


void get_next(const char T[], int m) {
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && T[j + 1] != T[i]) j = ne[j];
        if (T[j + 1] == T[i]) j++;
        ne[i] = j;
    }
}//kmp第一步，求ne数组

int get_first_place(const char S[], const char T[], int n, int m) {
    int res = 0;
    get_next(T, m);
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && S[i] != T[j + 1]) j = ne[j];
        if (S[i] == T[j + 1]) j++;
        if (j == m) {
            res = i - m + 1;
            return res;
        }
    }
    return res;
}//kmp第二步，返回匹配串在原字符串出现的第一个位置

int get_length(const char x[]) {
    int res = 0;
    for (int i = 1; x[i]; i++) {
        res++;
    }
    return res;
}//获取一个字符串的长度，由于从1开始存储，所以从1开始计算

void Delete(char y[], int start, int len) {
    int n = get_length(y);
    for (int i = start; i <= n; i++) {
        y[i] = y[i + len];
    }
}//删除即将后面的字符向前移动

int main() {
    cout << "请输入一个字符串：" << endl;
    cin >> (s + 1);
    cout << "请输入你想在上一个字符串中删除的子串：" << endl;
    cin >> (t + 1);

    int res = get_first_place(s, t, get_length(s), get_length(t));
    while (res) {
        Delete(s, res, get_length(t));
        res = get_first_place(s, t, get_length(s), get_length(t));
    }

    cout << "删除完子串的字符串为：" << endl;
    cout << (s + 1) << endl;

    return 0;
}
