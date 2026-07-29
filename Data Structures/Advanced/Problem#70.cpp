#include <iostream>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    // Union by Rank
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        // Already in the same set
        if (root_i == root_j) {
            return false;
        }

        // Attach smaller rank tree under larger rank tree
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

    // Check if two elements belong to the same set
    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }
};

int main() {
    // Create DSU with 5 elements: 0,1,2,3,4
    DisjointSetUnion dsu(5);

    // Union operations
    dsu.unite(0, 1);
    dsu.unite(2, 3);

    // Connectivity checks
    cout << "0 and 1 connected? "
         << (dsu.isConnected(0, 1) ? "Yes" : "No")
         << endl;

    cout << "1 and 2 connected? "
         << (dsu.isConnected(1, 2) ? "Yes" : "No")
         << endl;

    // Merge the two groups
    dsu.unite(1, 2);

    cout << "\nAfter uniting 1 and 2:" << endl;

    cout << "0 and 3 connected? "
         << (dsu.isConnected(0, 3) ? "Yes" : "No")
         << endl;

    cout << "4 connected to 0? "
         << (dsu.isConnected(4, 0) ? "Yes" : "No")
         << endl;

    return 0;
}