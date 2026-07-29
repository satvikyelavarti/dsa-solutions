#include <iostream>
using namespace std;

const int INF = 1000000;

void dijkstra(int graph[][100], int V, int source) {
    int dist[100];
    bool visited[100];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {

        int minDist = INF;
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 5;

    int graph[100][100] = {0};

    graph[0][1] = 10;
    graph[1][0] = 10;

    graph[0][4] = 5;
    graph[4][0] = 5;

    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[1][4] = 2;
    graph[4][1] = 2;

    graph[2][3] = 4;
    graph[3][2] = 4;

    graph[3][4] = 2;
    graph[4][3] = 2;

    dijkstra(graph, V, 0);

    return 0;
}