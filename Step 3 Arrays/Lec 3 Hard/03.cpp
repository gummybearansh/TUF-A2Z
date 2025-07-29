// Three Sum Problem 
// return all unique triplets that sum up to 0 (cannot take same element more than once: i != j != k) 
#include <iostream>
#include <set>
#include <vector>
using namespace std; 

vector<vector<int>> threeSumBest(vector<int> v){
    int n = v.size(); 
    sort(v.begin(), v.end()); 
    set<vector<int>> st;
    for (int i = 0; i < n; i++){
        if (i>0 && v[i] == v[i-1]) continue;
        int j = i+1, k = n-1; 
        while (j < k){ 
            int sum = v[i] + v[j] + v[k]; 
            if (sum < 0){
                j++;
            }
            else if (sum > 0){
                k--;
            }
            else {
                vector<int> temp = {v[i], v[j], v[k]};
                // no need to sort, array is already sorted 
                st.insert(temp);
                j++;
                while (j < k && v[j] == v[j-1]) j++;
                k--; 
                while (j < k && v[k] == v[k+1]) k--;
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// hashing 
// arr[k] = -(arr[i] + arr[j]) stored in set 
vector<vector<int>> threeSumBetter(vector<int> v){
    int n = v.size(); 
    set<vector<int>> st; 
    for (int i = 0; i < n; i++){
        // new hashset for every i 
        set<int> hashSet;
        // makes sure doesn't return v[i] v[j] from hashSet 
        for (int j = i+1; j < n; j++){
            if (hashSet.find(-(v[i] + v[j])) != hashSet.end()){
                vector<int> temp = {v[i], v[j], -(v[i]+v[j])};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(v[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// find all triplets & sort and store using set 
vector<vector<int>> threeSumBrute(vector<int> v){
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                if (v[i] + v[j] + v[k] == 0){
                    // sort and store it in set 
                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    // don't need to check if already in set - set only stores unique values 
                    // if (st.find(temp) == st.end()){
                    //     st.insert(temp);
                    // }
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    // vector<vector<int>> ans = threeSumBrute(v);
    // vector<vector<int>> ans = threeSumBetter(v);
    vector<vector<int>> ans = threeSumBest(v);
    
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < 3; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
