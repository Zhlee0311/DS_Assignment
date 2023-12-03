#include <iostream>

// 定义二叉树节点的结构
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 判断两棵二叉树是否相似的递归函数
bool areTreesSimilar(TreeNode* tree1, TreeNode* tree2) {
    // 两棵树均为空，相似
    if (!tree1 && !tree2)
        return true;
    // 一棵树为空，一棵不为空，不相似
    if (!tree1 || !tree2)
        return false;
    // 根节点数值不相等，不相似
    if (tree1->value != tree2->value)
        return false;

    // 递归比较左右子树是否相似
    bool leftSimilarity = areTreesSimilar(tree1->left, tree2->left);
    bool rightSimilarity = areTreesSimilar(tree1->right, tree2->right);

    // 两棵树的左右子树均相似，整体才相似
    return leftSimilarity && rightSimilarity;
}

int main() {
    // 示例用法
    // 构造两棵相似的二叉树
    // B1:
    //    1
    //   / \
    //  2   3
    // B2:
    //    1
    //   / \
    //  2   3
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // 判断两棵二叉树是否相似
    bool result = areTreesSimilar(tree1, tree2);
    std::cout << std::boolalpha << result << std::endl;  // 输出 true

    // 释放动态分配的内存
    delete tree1->left;
    delete tree1->right;
    delete tree1;

    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
