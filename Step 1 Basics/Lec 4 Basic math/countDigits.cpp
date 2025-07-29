#include <iostream>
#include <math.h> 
using namespace std;

int main(){
    int n; 
    cin >> n; 

    // AAM ZINDAGI
    // int numOfDigits = 0; 
    // while (n > 0){
    //     numOfDigits ++; 
    //     n /= 10; 
    // }

    int numOfDigits = (int) (log10(n)+1);
    cout << numOfDigits << endl;

    // time complexity -> O(log10n) + 1
    // we divide n by 10 until it reaches 0 which takes log10N iterations
}
