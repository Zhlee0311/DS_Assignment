#include <iostream>
#include <vector>

using namespace std;

// 三元组的结构体
struct Triplet {
    int row;
    int col;
    int value;
};

// 获取矩阵元素的函数
int getMatrixElement(const vector<Triplet>& tripletList, int rowIndex, int colIndex) {
    // 初始化行起始向量
    vector<int> rowStartVector(max_element(tripletList.begin(), tripletList.end(),
                                           [](const Triplet& a, const Triplet& b) {
                                               return a.row < b.row;
                                           })->row + 1, 0);

    // 填充行起始向量
    for (const Triplet& triplet : tripletList) {
        if (rowStartVector[triplet.row] == 0) {
            rowStartVector[triplet.row] = &triplet - &tripletList[0];
        }
    }

    // 在二元组顺序表中查找矩阵元素
    for (int k = rowStartVector[rowIndex]; k < rowStartVector[rowIndex + 1]; ++k) {
        if (tripletList[k].col == colIndex) {
            return tripletList[k].value;
        }
    }

    // 如果找不到元素，则返回默认值（例如0）
    return 0;
}

int main() {
    // 例子：三元组顺序表
    vector<Triplet> tripletList = {{0, 1, 3}, {0, 3, 5}, {1, 2, 7}, {2, 0, 1}, {2, 1, 9}};

    // 测试获取矩阵元素的函数
    int rowIndex = 0;
    int colIndex = 3;

    int result = getMatrixElement(tripletList, rowIndex, colIndex);

    cout << "Matrix element at (" << rowIndex << ", " << colIndex << "): " << result << endl;

    return 0;
}
