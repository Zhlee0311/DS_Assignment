#include<iostream>

using namespace std;
const int Max_Size = 10;
const int Error_1 = -1;
const int Error_2 = -2;

class CircularQueue {
private:
    int front;//队列的头指针
    int rear;//队列的尾指针
    int length;//队列中元素的个数
    int ele[Max_Size]{};//队列中存元素的数组
public:
    CircularQueue() {
        front = -1;
        rear = -1;
        length = 0;
    }// 初始化循环队列
    bool is_Empty() const {
        if (front == -1 && rear == -1)return true;
        else return false;
    }//当头指针与尾指针均为-1时循环队列为空
    bool is_Full() const {
        if (length == Max_Size)return true;
        else return false;
    }//根据循环队列的长度判断是否为空，同时也可以根据头尾指针的相对位置来判断
    void enqueue(int x) {
        if (is_Empty()) {
            ele[++rear] = x;
            front++;
            length++;
            printf("原队列为空，%d已成功进队！\n", x);
        } else if (is_Full()) {
            int hh = ele[front];
            front = (front + 1) % Max_Size;
            rear = (rear + 1) % Max_Size;
            ele[rear] = x;
            printf("队列已满，%d已成功进队并覆盖队头元素%d！\n", x, hh);
        } else {
            rear = (rear + 1) % Max_Size;
            ele[rear] = x;
            length++;
            printf("%d已成功进队，当前队列元素个数为%d。\n", x, length);
        }
    }//根据循环队列空、满、非空非满三种情况选择不同的进队方式
    int dequeue() {
        if (is_Empty()) {
            return Error_1;
        } else if (front == rear) {
            front = -1;
            rear = -1;
            length--;
            return Error_2;
        } else {
            front = (front + 1) % Max_Size;
            int hh = ele[front];
            length--;
            return hh;
        }
    }//根据循环队列空、仅有一个元素、非空且不只有一个元素三种情况选择不同的出队方式，该函数返回正常情况下出队后队头的元素
    void get_length() const {
        printf("队列中现有%d个元素！\n", length);
    }

    void print_queue() {
        if (is_Empty()) {
            cout << "队列为空！" << endl;
            return;
        } else if (front == rear) {
            cout << "队列中所有的元素为：";
            cout << ele[front] << endl;
            return;
        } else {
            int hh = front, tt = rear;
            cout << "队列中所有的元素为：";
            while (hh != tt) {
                cout << ele[hh] << ' ';
                hh = (hh + 1) % Max_Size;
            }
            cout << ele[hh] << endl;
        }
    }
};

int main() {
    CircularQueue q;
    int option;
    cout << "请选择你要进行的操作：" << endl;
    printf("1.使一个元素入队 2.使队头元素出队 3.查询当前队列元素的个数 4.输出当前队列中的所有元素 5.退出\n");
    while (cin >> option) {
        switch (option) {
            case 1: {
                int x;
                cout << "请输入要入队的元素：";
                cin >> x;
                q.enqueue(x);
                break;
            }
            case 2: {
                int t = q.dequeue();
                if (t == Error_1) {
                    cout << "当前队列为空，无法使元素出队！" << endl;
                } else if (t == Error_2) {
                    cout << "当前队列为空，已无队头元素！" << endl;
                } else {
                    cout << "当前队列的队头元素为：" << t << endl;
                }
                break;
            }
            case 3: {
                q.get_length();
                break;
            }
            case 4: {
                q.print_queue();
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                cout << "请重新选择！" << endl;
                continue;
            }
        }
        cout << endl;
        cout << "请选择你要进行的操作：" << endl;
        printf("1.使一个元素入队 2.使队头元素出队 3.查询当前队列元素的个数 4.输出当前队列中的所有元素 5.退出\n");
    }
    return 0;
}