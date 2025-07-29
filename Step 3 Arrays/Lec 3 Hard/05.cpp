// Longest subarray with sum 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// prefix sum hashing 
int longestSubarrayBetter(vector<int> &v){
    int n = v.size(), preSum = 0, maxLen = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        preSum += v[i];
        if (preSum == 0) maxLen = max(maxLen, i+1);
        if (mpp.find(preSum) != mpp.end()){
            maxLen = max(maxLen, i-mpp[preSum]);
        } else {
            mpp[preSum] = i;
        }
    }
    return maxLen;
}

// manually iterate over all subarrays 
int longestSubarrayBrute(vector<int> &v){ 
    int n = v.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += v[j];
            if (sum == 0) maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    // int len = longestSubarrayBrute(v);
    int len = longestSubarrayBetter(v);

    cout << len << endl;
}
