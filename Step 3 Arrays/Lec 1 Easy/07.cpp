// linear search
#include <iostream>
#include <vector> 
using namespace std;

// returns first index of element
int linearSearch(vector<int> &v, int n){
    int size = v.size();
    for (int i = 0; i < size; i++){
        if (v[i] == n) return i;
    }
    return -1;
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

    cout << linearSearch(v, 2);

    
}
