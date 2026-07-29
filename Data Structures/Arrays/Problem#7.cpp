//Moving zeroes to the end of an array while maintaining the order of non zero elements
#include<iostream>
using namespace std;
void MovingZeroes(int arr[],int size)
{
    int j = 0;    //Here j keeps track of the non zero element 
    for (int i = 0;i < size; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << "->";
    cout << endl;
}

int main()
{
    int arr[] = {0, 0, 0, 3, 0, 4, 6,0,9,0,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    MovingZeroes(arr, size);

    display(arr, size);

    return 0;
}


//Time Complexity = O(N)
//Space Complexity = O(1)