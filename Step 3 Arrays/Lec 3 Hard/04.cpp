// four sum 
// return 4 unique indexes that add up to target 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// two pointer approach while fixing i and j 
vector<vector<int>> fourSumBest(vector<int>&v, int target){
    sort(v.begin(), v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        if (i>0 && v[i] == v[i-1]) continue;
        for (int j = i+1; j < n; j++){
            if (j>i+1 && v[j] == v[j-1]) continue;
            int k = j+1, l = n-1;
            while (k < l){
                long long sum = v[i];
                sum += v[j];
                sum += v[k]; 
                sum += v[l];
                if (sum < target){
                    k++;
                }
                else if (sum > target){
                    l--;
                }
                else {
                    // already sorted array i<j<k<l
                    vector<int> temp = {v[i], v[j], v[k], v[l]};
                    ans.push_back(temp);
                    k++; l--;
                    while (k<l && v[k] == v[k-1]) k++;
                    while (k<l && v[l] == v[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

// Hashing logic (eliminating fourth loop) 
// searching for: target-(v[i] + v[j] + v[k]) in hashset
// TC: O(n^3 * log(m))
// SC: O(n) + 2* O(quads)
vector<vector<int>> fourSumBetter(vector<int> &v, int target){
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            // reset hashset when i moves 
            set<long long> hashSet;
            for (int k = j+1; k < n; k++){
                long long sum = v[i] + v[k];
                sum += v[j];
                long long fourth = target - sum;
                if (hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp = {v[i], v[j], v[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(v[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// iteratively find all quads 
// sort and store them in a set if sum up to target 
// TC: O(n^4), SC: 2*O(unique quads)
vector<vector<int>> fourSumBrute(vector<int> &v, int target){
    int n = v.size(); 
    set<vector<int>> st;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                for (int l = k+1; l < n; l++){
                    // type casting to long long 
                    long long sum = v[i] + v[j];
                    sum += v[k];
                    sum += v[l];
                    if (sum == target){
                        vector<int> temp = {v[i], v[j], v[k], v[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumTrial(vector<int> &v, int target){
    vector<vector<int>> ans;
    int n = v.size();
    if (n < 4) return ans;
    sort(v.begin(), v.end());
    // fixing i position
    for (int i = 0; i < n-3; i++){
        if (i > 0 && v[i-1] == v[i]) continue;
        // early exit -> (4 * smallest fixed) is greater than target 
        if ((long long)v[i] * 4 > target) break; 
        for (int j = i+1; j < n-2; j++){
            if (j > i+1 && v[j-1] == v[j]) continue;
            int k = j+1, l = n-1;
            while (k < l){
                long long sum = (long long) v[i] + v[j] + v[k] + v[l];
                if (sum < target) {
                    k++;
                }
                else if (sum > target){
                    l--;
                }
                else {
                    ans.push_back({v[i], v[j], v[k], v[l]});
                    k++;
                    while (k < l && v[k-1] == v[k]) k++;
                    l--;
                    while (k < l && v[l+1] == v[l]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    // vector<vector<int>> ans = fourSumTrial(v, target);
    // vector<vector<int>> ans = fourSumBrute(v, target);
    // vector<vector<int>> ans = fourSumBetter(v, target);
    vector<vector<int>> ans = fourSumBest(v, target);

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < 4; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
