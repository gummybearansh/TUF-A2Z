// rotate nxn matrix by 90 degrees 
#include <iostream>
#include <vector> 
using namespace std;

// TC: O(N^2) SC: In place O(1)
void rotateMatrixBetter(vector<vector<int>> &v){
    int m = v.size(), n = v[0].size();
    // TC of this loop O(N/2 * N/2)
    // step 1 - in place transpose: 
    // i -> 0 to n-2
    for (int i = 0; i < n-1; i++){
        // j -> i+1 to n-1
        for (int j = i+1; j < n; j++){
            swap(v[i][j], v[j][i]);
        }
    }

    // TC of this loop (N * N/2)
    // step 2 - reverse all rows 
    for (int i = 0; i < n; i++){
        reverse(v[i].begin(), v[i].end());
    }
}

// BruteForce: TC = O(n^2), SC = O(n^2);
void rotateMatrixBrute(vector<vector<int>> &v){
    int m = v.size(), n = v[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    // [i][j] -> [j][n-1-i]
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans[j][n-1-i] = v[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    // IMPORTANT - 2D matrix input (vectors)
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    // rotateMatrixBrute(matrix);
    rotateMatrixBetter(matrix);
    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
