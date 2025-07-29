class Solution {
public:
    // logic is perfect but memory limit exceeded due to recursion xdxd
    
    bool recursivePalindrome(string s, int i, int n){
        if (i >= n/2) return true;
        if (s[i] != s[n-1-i]) return false;
        return recursivePalindrome(s, i+1, n);
    }

    bool isPalindrome(string s) {
        string alphaNumS = "";
        int n = s.length();

        for (int i = 0; i < n; i++){
            if (isalnum(s[i])) alphaNumS += (char) tolower(s[i]);
        }

        n = alphaNumS.length();
        return recursivePalindrome(alphaNumS, 0, n);
    }
};
