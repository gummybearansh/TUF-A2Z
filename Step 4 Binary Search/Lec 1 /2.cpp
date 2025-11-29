// finding upper bound
// smallest index in array such that arr[idx] > x

#include <iostream>
using namespace std;

int upperBound(const vector<int> &v, int low, int high, int x, int idx){
    if (low > high) return idx;

    int mid = (low + high) / 2;

    // if greater already, then elminiate right search space
    if (v[mid] > x) return upperBound(v, low, mid-1, x, mid);
    // otherwise elminate left search space (smaller)
    else return upperBound(v, mid+1, high, x, idx);
}

int upperBoundItertive(const vector<int> &v, int x){
    int low = 0, high = v.size()-1;
    int idx = v.size();
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] > x) {
            // need to find smallest that's > 
            // so search in left half
            idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Upper Bound: ";
    cout << upperBound(v, 0, v.size()-1, x, v.size()); 
    cout << "\nUpper Bound Iterative: ";
    cout << upperBoundItertive(v, x);
}