#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    for (int i = 1; i*i <= n; i--){
        if (i%n == 0){
            cout << "Not prime";
            return 0;
        }
    }
    cout << "Entered number is prime";
}
