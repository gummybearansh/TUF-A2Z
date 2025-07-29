#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int maximumUniqueSubarray(vector<int> &nums){
    int n = nums.size();
    vector<int> p(n+1, 0);
    for (int i = 0; i < n; i++){
        p[i+1] = p[i] + nums[i];
    }
    int s = 0, ans = 0;
    vector<int> M(10001, -1);
    for (int i = 0; i < n; i++){
        s = max(s, M[nums[i]]+1);
        ans = max(ans, p[i+1] - p[s]);
        M[nums[i]] = i;
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
  
    int ans = maximumUniqueSubarray(v);
    cout << ans;
}

