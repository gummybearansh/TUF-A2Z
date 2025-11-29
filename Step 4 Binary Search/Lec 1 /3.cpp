// finding floor in array
// largest number less thank or equal to x (<= x) (just before = floor) 
// ceil is just lower bound
#include <iostream>
using namespace std;

int floor(const vector<int> &v, int x){
    int low = 0, high = v.size()-1;
    int ans = -1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] <= x){
            // now need to find largest one that's still smaller - elminate left half
            ans = v[mid];
            low = mid + 1;
        } else {
            // otherwise need to find element smaller than x, elminate right half 
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << floor(v, x);
}