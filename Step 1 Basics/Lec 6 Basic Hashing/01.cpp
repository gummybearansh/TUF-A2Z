// Hashing -> Pre-storing + fetching 
#include <iostream>
#include <vector> 
using namespace std;

// poor hash  -> need hash array size of max element + 1
// in main function -> max int arr -> [1e6] (max bool arr [1e7])
// globally max int array -> [1e7] (max bool arr [1e8])


int main(){
    // size of array and then array input 
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Prestoring (preComputation) -> Creating Hash array to store all frequency of elements of array in 'index' in another hash array
    vector<int> hash(n, 0); // n elements all set to 0
    // populating hash array
    for (int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    // number of queries and then queries 
    int q;
    cin >> q;
    int queries[q];
    for (int i = 0; i < q; i++){
        cin >> queries[i];
    }

    // Fetching (result of queries) 
    for (int i = 0; i < q; i++){
        cout << queries[i] << " occurs " << hash[queries[i]] << " times" << endl;
    }
}
