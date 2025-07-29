// left shift by D places 
// every 'N' shifts -> back to original array
// so need to shift by D % 'N'
#include <iostream>
#include <vector> 
using namespace std;

void leftShiftD(vector<int> &v, int d){
    int n = v.size();
    d = d % n;

    vector<int> temp;
    // need to shift by 3? -> last all except first 3 come front, and then last 3 come in the back
    for (int i = d; i < n; i++){
        temp.push_back(v[i]);
    }
    // then push the first 3 
    for (int i = 0; i < d; i++){
        temp.push_back(v[i]);
    }

    // replace
    for (int i = 0; i < n; i++){
        v[i] = temp[i];
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

    int d = 2;

    leftShiftD(v, d);
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
