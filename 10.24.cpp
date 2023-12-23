#include <iostream>
#include <vector>

void twoWayInsertionSort(std::vector<int> &arr) {
    int n = arr.size();

    // 将序列分为两个部分
    int mid = n / 2;
    std::vector<int> leftPart(arr.begin(), arr.begin() + mid);
    std::vector<int> rightPart(arr.begin() + mid, arr.end());

    // 对两个部分分别进行插入排序
    std::sort(leftPart.begin(), leftPart.end());
    std::sort(rightPart.begin(), rightPart.end());

    // 合并两个有序部分
    int i = 0, j = 0, k = 0;
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] < rightPart[j]) {
            arr[k] = leftPart[i];
            ++i;
        } else {
            arr[k] = rightPart[j];
            ++j;
        }
        ++k;
    }

    // 将剩余的元素添加到序列中
    while (i < leftPart.size()) {
        arr[k] = leftPart[i];
        ++i;
        ++k;
    }

    while (j < rightPart.size()) {
        arr[k] = rightPart[j];
        ++j;
        ++k;
    }
}

// 示例
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "排序前的数组：";
    for (int num: arr) {
        std::cout << " " << num;
    }
    std::cout<<std::endl;
    twoWayInsertionSort(arr);

    std::cout << "排序后的数组:";
    for (int num: arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
