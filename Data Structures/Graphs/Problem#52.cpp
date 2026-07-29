#include <iostream>
#include <queue>
using namespace std;

void BFS(int graph[][10], int vertices, int source) {
    bool visited[10] = {false};
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    int graph[10][10] = {0};

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;   // Remove for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    cout << "BFS Traversal: ";
    BFS(graph, vertices, source);

    return 0;
}