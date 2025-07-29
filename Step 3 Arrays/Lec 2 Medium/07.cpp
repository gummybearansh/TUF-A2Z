// next Permutation 
#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

// next Permutation
void nextPermutation(vector<int> &v){
    int n = v.size(); 
    // 1. find break point (where dip aka v[i] < v[i+1])
    int dipIdx = -1;
    for (int i = n-2; i >= 0; i--){
        if (v[i] < v[i+1]){
            dipIdx = i;
            break;
        }
    }

    // if no dip -> already lexicographically largest -> need smallest -> sorted or just reverse it 
    if (dipIdx == -1) reverse(v.begin(), v.end());

    // 2. find smallest number greater than v[dipIdx]
    for (int i = n-1; i > dipIdx; i--){
        if (v[i] > v[dipIdx]){
            // swap 
            int temp = v[i];
            v[i] = v[dipIdx];
            v[dipIdx] = temp;
        }
    }

    // 3. reverse remaining array after idx (already descending, need smallest to largest) 
    reverse(v.begin() + dipIdx + 1, v.end());
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

    // next_permutation(v.begin(), v.end());
    nextPermutation(v);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
