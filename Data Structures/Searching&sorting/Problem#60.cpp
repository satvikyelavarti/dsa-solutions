
#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;      // Store current occurrence
            right = mid - 1;   // Search left half
        }
        else if (target < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int index = firstOccurrence(arr, n, target);

    if (index != -1)
        cout << "First occurrence found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}