// Reverse an Array
#include <iostream> 
using namespace std;

// one pointer only approach
// second pointer will be -> (n - 1 - i)
// but need to pass in size of array anyways... 
// sizeof(arr) will give size of pointer because in c++ arrays can decay into pointers when passing as reference. 
void recursiveReverse(int *arr, int i, int n){
    // base case 
    if (i >= n/2) return;
    // otherwise swap same logic 
    int temp = arr[i];
    arr[i] = arr[n-1-i]; 
    arr[n-1-i] = temp;

    recursiveReverse(arr, i+1, n);
}

// two pointer recursive approach
// passed arr by reference
void recursiveReverseTwoPointer(int *arr, int i, int j){
    // base case    
    if (i >= j) return;
    // otherwise swap element at i and j 
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    // then call recursiveReverse on new indexes
    recursiveReverseTwoPointer(arr, i+1, j-1);
}

int main(){
    int n; 
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "reversing once" << endl;
    recursiveReverseTwoPointer(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << "\nreversing again" << endl;
    recursiveReverse(arr, 0, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
}
