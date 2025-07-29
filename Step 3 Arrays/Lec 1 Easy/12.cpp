// Longest subarray with sum k (array only has positives) 
#include <iostream>
#include <vector> 
#include <map>
using namespace std;

void subarraySumOptimal(vector<int> v, int k){
    int left = 0, right = 0, sum = v[0], maxLen = 0, n = v.size(); 

    while (right < n){
        // if sum is too big -> shrink from left
        while (left <= right && sum > k){
            sum -= v[left]; 
            left++;
        }
        // if sum is perfect, check length
        if (sum == k){ 
            maxLen = max(maxLen, right-left+1);
        }
        // move right forward (expand window) 
        right++;
        if (right < n) sum += v[right]; 
    }
    cout << maxLen << endl;
}

void subarraySumBetter(vector<int> v, int k){
    map<int, int> preSumMap;
    int n = v.size(), preSum = 0, maxLen = 0;
    for (int i = 0; i < n; i++){
        preSum += v[i];
        if (preSum == k) maxLen = max(maxLen, i+1);
        int rem = preSum - k;
        if (preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len); 
        }
        if (preSumMap.find(preSum) == preSumMap.end()) {
            preSumMap[preSum] = i; 
        }
    }
    cout << maxLen << endl;
}

// slightly better TC -> O(N^2) SC -> O(1)
// running sum of subarrays, if equal to k, compare with maxLength
void subarraySumOptimizedBrute(vector<int> v, int k){
    int n = v.size(), maxLength = 0;
    for (int i = 0; i < n; i++){
        int tempSum = 0;
        // all subarrays -> [i, n] -> sum compared on the way
        for (int j = i; j < n; j++){
            tempSum += v[j]; 
            cout << "sum " << tempSum << " i " << i << " j " << j << endl;
            if (tempSum == k) maxLength = max(maxLength, j-i+1);
        }
    }
    cout << maxLength;
}


// custom comparation for descending sort
bool comp(int a, int b){
    return a > b;
}
// BRUTE -> O(n^3) SC -> O(X) where x is number of subarrays with sum k
// generate all subarrays 
// sum = k -> store size
// return max size 
void subarraySumBrute(vector<int> v, int k){
    int n = v.size();
    vector<int> subarrayLength;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            // [i, j] -> is a subarray
            int tempSum = 0;
            for (int a = i; a <= j; a++){
                tempSum +=  v[a];
            }
            if (tempSum == k){
                cout << "sum " << tempSum << " i " << i << " j " << j << endl;
                subarrayLength.push_back(j-i+1);
            }
        }
    }
    // find max using loop or sorting
    sort(subarrayLength.begin(), subarrayLength.end(), comp);
    for (int i = 0; i < subarrayLength.size(); i++){
        cout << subarrayLength[i] << ' ';
    }
    cout << endl;
    cout << subarrayLength[0] << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // subarraySumBrute(v, k);
    // subarraySumOptimizedBrute(v, k);
    // subarraySumBetter(v, k);
    subarraySumOptimal(v, k);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
