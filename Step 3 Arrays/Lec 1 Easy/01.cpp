// largest element of array
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
        cout << v[i] << ' ';
    }
    cout << endl;

    int largest = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] > largest) largest = v[i];
    }
    cout << largest;
}
