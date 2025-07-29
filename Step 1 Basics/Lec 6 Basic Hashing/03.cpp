// map 
// stores all values in sorted order (based on keys) 
// storing and fetching from map takes O(LogN) (worst, average and best case all)

// can have any ds in key (pair, vector etc)
#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // hashing using map 
    // map <number, frequency>
    map<int, int> mpp;
    for (int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    for (auto p : mpp){
        cout << p.first << "->" << p.second << endl;
    }
    
}
