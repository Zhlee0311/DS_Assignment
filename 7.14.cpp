#include <iostream>
#include <vector>

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

    void printGraph() {
        // 打印邻接表
        for (int vertex = 0; vertex < vertices; ++vertex) {
            cout << "顶点 " << vertex << " 的邻接表: ";
            for (int neighbor : adjacency_list[vertex]) {
                cout << neighbor << " -> ";
            }
            cout << "NULL" << endl;
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
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 4);

    // 打印邻接表
    graph.printGraph();

    return 0;
}
