// how many times has sorted array been rotated?
#include <iostream>
using namespace std;

int numberOfRotations(vector<int> &v){
    // basically find the index of the min element
    // ideally should be 0 right -> no rotations
    // if its say 2 -> then 0 and 1st index elements have been rotated
    // therefore number of rotations is number of elements before min -> just the index of the min element
    int n = v.size();
    int low = 0, high = n-1;
    int idx = 0;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[low] <= v[mid]){
            if (v[low] < v[idx]){
                idx = low;
            }
            low = mid + 1;
        } else {
            if (v[mid] < v[idx]){
                idx = mid;
            }
            high = mid - 1;
        }
    }
    return idx;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << numberOfRotations(v);
}