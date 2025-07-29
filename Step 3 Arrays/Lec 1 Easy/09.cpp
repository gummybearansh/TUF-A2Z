#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

// optimal (sum)
int missingNumberOptimal(vector<int> &v){
    int n = v.size() + 1;
    int desiredSum = n * (n + 1) / 2, actualSum = 0;
    n--;

    for (int i = 0; i < n; i++){
        actualSum += v[i];
    }
    
    return desiredSum - actualSum;
}

int missingNumberOptimalXOR(vector<int> &v){
    int n = v.size();
    int XOR1 = 0;
    // for (int i = 1; i <= n+1; i++){
    //     XOR1 ^= i;
    // }    
    // trying to XOR1 in this loop itself
    int XOR2 = 0;
    for (int i = 0; i < n; i++){
        XOR1 ^= i+1;
        XOR2 ^= v[i];
    }
    XOR1 ^= n+1;
    cout << "XOR1: " << XOR1 << endl;
    cout << "XOR2: " << XOR2 << endl;
    return XOR1 ^ XOR2;
}

// brute -> linear search every number and find missing one in array O(N^2)

// better -> create a hash (array that marks elements as present or not) to find missing elemnt TC: O(N), SC: O(N);
int missingNumberBetter(vector<int> &v){
    int n = v.size();
    // actual hash needs to be of full array (+1 beacuse counting numbers from 1)
    vector<int> hash(n+2, 0);
    for (int i = 0; i < n; i++){
        hash[v[i]]++;
    }

    // visualize hash
    for (int i = 0; i < n+2; i++){
        cout << hash[i] << ' ';
    }
    cout << endl;

    int i = 1;
    while (i < n+2){
        if (hash[i] != 1) break;
        i++;
    }
    return i;
}

// optimal -> sort and find missing number
int missingNumberNlogN(vector<int> &v){
    int n = v.size();
    sort(v.begin(), v.end());
    int j = 1;

    for (int i = 0; i < n; i++){
        if (v[i] != j) break;
        j++;
    }
    return j;
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

    // int missing = missingNumberNlogN(v);
    // int missing = missingNumberBetter(v);
    // int missing = missingNumberOptimal(v);
    int missing = missingNumberOptimalXOR(v);

    cout << missing;
}
