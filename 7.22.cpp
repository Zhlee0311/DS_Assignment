#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DirectedGraph {
public:
    DirectedGraph(int vertices) : vertices(vertices) {
        adjacency_list.resize(vertices);
    }

    void addEdge(int start_vertex, int end_vertex) {
        // 添加有向边，从start_vertex指向end_vertex
        adjacency_list[start_vertex].push_back(end_vertex);
    }

    bool hasPath(int start_vertex, int end_vertex) {
        // 使用深度优先搜索判断是否存在路径
        unordered_set<int> visited;
        return dfs(start_vertex, end_vertex, visited);
    }

private:
    int vertices;
    vector<vector<int>> adjacency_list;

    bool dfs(int current_vertex, int target_vertex, unordered_set<int>& visited) {
        // 如果当前顶点等于目标顶点，说明找到了路径
        if (current_vertex == target_vertex) {
            return true;
        }

        // 将当前顶点标记为已访问
        visited.insert(current_vertex);

        // 对当前顶点的邻接顶点进行深度优先搜索
        for (int neighbor : adjacency_list[current_vertex]) {
            // 如果邻接顶点未访问过，则递归进行深度优先搜索
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, target_vertex, visited)) {
                    return true;  // 找到路径，返回true
                }
            }
        }

        return false;  // 未找到路径
    }
};

int main() {
    
    DirectedGraph graph(5);

    // 添加有向边
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 4);

    // 判断是否存在路径
    int vi = 0;
    int vj = 4;
    bool hasPath = graph.hasPath(vi, vj);

    // 输出结果
    if (hasPath) {
        cout << "存在路径从顶点 " << vi << " 到顶点 " << vj << endl;
    } else {
        cout << "不存在路径从顶点 " << vi << " 到顶点 " << vj << endl;
    }

    return 0;
}
