#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    // Build the segment tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;

        build(arr, leftChild, start, mid);
        build(arr, rightChild, mid + 1, end);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    // Range Sum Query
    int queryRange(int node, int start, int end,
                   int ql, int qr) {

        // No overlap
        if (qr < start || ql > end) {
            return 0;
        }

        // Complete overlap
        if (ql <= start && end <= qr) {
            return tree[node];
        }

        // Partial overlap
        int mid = start + (end - start) / 2;

        int leftSum =
            queryRange(2 * node, start, mid, ql, qr);

        int rightSum =
            queryRange(2 * node + 1, mid + 1, end, ql, qr);

        return leftSum + rightSum;
    }

    // Point Update
    void updatePoint(int node, int start, int end,
                     int idx, int val) {

        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid) {
            updatePoint(2 * node, start, mid, idx, val);
        }
        else {
            updatePoint(2 * node + 1,
                        mid + 1,
                        end,
                        idx,
                        val);
        }

        tree[node] =
            tree[2 * node] +
            tree[2 * node + 1];
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();

        tree.resize(4 * n, 0);

        if (n > 0) {
            build(arr, 1, 0, n - 1);
        }
    }

    // Wrapper for query
    int query(int ql, int qr) {
        return queryRange(1, 0, n - 1, ql, qr);
    }

    // Wrapper for update
    void update(int idx, int val) {
        updatePoint(1, 0, n - 1, idx, val);
    }
};

int main() {

    vector<int> arr = {
        1, 3, 5, 7, 9, 11
    };

    SegmentTree st(arr);

    // Sum from index 1 to 3
    cout << "Sum of values in range: "
         << st.query(1, 3)
         << endl;

    // Update index 1
    cout << "Updating element at index 1 to 10..."
         << endl;

    st.update(1, 10);

    // Query again
    cout << "New sum of values in range: "
         << st.query(1, 3)
         << endl;

    return 0;
}