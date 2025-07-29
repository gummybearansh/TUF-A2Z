// Majority element > [n/3] times
#include <iostream>
#include <unordered_map>
using namespace std;

// variation of voting 
vector<int> majorityBest(vector<int> v){
    // max 2 elements can have majority
    int n = v.size();
    vector<int> ans;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++){
        if (count1 == 0 && v[i] != ele2) ele1 = v[i], count1++;
        else if (count2 == 0 && v[i] != ele1) ele2 = v[i], count2++;
        else if (v[i] == ele1) count1 ++;
        else if (v[i] == ele2) count2 ++;
        else count1--, count2--;
    }
    // manually check ele1 and ele2 are actually majority
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == ele1) count1++;
        else if (v[i] == ele2) count2++;
    }
    if (count1 > n/3) ans.push_back(ele1);
    if (count2 > n/3) ans.push_back(ele2);
    return ans;
}

// one pass hashing
// store ele,freq. 
// when freq > n/3, add it to ans.
vector<int> majorityBetter(vector<int> v){
    int n = v.size();
    vector<int> ans; 
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        mpp[v[i]]++;
        if (mpp[v[i]] > n/3) ans.push_back(v[i]);
        if (ans.size() == 2) return ans;
    }
    return ans;
}

// loop over every element, storing count 
// if count > n/3, add to ans
// when over looping, add it to a diff array so don't repeat
vector<int> majorityBrute(vector<int> v){
    int n = v.size();
    vector<int> ans, found;
    for (int i = 0; i < n-1; i++){
        int count = 0;
        bool skip = false;
        for (int j = 0; j < found.size(); j++){
            if (v[i] == found[j]) skip = true;
        }
        if (skip) continue;
        for (int j = i+1; j < n; j++){
            if (v[i] == v[j]) count ++;
        }
        if (count >= n/3) ans.push_back(v[i]);
        if (ans.size() == 2) return ans;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    // vector<int> ans = majorityBrute(v);
    // vector<int> ans = majorityBetter(v);
    vector<int> ans = majorityBest(v);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
}
