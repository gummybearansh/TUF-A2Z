// Find minimum in rotated sorted array
#include <iostream>
using namespace std;

int minInRotatedSortedArray(const vector<int> &v) {
  // we can find the sorted half easily
  // the 'low' of the sorted half - meaning the smallest element of the sorted
  // half will be stored in ans now we don't need to search through the sorted
  // half and we can just eliminate it so look in the other half
  int n = v.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  while (low <= high) {
    int mid = (low + high) / 2;

    // optimization : if rotated portion is crossed then this happens:
    if (v[low] <= v[high]) {
      // meaning entire search space is sorted, so the min in this search space
      // will be v[low]
      ans = min(ans, v[low]);
      break;
    }

    // left half is sorted
    if (v[low] <= v[mid]) {
      ans = min(ans, v[low]);
      // now left half is useless, eliminate it
      low = mid + 1;
    } else {
      // if right half is sorted -> v[mid] is the smallest element
      ans = min(ans, v[mid]);
      // now right half is useless
      high = mid - 1;
    }
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << minInRotatedSortedArray(v);
}
