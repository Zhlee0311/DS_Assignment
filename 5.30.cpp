#include <iostream>
#include <vector>

using namespace std;

// 定义广义表节点的结构体
struct GListNode {
    char data; // 假设元素为字符类型
    GListNode* next; // 指向下一个节点
};

// 递归求广义表深度的函数
int getGeneralListDepth(GListNode* head) {
    // 如果广义表为空，则深度为0
    if (head == nullptr) {
        return 0;
    }

    // 如果广义表只包含原子元素，深度为1
    if (head->data != '(') {
        return 1;
    }

    // 广义表包含子表，递归求解子表深度
    int maxSubListDepth = 0;
    GListNode* current = head->next; // 跳过表头'('
    while (current != nullptr && current->data != ')') {
        int subListDepth = getGeneralListDepth(current);
        maxSubListDepth = max(maxSubListDepth, subListDepth);
        // 移动到下一个子表（或原子元素）
        current = current->next;
    }

    // 深度为子表深度 + 1（加上当前表头）
    return maxSubListDepth + 1;
}

int main() {
    // 示例广义表的表示，使用链表表示法
    GListNode* head = new GListNode{'(', nullptr};
    head->next = new GListNode{'(', nullptr};
    head->next->next = new GListNode{'a', nullptr};
    head->next->next->next = new GListNode{',', nullptr};
    head->next->next->next->next = new GListNode{'b', nullptr};
    head->next->next->next->next->next = new GListNode{')', nullptr};
    head->next->next->next->next->next->next = new GListNode{')', nullptr};

    // 调用深度计算函数
    int depth = getGeneralListDepth(head);

    // 输出结果
    cout << "Depth of the general list: " << depth << endl;

    // 释放动态分配的内存
    while (head != nullptr) {
        GListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
