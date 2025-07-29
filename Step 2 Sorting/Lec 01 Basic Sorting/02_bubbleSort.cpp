// pushes max to last using adjacent swaps 
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }    

    // Bubble Sort 
    // Time Complexity -> worst/average -> O(N^2)
    // Time Complexity -> best case -> O(n) -> when optimized to check if any swap happened or not (best case when array is sorted)
    // swap adjacent elements; bubbling max to last
    int temp;
    bool didSwap = false;
    for (int i = 0; i < n-1; i++){
        didSwap = false;
        for (int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = true;
            }
        }
        // visualising max bubbling to end 
    for (int j = 0; j < n; j++){
        cout << arr[j] << ' ';
    }
    cout << endl;
        if (!didSwap){
            break;
        }
    }
    // visualising max bubbling to end 
    for (int j = 0; j < n; j++){
        cout << arr[j] << ' ';
    }
    cout << endl;
}

