//Checking if an array is sorted or not  
#include<iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        if (arr[i]>arr[i+1])
            return false;
    }
    return true;    // This statement is outside the for loop because if its inside it wont check all the elements and only check inside one loop 
}

int main()
{
    int arr[] = {1,5,6,4,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    if(isSorted(arr, size) == true)
        cout << "Array is sorted in ascending order";
    else
        cout << "Array is not sorted in ascending order";

    return 0;
}


//Time Complexity = O(N)
//Space Complexity = O(1)