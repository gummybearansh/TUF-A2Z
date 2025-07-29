// Example for Stack Overflow - when recursion (function calls itself) without base case
#include <iostream>
using namespace std;

void print1(){
    cout << 1 << endl;
    print1();
}

int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    print1();
}
