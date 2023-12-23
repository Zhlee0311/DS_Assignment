#include <iostream>
#include <vector>

void optimizedBubbleSort(std::vector<int> &arr) {
    int n = arr.size();
    int lastSwappedIndex = n - 1;

    for (int i = 0; i < n - 1; ++i) {
        int currentLastSwappedIndex = -1;

        for (int j = 0; j < lastSwappedIndex; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                currentLastSwappedIndex = j;
            }
        }

        // 如果在一趟中没有发生交换，说明数组已经有序
        if (currentLastSwappedIndex == -1) {
            break;
        }

        // 更新最后一次交换的位置
        lastSwappedIndex = currentLastSwappedIndex;
    }
}


int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "排序前的数组：";
    for (int num: arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    optimizedBubbleSort(arr);

    std::cout << "排序后的数组:";
    for (int num: arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
