// second largest element of array
#include <iostream>
#include <vector> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // Brute -> Sort, loop from end to find element != largest -> that will be second largest O(NlogN)
    
    // Better -> first pass - find largest, second pass - same comparison but make sure != largest O(2N)

    // Optimal -> O(N)
    int largest = INT_MIN, SLargest = INT_MIN;
    for (int i = 0; i < n; i++){
        if (v[i] > largest){
            SLargest = largest;
            largest = v[i];
        } 
        else if (v[i] > SLargest && v[i] != largest) SLargest = v[i];
    }
    cout << SLargest << ' ' << largest << endl;

    // same logic for second smallest 
    int smallest = INT_MAX, SSmallest = INT_MAX;
    for (int i = 0; i < n; i++){
        if (v[i] < smallest){
            SSmallest = smallest;
            smallest = v[i];
        }
        else if (v[i] != smallest && v[i] < SSmallest) SSmallest = v[i]; 
    }
    cout << SSmallest << ' ' << smallest << endl;

}
