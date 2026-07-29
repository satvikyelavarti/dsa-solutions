#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class OptimizedQuickSort {
private:

    // Select Median-of-Three Pivot
    int selectMedianOfThree(vector<int>& arr,
                            int low,
                            int high) {

        int mid = low + (high - low) / 2;

        if (arr[low] > arr[mid]) {
            swap(arr[low], arr[mid]);
        }

        if (arr[low] > arr[high]) {
            swap(arr[low], arr[high]);
        }

        if (arr[mid] > arr[high]) {
            swap(arr[mid], arr[high]);
        }

        // Move median to high - 1
        swap(arr[mid], arr[high - 1]);

        return high - 1;
    }

    // Partition Function
    int partition(vector<int>& arr,
                  int low,
                  int high) {

        int pivotIdx =
            selectMedianOfThree(arr,
                                low,
                                high);

        int pivot = arr[pivotIdx];

        int i = low - 1;

        for (int j = low;
             j < high - 1;
             j++) {

            if (arr[j] < pivot) {

                i++;

                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1],
             arr[high - 1]);

        return i + 1;
    }

public:

    void sort(vector<int>& arr,
              int low,
              int high) {

        // At least 3 elements
        if (low + 1 < high) {

            int pivotIdx =
                partition(arr,
                          low,
                          high);

            sort(arr,
                 low,
                 pivotIdx - 1);

            sort(arr,
                 pivotIdx + 1,
                 high);
        }

        // Exactly 2 elements
        else if (low < high) {

            if (arr[low] > arr[high]) {
                swap(arr[low],
                     arr[high]);
            }
        }
    }
};

int main() {

    OptimizedQuickSort sorter;

    // Sorted Input
    vector<int> sortedData = {
        10, 20, 30, 40, 50,
        60, 70, 80, 90
    };

    cout << "Original pre-sorted array: ";

    for (int x : sortedData) {
        cout << x << " ";
    }

    cout << endl;

    sorter.sort(
        sortedData,
        0,
        sortedData.size() - 1
    );

    cout << "Processed array layout:    ";

    for (int x : sortedData) {
        cout << x << " ";
    }

    cout << "\n\n";

    // Random Input
    vector<int> randomData = {
        44, 12, 89, 7,
        102, 33, 56,
        12, 9
    };

    cout << "Original random array:     ";

    for (int x : randomData) {
        cout << x << " ";
    }

    cout << endl;

    sorter.sort(
        randomData,
        0,
        randomData.size() - 1
    );

    cout << "Processed array layout:    ";

    for (int x : randomData) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}