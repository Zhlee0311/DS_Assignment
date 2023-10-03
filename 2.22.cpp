#include<iostream>
#include<algorithm>

using namespace std;

struct ListNode {
    int Val;
    ListNode *Next;

    explicit ListNode(int Val) : Val(Val), Next(nullptr) {

    }
};//链表的结构定义
ListNode *reverse(ListNode *Head_node) {
    ListNode *a = Head_node;
    ListNode *b = a->Next;
    while (b != nullptr) {
        if (a == Head_node)a->Next = nullptr;
        ListNode *c = b->Next;
        b->Next = a;
        a = b;
        b = c;
    }
    return a;
}//该逆置函数接受一个链表指针形参数，然后返回链表逆置后的头节点，时间复杂度为O(n)

int main() {
    int n, num;
    cout << "Enter the number of elements:";
    cin >> n;
    printf("Enter %d numbers:\n", n);
    cin >> num;
    auto *Head = new ListNode(num);
    ListNode *Current = Head;
    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        auto *New = new ListNode(num);
        Current->Next = New;
        Current = New;
    }
    auto t = reverse(Head);//t为逆置后的链表的头节点
    cout << "The result after reversing is:"<<endl;
    while (t != nullptr) {
        cout << t->Val << ' ';
        t = t->Next;
    }
    return 0;
}