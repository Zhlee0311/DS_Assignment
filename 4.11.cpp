#include <iostream>
#include <string>
#include <map>

using namespace std;

// 自定义函数来查找字符是否在字符串中出现
bool containsChar(const string &str, char c) {
    for (char ch: str) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}

pair<string, map<char, int>> getUniqueCharacters(const string &s, const string &t) {
    string r;
    map<char, int> firstOccurrence;

    for (int i = 0; i < s.length(); ++i) {
        if (firstOccurrence.find(s[i]) == firstOccurrence.end()) {
            firstOccurrence[s[i]] = i;
        }
    }

    for (char c: s) {
        if (!containsChar(t, c) && !containsChar(r, c)) {
            r += c;
        }
    }

    return make_pair(r, firstOccurrence);
}

int main() {
    string s, t;
    printf("请输入一个字符串s：\n");
    cin >> s;
    printf("好的，请再输入一个字符串t：\n");
    cin >> t;
    pair<string, map<char, int>> result = getUniqueCharacters(s, t);
    string r = result.first;
    map<char, int> firstOccurrence = result.second;

    cout << "新串r: " << r << endl;
    cout << "r中每个字符在s中第一次出现的位置:" << endl;

    for (char c: r) {
        cout << c << " 第一次出现的位置: " << firstOccurrence[c] << endl;
    }

    return 0;
}
