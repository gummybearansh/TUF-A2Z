// unordered_map
// storing and fetching -> worst case -> O(n) (happens rarely when all keys collide due to bad hash) 
// storing and fetching -> average & best case-> O(1)

// can only have linear ds as key   
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precompute
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    
    // order will change on each run (unordered) 
    for (auto it : mpp){
        cout << it.first << "->" << it.second << endl;
    }
}

// division method hashing
// taking hash array size as 100 or 1000 or .. 
// storing elements on index = num%100 (size of arr)
// chaining if multiple such elements exist 
// ex: arrsize = 10, nums = [1, 2, 22, 3] -> 2 and 22 will chain on the same index -> 2. (can be chained in sorted order so can find out frequency like that in minimal time) 
