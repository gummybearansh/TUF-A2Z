// majority element
#include <iostream>
#include <vector> 
#include <map>
using namespace std;

// optimal -> moores voting algorithm
int mooreVoting(vector<int> v){
    int n = v.size();
    int candidate = v[0], count = 0;
    for (int i = 0; i < n; i++){
        if (count == 0){
            candidate = v[i];
            count ++;
            continue;
        }
        if (v[i] == candidate) count ++;
        else count --;
    }
    if (count) return candidate;
    return -1;
}

// store [element, freq] in map
int majorityBetter(vector<int> v){
    int n = v.size();
    map<int, int> mpp;
    // simple syntax to store [element, freq] in map
    for (int i = 0; i < n; i++){
        mpp[v[i]]++;
    }

    for (auto it : mpp){
        if (it.second > floor(n/2)) return it.first;
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
    // int majority = majorityBetter(v);
    int majority = mooreVoting(v);

    cout << majority;

}
