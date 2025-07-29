#include <iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int i, int n){
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }

    recursiveInsertionSort(arr, i+1, n);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    recursiveInsertionSort(arr, 0, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
