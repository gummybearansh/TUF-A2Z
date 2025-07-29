// Character hashing 
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();

    // hash -> stores frequency of alphabets 
    // use 26 if lowercase alphabets only
    int hash[256] = {0};
    // each letter can be type casted (int) to an integer
    for (int i = 0; i < n; i++){
        // hash[s[i] - 'a']++;
        hash[s[i]]++;
        //     ^ autocasts char to integer 
    }
    // printing word signature (hash)
    for (int i = 0; i < 256; i++){
        // cout << (char)(i + 'a') << " - " << hash[i] << endl;
        cout << (char)(i) << " - " << hash[i] << endl;
    }
}
