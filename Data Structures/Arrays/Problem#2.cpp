// Writing a program to reverse the elements of an array
#include<iostream>
using namespace std;

#define ARRAY_SIZE  7
void reverseArray(int arr[], int size)
 { 
    for(int i = 0, j = size - 1; i < j;i++,j--)
    {
        swap(arr[i], arr[j]);
    
    }
   
 }
void DisplayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[ARRAY_SIZE] = {12, 22, 13, 6, 7, 8, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    DisplayArray(arr, size);

    reverseArray(arr, size);

    cout << "Reversed Array: ";
    DisplayArray(arr, size);

    return 0;
}


//Time Complexitiy = O(n)
//Space Complexitiy = O(1)