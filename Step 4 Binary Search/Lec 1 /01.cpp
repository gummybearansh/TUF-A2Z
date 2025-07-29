// Binary Search -> When search space is Sorted (can be any DS)
#include <iostream>
#include <vector>
using namespace std;

int BinarySearchRecursive(vector<int> v, int target, int low, int high){
    for (int i = low; i <= high; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
    // base case 
    if (low > high) return -1;
    int mid = (high+low)/2;
    if (v[mid] > target) return BinarySearchRecursive(v, target, low, mid-1);
    else if (v[mid] < target) return BinarySearchRecursive(v, target, mid+1, high);
    else return mid;
    return 0;
}
int BinarySearchIterative(vector<int> v, int target){
    int n = v.size();
    int low = 0, high = n-1;
    while (low <= high){
        for (int i = low; i <= high; i++){
            cout << v[i] << ' ';
        }
        cout << endl;
        int mid = (low + high)/2;
        if (v[mid] == target) return mid;
        else if (v[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int target = 1;
    int idx = BinarySearchRecursive(v, target, 0, n-1);
    cout << "Idx: " << idx;
}
