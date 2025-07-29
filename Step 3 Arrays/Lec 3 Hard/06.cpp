// count subarrays w/ XOR k
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// prefix xor logic 
int optimalCount(vector<int> &v, int k){
    int n = v.size();
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int prefixXor = 0, count = 0;
    for (int i = 0; i < n; i++){
        prefixXor ^= v[i];
        // for xor of few elements to end here 
        // there must exist prefixXor ^ k somewhere before 
        if (mpp.find(prefixXor ^ k) != mpp.end()) count += mpp[prefixXor ^ k];
        // increment count of prefixXor if previously found, (increments to 1 if doesn't exist)
        mpp[prefixXor] ++;
    }
    return count;
}

// XOR of all subarrays iteratively
int bruteBetterCount(vector<int> &v, int k){
    int n = v.size(), count = 0;
    for (int i = 0; i < n; i++){
        int XOR = 0;
        for (int j = i; j < n; j++){
            XOR ^= v[j];
            if (XOR == k) count++;
        }
    }
    return count;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    // int count = bruteBetterCount(v, k);
    int count = optimalCount(v, k);

    cout << count << endl;
}
