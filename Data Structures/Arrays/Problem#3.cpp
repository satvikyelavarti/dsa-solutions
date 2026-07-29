//Finding the number of times a target element occurs in a array
#include <iostream>
using namespace std;



void countOccurrences(int arr[], int size, int target)
{
    int count = 0;                 // Start count at 0

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target) 
            count++;
    }

    cout << target << " appears " << count << " times." << endl;
}

int main()
{
    int arr[] = {3, 2, 3, 2, 4, 2, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target element: ";
    cin >> target;

    countOccurrences(arr, size, target);

    return 0;
}

//Time Complexity = O(N)
//Space Complexity = O(1)
