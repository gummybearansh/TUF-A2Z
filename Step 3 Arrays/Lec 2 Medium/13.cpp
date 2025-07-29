// number of subarrays with sum k
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Prefix sum 
void optimalSubarrayCount(vector<int> &v, int k){
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int n = v.size(), preSum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        preSum += v[i];
        count += mpp[preSum - k];
        mpp[preSum] += 1;
    }
    cout << count << endl;

    for (auto it: mpp){
        cout << it.first << ' ' << it.second << endl;
    }
    cout << endl;
}
// TC: O(N^3) for unoptimized (brute)
// TC: O(N^2) for optimized finding of subarray sum 
// find all subarrays and sum them up 
void bruteBetterSubarrayCount(vector<int> &v, int k){
    int n = v.size();
    int sum = 0, count = 0;
    // finding all subarrays and summing
    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = i; j < n; j++){
            sum += v[j];
            if (sum == k) cout << i << ' ' << j << endl; count ++;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    // bruteBetterSubarrayCount(v, k);
    optimalSubarrayCount(v, k);
}
