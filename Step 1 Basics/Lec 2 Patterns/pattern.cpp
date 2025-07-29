#include <iostream>
#include <math.h>
using namespace std;

void pattern_1(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern_2(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern_3(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << j << ' ';
        }
        cout << endl;
    } 
}

void pattern_4(int n){
    for (int i = 1; i <= n; i++){
        int k = i;
        for (int j = 1; j <= i; j++){
            cout << k << ' ';
        }
        cout << endl;
    }
}

void pattern_5(int n){
    for (int i = n; i > 0; i--){
        for (int j = i; j > 0; j--){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern_6(int n){
    for (int i = n; i > 0; i--){
        for (int j = 1; j <= i; j++){
            cout << j << ' ';
        }
        cout << endl;
    }
}

// good one
void pattern_7(int n){
    // printing left spaces first (n-1), (n-2), (n-3)...
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < n-i; j++){
            cout << ' ';
        }
        // printing row * 2 - 1 stars 
        for (int j = 1; j <= (i*2)-1; j++){
            cout << "*";
        }
        cout << endl;
    }
    
}

void pattern_8(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j ++){
            cout << ' ';
        }
        for (int j = 1; j <= 2*(n-i) + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

// good ones from here 
void pattern_11(int n){
    int k;
    for (int i = 1; i <= n; i++){
        i % 2 == 0 ? k = 0 : k = 1;
        for (int j = 1; j <= i; j++){
            cout << k << ' '; 
            k = 1-k;
        }
        cout << endl;
    }
}

void pattern_12(int n){
    for (int i = 1; i <= n; i++){
        // print left pyramid 
        for (int j = 1; j <= i; j++){
            cout << j;
        }
        // print spaces in between 
        for (int j = 1; j <= 2*(n-i); j++){
            cout << " ";
        }
        // print right pyramid 
        for (int j = i; j >= 1; j--){
            cout << j;
        } 
        cout << endl;
    }
}

void pattern_13(int n){
    int k = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << k++ << ' ';
        }
        cout << endl;
    }
}

void pattern_14(int n){
    for (int i = 1; i <= n; i++){
        char letter = 'A';
        for (int j = 1; j <= i; j++){
            cout << letter++ << ' ';
        }
        cout << endl;
    }
}

void pattern_17(int n){
    for (int i = 1; i <= n; i++){
        // left spaces 
        char letter = 'A';
        for (int j = 1; j < n-i+1; j++){
            cout << " ";
        }
        // letters
        for (int j = 1; j <= 2*i - 1; j++){
            if (j > i) cout << --letter;
            else if (j < i) cout << letter++;
            else if (j == i) cout << letter;
        }
        cout << endl;
    }
}

void pattern_18(int n){
    for (int i = 1; i <= n; i++){
        char letter = 'A' + n;
        for (int j = i; j >= 1; j--){
            char tempLetter = letter - j;
            cout << tempLetter << ' ';
        }
        cout << endl;
    }
}

void pattern_19(int n){
    // top half
    for (int i = 1; i <= n; i++){
        // top left pyramid
        for (int j = 1; j <= (n-i)+1; j++){
            cout << "*";
        }
        // 2 * row - 1 spaces
        for (int j = 1; j <= 2*(i-1); j++){
            cout << " ";
        }
        // top right pyramid (same);
        for (int j = 1; j <= (n-i)+1; j++){
            cout << "*";
        }
        cout << endl;
    }
    // bottom half
    for (int i = 1; i <= n; i++){
        // bottom left pyramid
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        // 2 * (n-row) spaces
        for (int j = 1; j <= 2 * (n-i); j++){
            cout << " ";
        }
        // bottom right spaces 
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern_20(int n){

    // bottom half
    for (int i = 1; i <= n; i++){
        // bottom left pyramid
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        // 2 * (n-row) spaces
        for (int j = 1; j <= 2 * (n-i); j++){
            cout << " ";
        }
        // bottom right spaces 
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }  
    // top half
    for (int i = 1; i <= n; i++){
        // top left pyramid
        for (int j = 1; j <= (n-i)+1; j++){
            cout << "*";
        }
        // 2 * row - 1 spaces
        for (int j = 1; j <= 2*(i-1); j++){
            cout << " ";
        }
        // top right pyramid (same);
        for (int j = 1; j <= (n-i)+1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern_21(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i==1 || i==n || j==1 || j==n){
                cout << "*";
            }
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern_22(int n){
    for (int row = 0; row < 2*n-1; row++){
        for (int col = 0; col < 2*n-1; col++){
            int top = row;
            int bottom = 2*n - 2 - row;
            int left = col; 
            int right = 2*n - 2 - col;
            cout << n - min(min(top, bottom), min(left, right));
        }
        cout << endl;
    }    
}

int main(){
    int n = 4;

    // pattern_1(n);
    // pattern_2(n);
    // pattern_3(n);
    // pattern_3(n);
    // pattern_4(n);
    // pattern_5(n);
    // pattern_6(n);
    // pattern_7(n); // good one 
    // pattern_8(n);
    // pattern_11(n); // all good ones from here 
    // pattern_12(n);
    // pattern_13(n);
    // pattern_14(n);
    // pattern_17(n); // **
    // pattern_18(n);
    // pattern_19(n);
    // pattern_20(n); // derived form 19
    // pattern_21(n);
    pattern_22(n); // disgusting as fuck sheesh!!
}