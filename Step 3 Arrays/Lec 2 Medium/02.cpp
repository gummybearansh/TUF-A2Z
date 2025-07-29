// sort 0s 1s and 2s

#include <iostream>
#include <vector> 
using namespace std;


void dutchNationalFlag(vector<int> &v){
    int n = v.size();
    int low = 0, mid = 0, high = n-1;
    while (mid <= high){
        if (v[mid] == 0){
            // swap low and mid and incrememnt both
            int temp = v[low];
            v[low] = v[mid];
            v[mid] = temp;
            mid ++;
            low ++;
        }
        else if (v[mid] == 1){
            // correct place, increment mid
            mid ++;
        }
        else if (v[mid] == 2){
            // put it at correct place (high) and decrement high
            int temp = v[mid];
            v[mid] = v[high];
            v[high] = temp;
            high--;
        }

        // visualizing v at every iteration 
        for (int i = 0; i < n; i++){
            cout << v[i] << ' ';
        }
        cout << endl;
    }
}

void sort012Better(vector<int> &v){
    vector<int> hash(3, 0);
    int n = v.size();
    for (int i = 0; i < n; i++){
        hash[v[i]]++;
    }
    v.clear();
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < hash[i]; j++){
            v.push_back(i);
        }
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

    // sort012Better(v);
    dutchNationalFlag(v);

    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

