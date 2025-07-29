#include <iostream>
#include <map>
#include <vector> 
using namespace std;

// optimal -> XOR TC: O(N), SC: O(1)
// a ^ a = 0
// 0 ^ a = a
// so xor of all pairs = 0, 1 extra element a => a ^ 0 = a
int singleNumberOptimal(vector<int> &v){
    int n = v.size(), XOR = 0;
    for (int i = 0; i < n; i++){
        XOR ^= v[i];
    }
    return XOR;
}

// brute -> loop over numbers, finding another same number, if doesnt exist -> return number

// better -> map with <num, occ>
// if wanted to make own hash -> need array of size maxElement + 1; find element with freq 1 in this 
// find num with 1 occ and return it
// tc -> unorderedmap -> best O(N), worst O(n)
// map -> O(nlogN)
int singleNumberBetter(vector<int> &v){
    unordered_map<int, int> mp;
    int n = v.size();
    for (int i = 0; i < n; i++){
        mp[v[i]]++;
    }
    for (auto it: mp){
        if (it.second == 1) return it.first;
    }
    return -1;
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

    // int num = singleNumberBetter(v);
    int num = singleNumberOptimal(v);
    cout << num;
}
