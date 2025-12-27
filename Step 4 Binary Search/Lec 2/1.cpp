// Find Square root of a number using Binary Search
#include <iostream>

using namespace std;

int squareRoot(int n) {
  // range where root might exist
  int low = 1, high = n, ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // if exceeds -> ans is on left, this value doesn't matter
    // safely check (mid * mid) might overflow
    //(long long)mid * mid > n
    if (mid > n / mid) {
      high = mid - 1;
    }

    else {
      // this value can be the square root, but try finding someone bigger
      // ans = mid;
      low = mid + 1;
    }
  }
  // don't even need ans variable
  // high starts off in a range that cannot be ans
  // low starts off in a range that could possibly be answer
  // when they cross over:
  // high is the ans, low is the value just greater than the ans
  return high;
}

int main() {
  int n;
  cin >> n;
  cout << squareRoot(n);
}
