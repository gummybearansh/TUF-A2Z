#include <iostream>
#include <vector> 
using namespace std;

int main(){
    int n; 
    cout << "Enter a number: ";
    cin >> n;

    // same method but just use vector and then sort it 
    vector <int> answer; 
    for (int i = 1; i*i <= n; i++){
        if (n%i == 0){
            answer.push_back(i);
            answer.push_back(n/i); 
        }
    }

    sort(answer.begin(), answer.end());
    for(auto it: answer) cout << it << endl;    


    // for (int i = 1; i*i <= n; i++){
    //     if (n%i == 0){
    //         cout << i << ' ' << n/i <<endl;
    //     }
    // }
}
