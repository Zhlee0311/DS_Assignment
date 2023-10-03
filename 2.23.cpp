#include<iostream>
#include<random>

using namespace std;

struct ListNode {
    int Val;
    ListNode *Next;

    explicit ListNode(int Val) : Val(Val), Next(nullptr) {

    }
};

ListNode *List_Merge(ListNode *Head_a, ListNode *Head_b) {
    ListNode *a = Head_a;
    ListNode *b = Head_b;
    ListNode *res = a;//res表示合并后的链表的头指针
    while (a != nullptr && b != nullptr) {
        ListNode *a_next = a->Next;
        ListNode *b_next = b->Next;
        a->Next = b, a = a_next;
        if (a != nullptr) {
            b->Next = a;
            b = b_next;
        }
    }
    return res;
}//时间复杂度为O(n)

ListNode *List_Generate(ListNode *(&Head), int x) {
    Head = nullptr;
    ListNode *Current;
    for (int i = 1; i <= x; i++) {
        ListNode *New = new ListNode(i);
        if (Head == nullptr) {
            Head = New;
            Current = New;
        } else {
            Current->Next = New;
            Current = New;
        }
    }
    return Head;
}

void List_Print(ListNode *p) {
    while (p != nullptr) {
        cout << p->Val << ' ';
        p = p->Next;
    }
    cout << endl;
}

int init() {
    random_device rd;//创建随机数生成器引擎
    mt19937 gen(rd()); //使用Mersenne Twister算法生成随机数
    uniform_int_distribution<int> dis(1, 15); // 生成1到15之间的随机整数
    return dis(gen);
}

int main() {
    ListNode *Head_a = List_Generate(Head_a, init());//构建链表a
    ListNode *Head_b = List_Generate(Head_b, init());//构建链表b
    //结果展示
    ListNode *p;
    p = Head_a;
    cout << "List a is:" << endl;
    List_Print(p);//打印链表a
    p = Head_b;
    cout << "List b is:" << endl;
    List_Print(p);//打印链表b
    p = List_Merge(Head_a, Head_b);//t为合并后的链表的头指针
    cout << "The list after merging is:" << endl;
    List_Print(p);//打印合并后的链表
    return 0;
}