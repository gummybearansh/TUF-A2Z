#include <iostream>
#include <vector> 
using namespace std;

int maxConsecutiveOnes(vector<int> &v){
    int n = v.size(), count = 0, max = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == 1) count++;
        else count = 0;

        if (count > max) max = count;
    }
    return max;
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

    int max = maxConsecutiveOnes(v);
    cout << max;
}
