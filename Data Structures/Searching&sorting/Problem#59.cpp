#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    // Base case: element not found
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    // Element found
    if (arr[mid] == target)
        return mid;

    // Search in left half
    if (target < arr[mid])
        return binarySearch(arr, left, mid - 1, target);

    // Search in right half
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 50;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}