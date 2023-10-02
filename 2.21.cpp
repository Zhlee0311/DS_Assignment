#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;//顺序表的最大长度

struct SeqList {
    int Datas[N];
    int Last_index;
};//顺序表结构的定义
void reverse(SeqList &List) {
    int n = List.Last_index;
    for (int i = 0, j = n; i < j; i++, j--) {
        swap(List.Datas[i], List.Datas[j]);
    }
}//算法实现，计算次数为n/2，复杂度为O(n)

int main() {
    int n;//顺序表的长度
    SeqList List = {};//定义一个顺序表
    cout << "Enter the number of elements: ";
    cin >> n;
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        cin >> List.Datas[i];
        List.Last_index = i;
    }
    reverse(List);
    printf("The result after reversing is:\n");
    for (int i = 0; i < n; i++) {
        cout << List.Datas[i] << ' ';
    }
    return 0;
}