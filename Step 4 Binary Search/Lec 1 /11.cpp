// find peak element
#include <iostream>
#include <vector>

using namespace std;

// TC: O(Log N)
int findPeak(vector<int> &v) {
  int n = v.size();

  // edge cases
  if (n == 1)
    return v[0];
  if (v[0] > v[1])
    return v[0];
  if (v[n - 1] > v[n - 2])
    return v[n - 1];

  int low = 1, high = n - 2;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // cout << v[mid - 1] << ' ' << v[mid] << ' ' << v[mid + 1] << '\n';
    // what can mid be?
    // mid can be peak (^)
    if (v[mid - 1] < v[mid] && v[mid] > v[mid + 1]) {
      return v[mid];
    }
    // mid can be part of 'rise' (<<<)
    // already compared both sides once, be smart with comparison
    else if (v[mid] < v[mid + 1]) {
      // peak will be on right if we're part of rise
      // eliminate left half
      low = mid + 1;
      continue;
    }
    // mid can be part of 'fall' (>>>) or can be a low (inverted ^) meaning peak
    // can be either side
    else {
      // if we're in fall, peak is on the left half
      // eliminate right
      high = mid - 1;
      continue;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << findPeak(v);
}
