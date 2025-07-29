// 2 sum 
#include <iostream>
#include <vector> 
#include <map> 
using namespace std;

// sort and greedy
void twoSumBetterVariety1(vector<int> v, int target){
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    bool found = false;
    while (left < right){
        if (v[left] + v[right] == target){
            found = true;
            break;
        }
        else if(v[left] + v[right] > target) right--;
        else left++;
    }
    if (found) cout << "YES";
    else cout << "NO";
}

// add up every two elements and check if sum is target
vector<int> twoSumBrute(vector<int> v, int target){
    int n = v.size(), i = 0, j = 0;
    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
            if (i != j && v[i] + v[j] == target){
                return {i, j};
            }
        }
    }
    return {-1};
}

// store [ele, idx] in a map
// at current element, search for [target - element] in map
vector<int> twoSumBetter(vector<int> v, int target){
    map<int, int> mpp;
    int n = v.size();
    for (int i = 0; i < n; i++){
        if (mpp.find(target-v[i]) != mpp.end()){
            return {i, mpp[target-v[i]]};
        }
        mpp[v[i]] = i;
    }
    return {-1};
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // vector<int> ans = twoSumBrute(v, target);
    // vector<int> ans = twoSumBetter(v, target);
    twoSumBetterVariety1(v, target);

    // for (int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << ' ';
    // }
    // cout << endl;
}
