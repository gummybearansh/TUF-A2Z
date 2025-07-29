// Print one to N and N to one using recursion TC -> O(N); SC -> O(N);
#include <iostream>
using namespace std;

// recursion -> a function calling itself until a specific condition is met 
// see segf for stackoverflow (segmentation fault) 
// a function is completed when it's last line is executed or it is 'returned' 
void oneToN(int n){
    // base case 
    // return when 1
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    // whatever N this initial function was called with is not completed
    // it will wait in the stack for oneToN(n-1) to complete 
    // only then it can print the bigger 'n'.

    oneToN(n-1);
    // prints current n after all smaller Ns are printed
    cout << n << endl;
}

void NtoOne(int n){
    // printing n as it comes (biggest first)
    cout << n << endl;
    // base case 
    if (n == 1) return;
    // function calling itself 
    NtoOne(n-1);
}

int main(){
    int n;
    cin >> n;
    // oneToN(n);
    NtoOne(n);
    return 0;
}
