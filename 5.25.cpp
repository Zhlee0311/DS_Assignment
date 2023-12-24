#include <iostream>
#include <vector>

using namespace std;

// 结构体表示稀疏矩阵的三元组形式
struct Triplet {
    int row;
    int col;
    int value;
};

// 矩阵相加的函数
void addMatrices(const vector<Triplet>& matrixA, const vector<Triplet>& matrixB, vector<Triplet>& resultMatrix) {
    // 遍历矩阵A，将元素加到结果矩阵中
    for (const Triplet& elementA : matrixA) {
        resultMatrix.push_back(elementA);
    }

    // 遍历矩阵B，将元素加到结果矩阵中
    for (const Triplet& elementB : matrixB) {
        // 查找结果矩阵中是否有相同位置的元素
        bool found = false;
        for (Triplet& resultElement : resultMatrix) {
            if (resultElement.row == elementB.row && resultElement.col == elementB.col) {
                // 找到相同位置的元素，执行相加操作
                resultElement.value += elementB.value;
                found = true;
                break;
            }
        }

        // 如果结果矩阵中没有相同位置的元素，将元素添加到结果矩阵中
        if (!found) {
            resultMatrix.push_back(elementB);
        }
    }
}

int main() {
    // 示例稀疏矩阵A和B
    vector<Triplet> matrixA = {{0, 1, 3}, {0, 3, 5}, {1, 2, 7}};
    vector<Triplet> matrixB = {{0, 1, 2}, {0, 2, 4}, {1, 2, 3}};

    // 初始化结果矩阵
    vector<Triplet> resultMatrix;

    // 调用矩阵相加函数
    addMatrices(matrixA, matrixB, resultMatrix);

    // 输出结果矩阵
    cout << "Result Matrix:" << endl;
    for (const Triplet& resultElement : resultMatrix) {
        cout << "(" << resultElement.row << ", " << resultElement.col << ", " << resultElement.value << ")" << endl;
    }

    return 0;
}
