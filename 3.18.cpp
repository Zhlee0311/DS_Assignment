#include<iostream>
#include<unordered_map>

using namespace std;
const int N = 1010;
struct stack {
    char ch[N];
    int top;
};//栈的结构定义
unordered_map<char, char> bracket_pair{
        {')', '('},
        {']', '['},
        {'}', '{'},
};//哈希表表示相匹配的括号

bool is_bracket(char ch) {
    return (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}');
}//判断一个字符是否为括号

bool bracket_match(const string &x) {
    stack st{};
    st.top = -1;
    for (int i = 0; x[i]; i++) {
        if (!is_bracket(x[i]))continue;
        else if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            st.ch[++st.top] = x[i];
        } else {
            if (st.top == -1 || st.ch[st.top] != bracket_pair[x[i]]) {
                return false;
            } else st.top--;
        }
    }
    return (st.top == -1);
}//判断一个表达式中的括号是否匹配，时间复杂度为O(n),n为表达式的长度

int main() {
    string input;
    cout << "Enter an expression to check whether its brackets are balanced:" << endl;
    cin >> input;
    if (bracket_match(input))cout << "It's balanced." << endl;
    else cout << "It's unbalanced." << endl;
    return 0;
}