// print matrix spiral
#include <iostream>
#include <vector>

using namespace std;

void printSpiral(vector<vector<int>> v){
    int n = v.size(), m = v[0].size();
    int top = 0, left = 0, right = m-1, bottom = n-1;
    while (bottom >= top && right >= left){
        // print left to right
        for (int i = left; i <= right; i++){
            cout << v[top][i] << ' ';
        }
        cout << endl;
        top++;

        // print top to bottom
        for (int i = top; i <= bottom; i++){
            cout << v[i][right] << ' ';
        }
        cout << endl;
        right--;

        // print right to left 
        if (top <= bottom){ // edge case if top exceeds bottom
            for (int i = right; i >= left; i--){
                cout << v[bottom][i] << ' ';
            }
        }
        cout << endl;
        bottom--;

        // print bottom to top
        if (left <= right){ // edge case wehn left exceeds right 
            for (int i = bottom; i >= top; i--){
                cout << v[i][left] << ' ';
            }
        }

        cout << endl;
        left++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    printSpiral(matrix);
}
