// find minimum divisor given a threshold
#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

bool check(int divisor, vector<int> &v, int threshold) {
  ll sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += (v[i] + divisor - 1 / divisor);
    if (sum > threshold)
      return false;
  }
  return threshold >= sum;
}
int minDivisor(vector<int> &v, int threshold) {
  int low = 1, high = *max_element(v.begin(), v.end());
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid, v, threshold)) {
      // valid, but try to find smaller
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int main() {
  int n, threshold;
  cin >> n >> threshold;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  cout << minDivisor(v, threshold);
}
