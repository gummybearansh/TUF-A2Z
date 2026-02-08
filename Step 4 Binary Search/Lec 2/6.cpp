// LC 1011
// capacity to ship packages within D days
// given weights of products, what is the minumum weight u load into the ship each day to ship all products
#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool check(int max_capacity, vector<int> &weights, int days) {
  // add weights to the ship till they're under max capacity.
  ll filled = 0, d = 1;
  for (int i = 0; i < weights.size(); i++) {
    filled += weights[i];
    if (filled > max_capacity) {
      d++;
      if (d > days)
        return false;
      filled = weights[i];
    }
  }
  return d <= days;
}

// Monotonic -> if i can finish within D days with x capacity, then obviously i can do it with >x capacity
// range of x: 1 to max element (would do it within arr.size() days)
int shipWithinDays(vector<int> &weights, int days) {
  int n = weights.size();
  int mxW = INT_MIN, smW = 0;

  for (int w : weights) {
    mxW = max(mxW, w);
    smW += w;
  }

  // low => max element => need to carry atleast all elements done in n days
  // high => sum of all elements => done in 1 day
  int low = mxW, high = smW;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // is it possible to load with max capacity mid?
    // if yes, then try to find smaller
    if (check(mid, weights, days)) {
      ans = mid;
      high = mid - 1;
    } else {
      // not possible, increase capacity
      low = mid + 1;
    }
  }

  return ans;
}

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  cout << shipWithinDays(v, d);
}
