#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i = low, j = mid+1;
    vector<int>temp;
    while (i <= mid && j <= high){
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (j <= high) temp.push_back(arr[j++]);
    while (i <= mid) temp.push_back(arr[i++]);

    for (int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high){
    // base case of recursion
    if (low == high) return; 
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);

    for (int i = low; i <= high; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    // for (int i = 0; i < n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;
}
