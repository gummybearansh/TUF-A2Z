// leaders of an array
// right of which every element is smaller 

#include <iostream>
#include <vector> 
using namespace std;

// complexity 
// TC -> O(N) 
// SC -> O(n) worst case -> [5, 4, 3, 2, 1] -> all leaders 
void leader(vector<int> v){
    // if an element is greater than max element on the right of it, it will be greater than all the other elements as well
    // every element greater than max of right of it is a leader
    int n = v.size(), maxi = INT_MIN;
    vector<int> leaders;
    for (int i = n-1; i >= 0; i--){
        if (v[i] > maxi){
            maxi = v[i]; 
            leaders.push_back(v[i]);
        }
    }
    
    for (int i = 0; i < leaders.size(); i++){
        cout << leaders[i] << ' ';
    }
    cout << endl;
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

    leader(v);
}
