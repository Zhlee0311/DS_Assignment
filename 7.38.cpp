#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

// 定义图的节点
struct Node {
    char value;
    vector<Node*> neighbors;

    Node(char val) : value(val) {}
};

// 构建有向无环图的邻接表
void buildGraph(vector<Node*>& graph, const vector<string>& rpn) {
    stack<Node*> nodeStack;

    for (const string& token : rpn) {
        Node* newNode = new Node(token[0]);

        if (isdigit(token[0]) || isalpha(token[0])) {
            // 操作数，直接添加到图中
            graph.push_back(newNode);
            nodeStack.push(newNode);
        } else {
            // 运算符，弹出两个操作数，添加到图中，并与运算符建立边
            Node* operand2 = nodeStack.top();
            nodeStack.pop();
            Node* operand1 = nodeStack.top();
            nodeStack.pop();

            graph.push_back(newNode);
            graph.back()->neighbors.push_back(operand1);
            graph.back()->neighbors.push_back(operand2);

            nodeStack.push(newNode);
        }
    }
}

int main() {
    string infixExpression = "a+b*c";

    // 将中缀表达式转换为逆波兰式
    stack<char> operators;
    vector<string> rpn;

    unordered_map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for (char c : infixExpression) {
        if (isalnum(c)) {
            rpn.push_back(string(1, c));
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else {
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                rpn.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        rpn.push_back(string(1, operators.top()));
        operators.pop();
    }

    // 输出逆波兰式
    cout << "逆波兰式: ";
    for (const string& token : rpn) {
        cout << token << " ";
    }
    cout << endl;

    // 构建有向无环图的邻接表
    vector<Node*> graph;
    buildGraph(graph, rpn);

    // 释放图的节点内存
    for (Node* node : graph) {
        delete node;
    }

    return 0;
}
