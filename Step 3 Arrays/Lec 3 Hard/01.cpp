// Pascal's triangle

#include <iostream>
#include <vector>

using namespace std;

vector<int> findRow(int row);
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++){
        vector<int> row = findRow(i);
        ans.push_back(row);
    }
    return ans;

}
// optimized finding row 
// TC = O(RowSize);
vector<int> findRow(int row){
    vector<int> ans(row);
    ans[0] = 1;
    ans[row-1] = 1;
    for (int col = 1; col < row-1; col++){
        int temp = ans[col-1] * (row - col) / (col);
        ans[col] = temp;
    } 
    return ans;
}

// optimised NCR calculation 
// TC -> O(r) 
// SC -> O(1);
int funNcR(int n, int r){
    int res = 1;
    for (int i = 0; i < r; i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j < n-i; j++){
    //         cout << ' ';
    //     }
    //     for (int j = 1; j <= i; j++){
    //         cout << funNcR(i-1, j-1) << ' ';
    //     }
    //     cout << endl;
    // }

    // vector<int> row = findRow(n);
    vector<vector<int>> ans = pascalTriangle(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            cout << ' ';
        }
        for (int j = 0; j <= i; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    
}
