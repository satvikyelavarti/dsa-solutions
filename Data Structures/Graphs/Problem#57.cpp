#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int parent[100];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(Edge edges[], int V, int E) {
    sortEdges(edges, E);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cablesUsed = 0;
    int totalCost = 0;

    cout << "Selected connections:\n";

    for (int i = 0; i < E && cablesUsed < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            unite(u, v);

            cout << u << " - " << v
                 << " (cost = " << edges[i].weight << ")\n";

            totalCost += edges[i].weight;
            cablesUsed++;
        }
    }

    if (cablesUsed == V - 1) {
        cout << "\nMinimum cables needed = "
             << cablesUsed << endl;

        cout << "Total cost = "
             << totalCost << endl;
    } else {
        cout << "Network cannot be fully connected\n";
    }
}

int main() {
    int V = 4;

    Edge edges[] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    int E = 5;

    kruskal(edges, V, E);

    return 0;
}