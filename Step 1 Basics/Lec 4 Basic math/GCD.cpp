#include <iostream>
using namespace std;

int main(){
    int n1, n2;
    cout << "Enter n1 and n2\n";
    cin >> n1 >> n2;

    // Euciladean algorithm 
    // O(min(a,b,))
    
    while (n1 != 0 && n2 != 0){
        cout << n1 << ' ' << n2 << endl;
        n1 > n2 ? n1 %= n2 : n2 %= n1; 
    }
    n1 == 0 ? cout << n2 : cout << n1; 



    // int smaller; 
    // n1 > n2 ? smaller = n2 : smaller = n1;

    // for (int i = smaller; i > 0; i--){
    //     if (n1 % i == 0 && n2 % i == 0){
    //         cout << "GCD = " << i;
    //         break;
    //     }
    // }
}
