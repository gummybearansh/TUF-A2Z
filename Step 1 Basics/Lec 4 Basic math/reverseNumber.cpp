#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;

    int digit, ans = 0;
    while (n > 0){
        digit = n % 10; 
        n /= 10;
        ans *= 10; 
        ans += digit; 
    }
    cout << ans;

    // complexity -> O(log10N) + 1
    // the plus 1 in this and last question is if the number is divisible by 10 from the start 
}
