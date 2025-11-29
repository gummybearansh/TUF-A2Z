// Count number of occurrences 
// Solved using raw binary search solution, not lb ub implementation
#include <iostream>
using namespace std;

int numberOfOccurrences(vector<int> &v, int x){
    int n = v.size();
    int low = 0, high = n-1;
    int firstOccurrence = n;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] == x){
            // found, but try to find first occurrence
            firstOccurrence = mid;
            high = mid - 1;
        }
        else if (v[mid] > x) high = mid - 1;
        else low = mid + 1; 
    }
    if (firstOccurrence == n || v[firstOccurrence] != x){
        return -1;
    }

    int lastOccurrence;
    low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] == x){
            // found, but try to find last (more ahead)
            lastOccurrence = mid;
            low = mid + 1;
        }
        else if (v[mid] < x) low = mid + 1;
        else high = mid -1; 
    }
    cout << firstOccurrence << ' ' << lastOccurrence << '\n';
    return lastOccurrence - firstOccurrence + 1;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int num = numberOfOccurrences(v, x);
    cout << num << '\n';
}