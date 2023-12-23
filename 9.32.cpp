#include <iostream>

// 二叉排序树的节点结构
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 向二叉排序树中插入节点
TreeNode* insert(TreeNode* root, int key) {
    if (!root) {
        return new TreeNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// 在二叉排序树中找到小于 x 且最靠近 x 的值 a 和大于 x 且最靠近 x 的值 b
void findClosestValues(TreeNode* root, int x, int& a, int& b) {
    if (!root) {
        return;
    }

    // 如果当前节点的值等于 x，则 a 和 b 都等于 x
    if (root->data == x) {
        a = b = x;
        return;
    }

    // 如果当前节点的值小于 x，更新 a，并在右子树中继续查找
    if (root->data < x) {
        a = root->data;
        findClosestValues(root->right, x, a, b);
    } else {
        // 如果当前节点的值大于 x，更新 b，并在左子树中继续查找
        b = root->data;
        findClosestValues(root->left, x, a, b);
    }
}

// 中序遍历打印二叉排序树
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        std::cout << root->data << " ";
        printInOrder(root->right);
    }
}

int main() {
    // 构造二叉排序树
    TreeNode* root = nullptr;
    int keys[] = {3, 1, 8, -9, 0, 6, 9};
    for (int key : keys) {
        root = insert(root, key);
    }

    // 打印二叉排序树
    std::cout << "二叉排序树（中序遍历）: ";
    printInOrder(root);
    std::cout << std::endl;

    // 查找小于 x 且最靠近 x 的值 a 和大于 x 且最靠近 x 的值 b
    int x = 2;
    int a, b;
    findClosestValues(root, x, a, b);

    // 输出结果
    std::cout << "对于 x = " << x << "，小于 x 且最靠近 x 的值 a = " << a
              << "，大于 x 且最靠近 x 的值 b = " << b << std::endl;

    return 0;
}
