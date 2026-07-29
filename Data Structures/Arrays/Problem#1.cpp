//Finding Maximum and Minimum and also the size of array.

#include<iostream>
using namespace std;
void findMax(int arr[],int size)   // Size is gonna be called from the main where we will pass the size along with the array.
{
    int max = arr[0]; 
    for(int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << "Maximum Element: "<< max << endl;
}


void findMin(int arr[], int size )
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    cout << "Minimum Element: "<< min << endl;
}

int main()
{
    int arr[] = {12,4,17,3,2,20};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Size of Array: "<< size << endl;
    
    findMax(arr, size);
    findMin(arr, size);
    return 0;
}


//Time Commplexity = O(N)
//Space Complexity = O(1)
