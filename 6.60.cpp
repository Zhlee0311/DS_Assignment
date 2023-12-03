#include <iostream>

struct TreeNode {
    int data;
    TreeNode* firstChild; // 孩子节点
    TreeNode* nextSibling; // 兄弟节点

    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

int countLeaves(TreeNode* root) {
    if (!root) return 0;

    if (!root->firstChild) {
        // 如果没有孩子，说明是叶子节点
        return 1;
    }

    // 递归统计所有孩子的叶子节点个数，再加上兄弟的叶子节点个数
    return countLeaves(root->firstChild) + countLeaves(root->nextSibling);
}

int main() {
    // 创建以“孩子-兄弟”链表表示的树
    TreeNode* root = new TreeNode(1);
    root->firstChild = new TreeNode(2);
    root->firstChild->nextSibling = new TreeNode(3);
    root->firstChild->nextSibling->nextSibling = new TreeNode(4);
    root->firstChild->firstChild = new TreeNode(5);
    root->firstChild->firstChild->nextSibling = new TreeNode(6);
    root->firstChild->firstChild->nextSibling->nextSibling = new TreeNode(7);

    // 打印树的结构
    std::cout << "Tree Structure:\n";
    std::cout << "       " << root->data << std::endl;
    std::cout << "      / \\" << std::endl;
    if (root->firstChild) {
        std::cout << "     " << root->firstChild->data << "   " << root->firstChild->nextSibling->data << std::endl;
        std::cout << "    / \\" << std::endl;
        if (root->firstChild->firstChild) {
            std::cout << "   " << root->firstChild->firstChild->data << "   "
                      << root->firstChild->firstChild->nextSibling->data << std::endl;
        }
    }

    // 统计叶子节点个数并输出
    int leafCount = countLeaves(root);
    std::cout << "\nNumber of Leaves: " << leafCount << std::endl;

    // 释放内存
    delete root->firstChild->firstChild;
    delete root->firstChild->firstChild->nextSibling;
    delete root->firstChild->firstChild->nextSibling->nextSibling;
    delete root->firstChild->nextSibling->nextSibling;
    delete root->firstChild->nextSibling;
    delete root->firstChild;
    delete root;

    return 0;
}
