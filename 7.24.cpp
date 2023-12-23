#include <iostream>
#include <stack>
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

    void iterativeDFS(int start_vertex) {
        // 非递归形式的深度优先搜索
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start_vertex);

        while (!s.empty()) {
            int current_vertex = s.top();
            s.pop();

            if (!visited[current_vertex]) {
                cout << current_vertex << " ";

                visited[current_vertex] = true;

                for (int neighbor : adjacency_list[current_vertex]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
    }

private:
    int vertices;
    vector<vector<int>> adjacency_list;
};

int main() {
    DirectedGraph graph(5);

    // 添加有向边
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 3);

    // 从顶点 0 开始进行非递归形式的深度优先搜索
    cout << "深度优先搜索结果: ";
    graph.iterativeDFS(0);

    return 0;
}
