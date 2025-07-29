// Union and Intersection of sorted arrays
#include <iostream>
#include <vector> 
#include <set>
using namespace std;

void sortedIntersectionOptimal(vector<int> &v1, vector<int> &v2){
    int n1 = v1.size(), n2 = v2.size(), i = 0, j = 0;
    vector<int> intersectionResult;
    while (i < n1 && j < n2){
        if (v1[i] == v2[j]){
            intersectionResult.push_back(v1[i]);
            i++; 
            j++;
        }
        else if (v1[i] < v2[j]) i++;
        else j++;
    }

    int n = intersectionResult.size();
    for (int i = 0; i < n; i++){
        cout << intersectionResult[i] << ' ';
    }
    cout << endl;
}

void sortedIntersectionBrute(vector<int> &v1, vector<int> &v2){
    int n1 = v1.size(), n2 = v2.size(); 
    vector<int> intersectionResult, visited(n2, 0);
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if (v1[i] == v2[j] && visited[j] == 0){
                intersectionResult.push_back(v1[i]);
                visited[j] ++;
                break;
            }
            if (v1[j] > v2[i]) break;
        }
    }
    int n = intersectionResult.size();
    for (int i = 0; i < n; i++){
        cout << intersectionResult[i] << ' ';
    }
    cout << endl;
}


void sortedUnionOptimal(vector<int> &v1, vector<int> &v2){
    int n1 = v1.size(), n2 = v2.size(), i = 0, j = 0;
    vector <int> unionResult;
    v1[i] < v2[j] ? unionResult.push_back(v1[i++]) : unionResult.push_back(v2[j++]);
    while (i < n1 && j < n2){
        if (v1[i] < v2[j]){
            if (unionResult.back() != v1[i]){
                unionResult.push_back(v1[i]);
            }
            i++;
        }
        else {
            if (unionResult.back() != v2[j]){
                unionResult.push_back(v2[j]);
            }
            j++;
        }
    }
    while (i < n1) unionResult.push_back(v1[i++]);
    while (j < n2) unionResult.push_back(v1[j++]);

    int n = unionResult.size();
    for (int i = 0; i < n; i++){
        cout << unionResult[i] << ' ';
    }
    cout << endl;
}
void sortedUnionBrute (vector<int> &v1, vector<int> &v2){
    set<int> st;
    int n1 = v1.size(), n2 = v2.size();
    for (int i = 0; i < n1; i++){
        st.insert(v1[i]);
    }
    for (int i = 0; i < n2; i++){
        st.insert(v2[i]);
    }
    vector<int> unionResult;
    int size = st.size();
    for (auto it : st){
        unionResult.push_back(it);
    }
    for (int i = 0; i < size; i++){
        cout << unionResult[i] << ' ';
    }
    cout << endl;
     
}

int main(){
    int n1, n2;
    cin >> n1;
    vector<int> v1, v2;
    for (int i = 0; i < n1; i++){
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++){
        int temp;
        cin >> temp;
        v2.push_back(temp);
    }

    // sortedUnionBrute(v1, v2);
    // sortedUnionOptimal(v1, v2);
    // sortedIntersectionBrute(v1, v2);
    // sortedIntersectionOptimal(v1, v2);

}
