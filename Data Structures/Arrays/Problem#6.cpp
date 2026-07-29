//Rotating array right by K steps
#include <iostream>
#include <algorithm>
using namespace std;

void rotateRight(int arr[], int n, int k) {
    k = k % n;  // Handle cases where k > n

    // Reverse entire array
    reverse(arr, arr + n);

    // Reverse first k elements
    reverse(arr, arr + k);

    // Reverse remaining elements
    reverse(arr + k, arr + n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateRight(arr, n, k);

    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}