// check if string is palindrome
#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s, int i, int n){
    // can keep checking first and last index to be equal
    // but how do i return true or false    
    // self derived solution
    // see flow chart on ipad
    if (i >= n / 2) return true;
    if (s[i] != s[n-i-1]) return false; 
    return checkPalindrome(s, i+1, n);
}

int main(){
    string s;
    cin >> s;
    string sWithoutWhitespace = "";
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (isalnum(s[i])) sWithoutWhitespace += (char) tolower(s[i]);
    }
    cout << sWithoutWhitespace << endl;
    n = sWithoutWhitespace.length();
    if (checkPalindrome(sWithoutWhitespace, 0, n)) cout << "Palindrome " << endl;
    else cout << "Not Palindrome" << endl;
}
