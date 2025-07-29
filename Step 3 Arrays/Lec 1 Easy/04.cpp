// Left-Rotate array by 1 place
#include <iostream>
#include <vector> 
using namespace std;

void leftRotate(vector<int> &v){
    int temp = v[0];
    int n = v.size();
    // move all elements back 1 index
    for (int i = 1; i < n; i++){
        v[i-1] = v[i];
    }
    // last element should hold original first element (left shifted)
    v[n-1] = temp;
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

    leftRotate(v); 

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
