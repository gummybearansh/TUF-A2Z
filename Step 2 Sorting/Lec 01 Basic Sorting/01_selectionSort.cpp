// Select minimums and swap 
// [13, 46, 24, 52, 20, 9]
// min -> 9, swap with first index 
// [9, _ 46, 24, 52, 20, 13]
// min -> 13, swap with second index
// [9, 13 _ 24, 52, 20, 46]
// min -> 24 ...

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Selection Sort 
    // Time Complexity -> O(N^2)
    // Space Complexity -> O(1)
    int minIdx, temp;
    for (int i = 0; i < n; i++){
        minIdx = i;
        for (int j = i; j < n; j++){
            // find min 
            if (arr[j] < arr[minIdx]) minIdx = j; 
        }
        // swap min with ith index
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        // to visualise array after each swap 
        for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
        }
        cout << endl;
    }


}
