#include <iostream>

// 定义单链表节点结构
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// 插入节点到链表尾部
void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 释放链表内存
void deleteList(ListNode*& head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// 打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 简单选择排序算法
void selectionSort(ListNode*& head) {
    ListNode* sorted = nullptr;
    ListNode* current = head;

    while (current) {
        ListNode* minNode = current;
        ListNode* temp = current->next;

        // 找到未排序部分中的最小节点
        while (temp) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }

        // 将最小节点移动到已排序部分的末尾
        if (minNode != current) {
            std::swap(minNode->data, current->data);
        }

        // 更新已排序部分的末尾
        if (!sorted) {
            sorted = current;
        } else {
            sorted = sorted->next;
        }

        current = current->next;
    }
}

int main() {
    ListNode* head = nullptr;

    // 插入一些节点
    insertAtEnd(head, 64);
    insertAtEnd(head, 34);
    insertAtEnd(head, 25);
    insertAtEnd(head, 12);
    insertAtEnd(head, 22);
    insertAtEnd(head, 11);
    insertAtEnd(head, 90);

    std::cout << "原始链表: ";
    printList(head);

    // 对链表进行简单选择排序
    selectionSort(head);

    std::cout << "排序后的链表: ";
    printList(head);

    // 释放链表内存
    deleteList(head);

    return 0;
}
