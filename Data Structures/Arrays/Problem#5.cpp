//Finding two numbers that add up to a specific target weight
#include <iostream>
using namespace std;

bool findPair(int arr[], int n, int target) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: "
                     << arr[i] << " and "
                     << arr[j] << endl;
                return true;
            }
        }
    }

    cout << "No pair found" << endl;
    return false;
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    findPair(arr, n, target);

    return 0;
}
//Time Complexity = O(N)
//Space Complexity = O(1)
