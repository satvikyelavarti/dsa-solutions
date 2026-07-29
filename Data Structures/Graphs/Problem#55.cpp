#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// ==========================================
// 1. DIRECTED GRAPH CYCLE DETECTION (DFS)
// ==========================================

class DirectedGraph {
private:
    int V;
    vector<vector<int>> adj;

    bool dfsCheck(int node,
                  vector<bool>& visited,
                  vector<bool>& in_stack) {

        visited[node] = true;
        in_stack[node] = true;

        for (int neighbor : adj[node]) {

            if (in_stack[neighbor]) {
                return true;
            }

            if (!visited[neighbor]) {
                if (dfsCheck(neighbor,
                             visited,
                             in_stack)) {
                    return true;
                }
            }
        }

        in_stack[node] = false;

        return false;
    }

public:
    DirectedGraph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool hasCycle() {

        vector<bool> visited(V, false);
        vector<bool> in_stack(V, false);

        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                if (dfsCheck(i,
                             visited,
                             in_stack)) {
                    return true;
                }
            }
        }

        return false;
    }
};

// ==========================================
// 2. DISJOINT SET (DSU)
// ==========================================

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {

        parent.resize(n);

        iota(parent.begin(),
             parent.end(),
             0);

        rank.resize(n, 0);
    }

    int find(int i) {

        if (parent[i] == i) {
            return i;
        }

        return parent[i] =
               find(parent[i]);
    }

    bool unite(int i, int j) {

        int root_i = find(i);
        int root_j = find(j);

        if (root_i == root_j) {
            return false;
        }

        if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        }
        else if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        }
        else {
            parent[root_j] = root_i;
            rank[root_i]++;
        }

        return true;
    }
};

// ==========================================
// 3. UNDIRECTED GRAPH CYCLE DETECTION
// ==========================================

class UndirectedGraph {
private:
    int V;
    vector<pair<int, int>> edges;

public:
    UndirectedGraph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }

    bool hasCycle() {

        DisjointSet dsu(V);

        for (auto const& edge : edges) {

            int u = edge.first;
            int v = edge.second;

            if (!dsu.unite(u, v)) {
                return true;
            }
        }

        return false;
    }
};



int main() {

    // Directed Graph
    DirectedGraph dg(4);

    dg.addEdge(0, 1);
    dg.addEdge(1, 2);
    dg.addEdge(2, 3);
    dg.addEdge(3, 1);

    cout << "Directed Graph Cycle Detection: ";

    if (dg.hasCycle()) {
        cout << "Cycle Detected!" << endl;
    }
    else {
        cout << "No Cycle Detected." << endl;
    }

    // Undirected Graph
    UndirectedGraph ug(4);

    ug.addEdge(0, 1);
    ug.addEdge(1, 2);
    ug.addEdge(2, 3);
    ug.addEdge(3, 0);

    cout << "Undirected Graph Cycle Detection (DSU): ";

    if (ug.hasCycle()) {
        cout << "Cycle Detected!" << endl;
    }
    else {
        cout << "No Cycle Detected." << endl;
    }

    return 0;
}