#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapCount++;
            }
        }
    }

    cout << "Bubble Sort Swaps: " << swapCount << endl;
}

void insertionSort(int arr[], int n) {
    int swapCount = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swapCount++;   // Count each shift as a swap/move
        }

        arr[j + 1] = key;
    }

    cout << "Insertion Sort Swaps: " << swapCount << endl;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int original[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(original) / sizeof(original[0]);

    int bubbleArr[100];
    int insertionArr[100];

    // Copy original array
    for (int i = 0; i < n; i++) {
        bubbleArr[i] = original[i];
        insertionArr[i] = original[i];
    }

    bubbleSort(bubbleArr, n);
    insertionSort(insertionArr, n);

    cout << "\nSorted array using Bubble Sort: ";
    printArray(bubbleArr, n);

    cout << "Sorted array using Insertion Sort: ";
    printArray(insertionArr, n);

    return 0;
}