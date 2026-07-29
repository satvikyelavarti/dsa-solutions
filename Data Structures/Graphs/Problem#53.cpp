#include <iostream>
using namespace std;

void DFS(int graph[][10], bool visited[], int vertices, int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, vertices, i);
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

    bool visited[100] = {false};

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    cout << "DFS Traversal: ";
    DFS(graph, visited, vertices, source);

    return 0;
}