// Quick Sort -> divide and conquer
// Time Complexity -> O(NlogN) (same as merge sort)
// Space Complexity -> O(1) (but uses stack space)
#include <iostream>
using namespace std;

// Step 1 - pick a pivot and place it in it's right place 
//                  -> can be first, median, last, random element doesnt matter 
// Step 2 - smaller on the left and larger on the right  
// see ipad for pseudocode and dry run 
int helper(int arr[], int low, int high);

void quickSort(int arr[], int low, int high){
    if (low >= high) return;
    int partitionIndex = helper(arr, low, high);
    quickSort(arr, low, partitionIndex-1);
    quickSort(arr, partitionIndex+1, high);
}

int helper(int arr[], int low, int high){
    int pivot = arr[low], i = low, j = high;
    while(i < j){
        while(arr[i] <=  pivot && i < high) i++;
        while(arr[j] > pivot && j > low) j--;
        if (i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    
    return j;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
