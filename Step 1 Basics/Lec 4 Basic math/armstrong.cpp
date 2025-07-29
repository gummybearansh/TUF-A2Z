#include <iostream>
using namespace std;

int main(){
    // sum of digits raised to the power of number of digits 

    // first find number of digits 
    int n; 
    cout << "Enter a number\n"; 
    cin >> n;
    
    int numOfDigits = 0, temp = n; 
    while (temp > 0){
        numOfDigits ++; 
        temp /= 10; 
    }
    cout << "Number of digits = " << numOfDigits << endl;

    temp = n;
    int armstronged = 0, digit, digitPowered;
    while (temp > 0){
        digit = temp % 10;
        temp /= 10;
        digitPowered = 1;
        for (int i = 0; i < numOfDigits; i++) {
            digitPowered *= digit;
        }
        armstronged += digitPowered;
    }
    cout << "Armstronged = " << armstronged << endl;;
    armstronged == n ? cout << "yes armstrong" : cout << "not armstrong";
}
