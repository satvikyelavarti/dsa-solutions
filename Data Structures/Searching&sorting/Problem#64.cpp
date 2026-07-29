//Ternary Search 
#include<iostream>
#include<vector>
using namespace std;

int TernarySearch(vector<int>arr, int low, int high, int key){
    if(high < low)
    return -1;

int mid1 = low + (high - low) / 3;
int mid2 = high - (high - low) / 3;

 if (arr[mid1] == key) { 
    return mid1; 
 } 
 if (arr[mid2] == key) { 
    return mid2; 
 }

 if (key < arr[mid1]) { 
 return TernarySearch(arr, low, mid1 - 1, key); 
 } 
 else if (key > arr[mid2]) { 
 return TernarySearch(arr, mid2 + 1, high, key); 
 } 
 else { 
 return TernarySearch(arr, mid1 + 1, mid2 - 1, key); 
 } 
}
 int main(){ 
 vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int key = 13; 
    int n = arr.size(); 
    int result = TernarySearch(arr, 0, n - 1, key);
 if (result != -1) { 
cout << "Element " << key << " found at index " << result <<endl; 
 }
 
 else { 
cout << "Element " << key << " not found in the array." <<endl; 
 }
 
 return 0; 
}
