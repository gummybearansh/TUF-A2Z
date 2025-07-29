// Divide and Merge      
#include <iostream>
#include <vector> 
using namespace std;

void merge(int arr[], int low, int mid, int high);
// Merge Sort 
// Time Complexity -> O(NlogN) (log N for division and N for merging each)
// Space Complexity -> O(N) (extra temp array for merging)
// Pseudocode
/* 
    mergeSort(arr, low, high){
        if (low >= high) return;
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    
    merge(arr, low, mid, high){
        i = low, j = mid+1;
        mergedArr = [];
        while (i <= mid && j <= high){
            if (arr[i] < arr[j]){
                mergedArr.push_back(arr[i])
                i++;
            } 
            else {
                mergedArr.push_back(arr[j]);
                j++;
            }
        }  
        while (i <= mid) mergedArr.push_back(arr[i]);
        while (j <= high) mergedArr.push_back(arr[j]);

        for (i = low -> high){
            arr[i] = mergedArr[i - low];
        }
    }
*/

void mergeSort(int arr[], int low, int high){
    if (low >= high) return;
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
}

void merge(int arr[], int low, int mid, int high){
    int left = low, right = mid+1;
    vector<int> temp;
    while (left <= mid && right <= high){
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    } 
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    } 

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
