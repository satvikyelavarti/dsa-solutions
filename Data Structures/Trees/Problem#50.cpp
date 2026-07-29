#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>

using namespace std;

class MaxHeapPriorityQueue {
private:
    vector<int> heap;

    // Helper functions
    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return (2 * i) + 1;
    }

    int rightChild(int i) {
        return (2 * i) + 2;
    }

    // Move element upward
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

public:
    // Heapify Down
    void heapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < heap.size() &&
            heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() &&
            heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // Insert element
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Extract maximum element
    int extractMax() {

        if (heap.empty()) {
            throw underflow_error(
                "Priority Queue is empty!"
            );
        }

        int maxVal = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapify(0);
        }

        return maxVal;
    }

    // Return maximum element
    int getMax() const {

        if (heap.empty()) {
            throw underflow_error(
                "Queue is empty!"
            );
        }

        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

    void printQueue() const {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {

    MaxHeapPriorityQueue pq;

    cout << "--- Inserting Elements: "
         << "15, 20, 7, 9, 30 ---"
         << endl;

    pq.insert(15);
    pq.insert(20);
    pq.insert(7);
    pq.insert(9);
    pq.insert(30);

    cout << "Internal vector representation "
         << "of Max Heap: ";

    pq.printQueue();

    cout << "Current Maximum Element: "
         << pq.getMax()
         << endl << endl;

    cout << "--- Extracting Elements by Priority ---"
         << endl;

    while (!pq.empty()) {

        cout << "Extracted Max: "
             << pq.extractMax()
             << " | Remaining Heap: ";

        pq.printQueue();
    }

    return 0;
}