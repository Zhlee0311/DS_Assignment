#include <iostream>
#include <vector>

// 顺序查找算法，将监视哨设在高下标端
int sequentialSearchWithSentinel(std::vector<int> &arr, int key) {
    int n = arr.size();

    // 设置监视哨，将其值设为要查找的关键字
    arr.push_back(key);

    int i = 0;
    while (arr[i] != key) {
        ++i;
    }

    // 恢复数组原有的状态，去掉添加的监视哨
    arr.pop_back();

    // 如果i小于n，说明找到了关键字，返回索引；否则返回-1表示未找到
    return (i < n) ? i : -1;
}

int main() {
    std::vector<int> arr = {12, 34, 56, 78, 90, 32, 65};
    int key = 56;
    std::cout << "关键字序列：";
    for (int num: arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    int result = sequentialSearchWithSentinel(arr, key);

    if (result != -1) {
        std::cout << "关键字 " << key << " 在数组中的位置为 " << result << std::endl;
    } else {
        std::cout << "关键字 " << key << " 未在数组中找到" << std::endl;
    }

    return 0;
}
