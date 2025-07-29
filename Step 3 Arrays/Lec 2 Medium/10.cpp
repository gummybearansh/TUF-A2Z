// set Zeroes (to entire row and col where 0 is present)
#include <iostream>
#include <vector> 
#include <unordered_set>
using namespace std;

// Optimal Solution 
void setZeroesOptimal(vector<vector<int>> &v){
         
}

// Better (same as my thought process but better implemented)
// store which row/col has 0 in an arr of that row/col's hash type thing 
// Time Complexity -> O(n*m) + O(n*m)
// Space Complexity -> O(n+m) [two extra arrays]
void setZeroesBetter(vector<vector<int>> &v){
    int n = v.size(), m = v[0].size();
    vector<int> rowIdx (n, 0);
    vector<int> colIdx (m, 0);
    
    // marking which row and col has 0
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == 0){
                rowIdx[i] = 1;
                colIdx[j] = 1;
            }
        }
    }
    
    // mark entire row and col based on mark
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (rowIdx[i] == 1 || colIdx[j] == 1){
                v[i][j] = 0;
            }
        }
    }
    
}

vector<vector<int>> findZero(vector<vector<int>> v){
    vector<vector<int>> ans = {{}, {}};
    int n = v.size(), m = v[0].size();
    // return i and j indexes of all 0s in an array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == 0){
                ans[0].push_back(i);
                ans[1].push_back(j);
            }
        }
    }
    return ans;
}
void setZeroes(vector<vector<int>> &v){
    vector<vector<int>> indexes = findZero(v);
    unordered_set iIndexes(indexes[0].begin(), indexes[0].end());
    unordered_set jIndexes(indexes[1].begin(), indexes[1].end());

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].size(); j++){
            if (iIndexes.find(i) != iIndexes.end() || jIndexes.find(j) != jIndexes.end()){
                v[i][j] = 0;
            }
        }
    }
    
    cout << endl;
}

// Brute -> go over each element and if it's a 0, mark that entire row and col as -1.
// O(n*m)*O(n+m) + O(n*m) // each iteration calls fn that run n and m times 
// roughly n^3 solution 
void setRow(vector<vector<int>> &v, int i){
    for (int j = 0; j < v[0].size(); j++){
        if (v[i][j] != 0) v[i][j] = -1;
    }
}

void setCol(vector<vector<int>> &v, int j){
    for (int i = 0; i < v.size(); i++){
        if (v[i][j] != 0) v[i][j] = -1;
    }
}
void setZeroesBrute(vector<vector<int>> &v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].size(); j++){
            if (v[i][j] == 0){
                setRow(v, i);
                setCol(v, j);
            }
        }
    }

    // now go over it again and mark the -1s as 0s
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].size(); j++){
            if (v[i][j] == -1) v[i][j] = 0;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v = {{0,1,2,0},{3,4,5,2},{1,3,1,5}, {3,2,1,2}};

    // setZeroes(v);
    // setZeroesBrute(v);
    // setZeroesBetter(v);
    setZeroesOptimal(v);

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].size(); j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
