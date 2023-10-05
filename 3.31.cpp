#include<iostream>

using namespace std;
const int N = 110;
bool dp[N][N];
char str[N];

int main() {
    char ch;//待输入的字符
    int index = 1;
    while (cin >> ch && ch != '@') {
        str[index] = ch;
        index++;
    }
    int n = index - 1;//字符串的长度（1～n）

    // 初始化dp数组
    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
    }

    // 动态规划，判断是否为回文串
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (str[l] == str[r]) {
                if (dp[l + 1][r - 1]) {
                    dp[l][r] = true;
                }
            }
        }
    }
    if (dp[1][n]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
