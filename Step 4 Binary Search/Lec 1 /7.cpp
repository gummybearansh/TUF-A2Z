// Search in rotated sorted array containing duplicates
// only one case to solve on top of problem with unique elements
#include <iostream>
using namespace std;

// TC -> average O(log n)
// worst case -> O(n/2) because if there are a bunch of duplicates [3 3 3 3 1 3 3 3 3 3], you'll have to shrink shrink shrink one at a time 
bool searchInRotatedSortedDuplicates(vector<int> &v, int x){
    int n = v.size();
    int low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] == x) return true;
        // the extra check, to shrink
        // do it before, because removes some valid cases if u do it after
        if (v[mid] == v[low] && v[mid] == v[high]){
            low ++;
            high --;
            continue;
        }
        // left half is sorted, check if target is in the range or not
        if (v[mid] > v[low]){
            if (x >= v[low] && x < v[mid]){
                // eliminate right half, found target in sorted range 
                high = mid - 1;
            }
            else low = mid + 1;
        }
        else {
            // right half is sorted, check if target is in range or not
            if (x > v[mid] && x <= v[high]){
                // target found in range, eliminate left half
                low = mid + 1;
            }
            else high = mid - 1;
        }
    }
    return false;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << searchInRotatedSortedDuplicates(v, x);
}