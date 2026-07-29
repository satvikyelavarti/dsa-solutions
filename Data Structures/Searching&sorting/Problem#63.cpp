#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int target) {
    // Check first element
    if (arr[0] == target)
        return 0;

    // Find range for binary search
    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;

    // Perform binary search in found range
    int left = i / 2;
    int right = (i < n) ? i : n - 1;

    return binarySearch(arr, left, right, target);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 23;

    int index = exponentialSearch(arr, n, target);

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}