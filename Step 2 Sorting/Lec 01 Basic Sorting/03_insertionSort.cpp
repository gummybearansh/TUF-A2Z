// Takes an element and puts it in its right position
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Insertion Sort 
    // Time Complexity -> Worst/Average Case -> O(N^2);
    // Time Complexity -> Best Case -> O(N) (in optimized while loop code) 
    int temp;
    for (int i = 1; i < n; i++){
        int j = i;
        // won't go inside inner loop in best case 
        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }

        // visualising 
        for (int j = 0; j < n; j++){
            cout << arr[j] << ' ';
        }
        cout << endl;
    }
}
