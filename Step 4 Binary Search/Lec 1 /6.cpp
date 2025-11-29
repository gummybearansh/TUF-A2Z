// Search in rotated sorted array
// all unique elements
#include <iostream>
using namespace std;

int findRotatedSortedArray(vector<int> &v, int x){
    int n = v.size();
    int low = 0, high = n-1;
    while (low <= high){
        cout << low << ' ' << high << '\n';
        int mid = (low + high) / 2;
        if (v[mid] == x) return mid;
        // to find out which half to eliminate
        // identify sorted and unsorted half
        else if (v[mid] >= v[low]){
            // meaning if left half is sorted 
            // try to find the number in the sorted half itself
            if (x >= v[low] && x < v[mid]){
                // elminiate right half, if target is in sorted left half
                high = mid - 1;
            }
            // now if the left half is sorted, but the target is smaller than the leftmost, eliminate the left half
            else {
                low = mid + 1;
            }
        }
        // incase right half is sorted
        else if (v[mid] <= v[high]){
            // same two cases, if element is in the sorted half or element is not in the sorted half 
            if (x <= v[high] && x > v[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << findRotatedSortedArray(v, x);
}