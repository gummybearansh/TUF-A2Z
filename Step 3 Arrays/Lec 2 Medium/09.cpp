// longest consecutive subsequence 
#include <iostream>
#include <vector> 
#include <unordered_set>
using namespace std;

bool linearSearch(vector<int> v, int x);

void longestOptimal(vector<int> v){
    unordered_set<int> st(v.begin(), v.end());
    int longest = 1;
    for (auto it: st){
        // it is start of sequence
        if (st.find(it-1) == st.end()){
            int count = 1;
            int element = it;
            while (st.find(element+1) != st.end()){
                count += 1;
                element += 1;
            }
            if (count > longest) longest = count;
        }
    }
    cout << longest << endl;

}
void longestBetter(vector<int> v){
    sort(v.begin(), v.end());
    int n = v.size(), currentCount = 1, longest = 1, lastSmaller = INT_MIN;
    for (int i = 0; i < n; i++){
        if (v[i] == lastSmaller) continue;
        else if (v[i] == lastSmaller + 1){
            currentCount += 1;
            lastSmaller = v[i];
            if (currentCount > longest) longest = currentCount;
        }
        else {
            lastSmaller = v[i]; 
            currentCount = 1;
        }
    }
    cout << longest << endl;
}

bool linearSearch(vector<int> v, int x){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == x) return true;
    }
    return false;
}

void longestBrute(vector<int> v){
    int n = v.size(), longest = 1;
    for (int i = 0; i < n; i++){
        int count = 1; 
        int element = v[i];
        while (linearSearch(v, element+1) == true){
            element += 1;
            count += 1;
        } 
        if (count > longest) longest = count;
    }
    cout << longest << endl;
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

    // longestBrute(v);
    // longestBetter(v);
    longestOptimal(v);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
