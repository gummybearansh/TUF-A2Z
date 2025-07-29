// move zeroes to the end of array
#include <iostream>
#include <vector> 
using namespace std;

void moveZeroesOptimal(vector<int> &v){
    int n = v.size(), i = 0, j = 0;
    // j needs to be at first non-zero element
    while (j < n && v[j] == 0) j++;
    // if array only has 0s (edge case) 
    if (j == n) return;
    for (; j < n; j++){
        if (v[j] != 0){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        } 
    }
}

// store unique elements in new array 
// put non-zero elements back in original
// put remaining 0s in the end
void moveZeroesBrute(vector<int> &v){
    vector<int> temp;
    int vSize = v.size(); 
    for (int i = 0; i < vSize; i++){
        if (v[i] != 0) temp.push_back(v[i]);
    }
    int tSize = temp.size();
    for (int i = 0; i < tSize; i++){
        v[i] = temp[i];
    }
    for (int i = tSize; i < vSize; i++){
        v[i] = 0;
    }
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

    // moveZeroesBrute(v);
    moveZeroesOptimal(v);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
