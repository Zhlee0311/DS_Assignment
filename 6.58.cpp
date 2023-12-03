#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    bool isThreaded;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr), isThreaded(false) {}
};

void threadTree(TreeNode* root, TreeNode*& prev) {
    if (!root) return;

    // 递归线索化左子树
    threadTree(root->left, prev);

    // 当前节点的左子树为空，将左子树指针线索化为前驱节点
    if (!root->left) {
        root->left = prev;
        root->isThreaded = true;
    }

    // 只有当前节点的左子树不为空时才更新前驱节点
    if (prev && !prev->right) {
        prev->right = root;
        prev->isThreaded = true;
    }

    // 更新前驱节点为当前节点
    prev = root;

    // 递归线索化右子树
    threadTree(root->right, prev);
}

void inOrderTraversal(TreeNode* root) {
    if (!root) return;

    // 找到中序遍历的起始节点（最左边的节点）
    while (root->left)
        root = root->left;

    // 从起始节点开始中序遍历
    while (root) {
        std::cout << root->data << " ";

        if (root->isThreaded)
            root = root->right;
        else {
            root = root->right;
            while (root && !root->isThreaded && root->left)
                root = root->left;
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* prev = nullptr;
    threadTree(root, prev);

    std::cout << "Inorder Traversal: ";
    inOrderTraversal(root);
    std::cout << "\n\nTree Structure:\n";

    std::cout << "       " << root->data << std::endl;
    std::cout << "      / \\" << std::endl;
    std::cout << "     " << root->left->data << "   " << root->right->data << std::endl;
    std::cout << "    / \\" << std::endl;
    std::cout << "   " << root->left->left->data << "   " << root->left->right->data << std::endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
