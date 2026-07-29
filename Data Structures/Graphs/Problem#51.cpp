#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[n][n];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<list<int>> adjList(n);

    // Convert matrix to adjacency list
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}