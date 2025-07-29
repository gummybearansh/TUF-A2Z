// Fibonacci (multiple recursion calls)
#include <iostream>
using namespace std;

// see notes for beautiful recursion tree
// time complexity -> O(2^n) (almost, n->2 + n-1->2....) exponential
// space complexity -> O(2^n)
// f(n) = f(n-1) + f(n-2) 
// finding nth fibonacci number
int fib(int n){
    // base cases 
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    for (int i = 1; i < 100; i++){
        cout << fib(i) << endl;
    }
}
