#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; 

    // what if i reverse it and make it a number and check against the original number 
    int temp = n, rev = 0; 
    while (temp > 0){
        rev = (rev * 10) + temp % 10;
        temp /= 10; 
    }

    if (n == rev) cout << "True palindrome";
    else cout << "False";

    // complexity (Olog10N) + 1 
}

