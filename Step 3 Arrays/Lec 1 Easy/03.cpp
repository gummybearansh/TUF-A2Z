// check if array is sorted
#include <iostream>
#include <vector> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++){
        if (v[i-1] > v[i]) {
            cout << "not sorted";
            return 0;
        }
    }
    cout << "Sorted";
}
