// max Subarray sum (kadane's algorithm)
#include <iostream>
#include <vector> 
using namespace std;

void kadanesAlgorithm(vector<int> v){
    int n = v.size();
    int sum = 0, maxSum = INT_MIN;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++){
        // keeping track of ansStart and end
        int start;
        if (sum == 0) {
            start = i;
        }
        sum += v[i];
        if (sum > maxSum){
            maxSum = sum; 
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) sum = 0;
    }
    cout << maxSum << " start " << ansStart << " end " << ansEnd << endl;
}

void maxSubarraySumBrute(vector<int> v){
    int maxSum = 0, n = v.size();
    for (int i = 0; i < n; i++){
        int tempSum = 0;
        for (int j = i; j < n; j++){
            tempSum += v[j];
            maxSum = max(maxSum, tempSum);
        }
    } 
    cout << maxSum << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // maxSubarraySumBrute(v);
    kadanesAlgorithm(v);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
