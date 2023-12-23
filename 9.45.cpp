#include <iostream>
#include <vector>
#include <list>

const int MAX_SIZE = 100; // 哈希表最大长度

// 哈希表节点结构
struct HashNode {
    int key;
};

// 哈希表类
class HashTable {
private:
    int size; // 哈希表长度
    std::vector<std::list<HashNode>> table; // 使用std::list作为链表存储冲突的节点

public:
    HashTable(int tableSize) : size(tableSize), table(tableSize) {}

    // 哈希函数
    int hashFunction(int key) const {
        return key % size;
    }

    // 插入关键字
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back({key});
    }

    // 打印哈希表
    void printTable() const {
        for (int i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const HashNode& node : table[i]) {
                std::cout << node.key << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // 创建哈希表
    int hashTableSize = 10; // 设置哈希表长度
    HashTable hashTable(hashTableSize);

    // 插入一组关键字
    std::vector<int> keys = {12, 5, 7, 18, 23, 15, 28, 33, 10, 42};
    for (int key : keys) {
        hashTable.insert(key);
    }

    // 打印哈希表
    std::cout << "哈希表：" << std::endl;
    hashTable.printTable();

    return 0;
}
