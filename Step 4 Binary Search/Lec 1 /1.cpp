// implementing lower bound 
// smallest idx in the array such that arr[idx] >= x
#include <iostream>
using namespace std;


// const vector<int> &v => pass me the vector by reference, but do not allow me to change the numbers inside the vector
int lowerBound(const vector<int> &v, int low, int high, int x, int idx){
    // need to find smallest element >= x
    // so just apply binary search to find an element >= x
    // if element is greater, modify search space to left half
    // keep repeating
    if (low > high) {
        return idx;
    }

    int mid = (low + high) / 2;
    // search on left half
    if (v[mid] >= x) return lowerBound(v, low, mid-1, x, mid);
    // if smaller, search on right
    else return lowerBound(v, mid+1, high, x, idx);
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << "Number to find lb of : " << x << endl;
    cout << "Array: ";
    for (auto it: v) cout << it << ' ';
    cout << "\nLower Bound: ";
    cout << lowerBound(v, 0, v.size()-1, x, v.size());
}