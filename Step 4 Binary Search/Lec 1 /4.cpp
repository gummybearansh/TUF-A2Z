// Find first and last occurrence of number in an array 
#include <iostream>
using namespace std;

pair<int, int> firstAndLastOccurrence(vector<int> v, int x){
    int n = v.size();
    int low = 0, high = n - 1;
    int lb, ub;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] >= x){
            lb = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    // unable to find number in array, no occurrences found
    if (lb == n || v[lb] != x){
        return {0, 0};
    }

    low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (v[mid] > x){
            ub = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return {lb, ub-1};
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    pair<int, int> ans = firstAndLastOccurrence(v, x);
    cout << "First " << ans.first << " Last " << ans.second << '\n';
}