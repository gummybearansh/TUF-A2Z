#include <iostream>
using namespace std;

// Replacing outer loop with recursive function calls
void recursiveBubbleSort(int arr[], int range){
    if (range == 1) return;
    for (int i = 0; i < range-1; i++){
        // swapping 
        if (arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    // visualising array after each recursive call
    for (int i = 0; i < range; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    recursiveBubbleSort(arr, range-1);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    recursiveBubbleSort(arr, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
