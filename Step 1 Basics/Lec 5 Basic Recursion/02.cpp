// Sum of first N numbers TC -> O(N); SC -> O(N);
// Factorial of N TC -> O(N); SC -> O(N);
#include <iostream>
using namespace std;

// functional way (very cool);
// break down the problem at every step
// sum(n) is just n + sum(n-1) 
// keep doing that 
// base case -> when n = 0 -> then sum is 0
// beautiful
int fsum(int i){
    if (i < 1) return 0;
    return i + fsum(i-1);
}

// factorial (functional recursion)
int fact(int i){
    if (i == 0) return 1;
    return i * fact(i-1);
}

// factorial (parametrized recursion)
void pfact(int i, int factorial){
    if (i == 0){
        cout << "factorial (param)" << factorial << endl;
        return;
    }
    pfact(i-1, factorial * i);
} 

// parameterized
// recursion tree sum(0, n) -> sum(n, n-1) -> sum(n+n-1, n-2) -> sum(n+n-1+n-2, n-3) ---> sum(n+n-1+n-3...1, 0) and then returns all functions 
void sum(int i, int currSum){
    if (i < 1){
        cout << "sum (param)" << currSum << endl;
        return;
    }
    sum(i-1, currSum + i);
}

int main(){
    int n;
    cin >> n;
    sum(n, 0);

    int summation = fsum(n);
    cout << "sum (fnal)" << summation << endl;

    pfact(n, 1);
    int factorial = fact(n);
    cout << "Factorial (fnal) " << factorial << endl;
}
