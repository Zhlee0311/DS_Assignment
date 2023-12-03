#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 树节点结构
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 先序遍历的非递归算法
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) {
        return result;
    }

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        result.push_back(node->value);

        // 先将右子树入栈，再将左子树入栈
        if (node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }

    return result;
}

int main() {
    // 创建一个示例树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Tree Structure:" << endl;
    cout << "       1" << endl;
    cout << "      / \\" << endl;
    cout << "     2   3" << endl;
    cout << "    / \\" << endl;
    cout << "   4   5" << endl;

    // 进行先序遍历
    vector<int> result = preorderTraversal(root);

    // 输出遍历结果
    cout << "\nPreorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
