#include <iostream>
#include <vector> 
using namespace std;

void rearrangeVariety(vector<int> &v){
    int n = v.size(); 
    // filling +ves and -ves in separate arrays
    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if (v[i] > 0) pos.push_back(v[i]);
        else neg.push_back(v[i]);
    }

    int posSize = pos.size(), negSize = neg.size();
    // two cases
    if (posSize < negSize){
        for (int i = 0; i < posSize; i++){
            v[2*i] = pos[i];
            v[2*i+1] = neg[i];
        }
        // now filling in remaining -ve numbers 
        int nextIdx = 2*posSize;
        for (int i = posSize; i < negSize; i++){
            v[nextIdx] = neg[i];
            nextIdx++;
        }
    }
    else {
        for (int i = 0; i < negSize; i++){
            v[2*i] = pos[i];
            v[2*i+1] = neg[i];
        }
        // filling in remaining +ve numbers 
        int nextIdx = 2*negSize;
        for (int i = negSize; i < posSize; i++){
            v[nextIdx] = pos[i];
            nextIdx++; 
        }
    }
}

// store in correct place in an ans array
void rearrangeOptimal(vector<int> &v){
    int n = v.size();
    vector<int> ans(n);
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < n; i++){
        if (v[i] > 0) {
            ans[posIdx] = v[i];
            posIdx += 2;
        }
        else {
            ans[negIdx] = v[i];
            negIdx += 2;
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

void rearrangeBrute(vector<int> &v){
    int n = v.size();
    vector<int> pos, neg; 
    for (int i = 0; i < n; i++){
        if (v[i] > 0) pos.push_back(v[i]);
        if (v[i] < 0) neg.push_back(v[i]);
    }
    
    // positive elements at [0, 2, 4...] indexes 
    // negative elements at [1, 3, 5...] indexes
    for (int i = 0; i < n/2; i++){
        v[2 * i] = pos[i];
        v[2 * i + 1] = neg[i];
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

    // rearrangeBrute(v);
    // rearrangeOptimal(v);
    rearrangeVariety(v);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
