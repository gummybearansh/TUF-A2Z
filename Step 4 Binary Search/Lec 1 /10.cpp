// find single element in sorted array
#include <iostream>
#include <vector>

using namespace std;

// TC:= O(log N)
int findSingleElement(vector<int> &v) {
  int n = v.size();

  // edge cases - single or 1st and last element
  if (n == 1)
    return v[0];
  if (v[0] != v[1])
    return v[0];
  if (v[n - 1] != v[n - 2])
    return v[n - 1];

  // now can check 1 to n-2 to avoid boundary checks
  int low = 1, high = n - 2;

  while (low <= high) {
    // int mid = (low + high) / 2;
    // better way for mid = saves from large test cases (think)
    int mid = low + (high - low) / 2;

    // is mid the single element?
    if (v[mid] != v[mid - 1] && v[mid] != v[mid + 1]) {
      return v[mid];
    }

    // (e, o) => before single
    // (o, e) => after single
    // region before single:
    //  -- if mid is even -> then pair will be next
    //  -- if mid is odd -> pair will be previous one

    // XOR USAGE
    // index ^ 1
    //
    // if index is odd -> it subtracts one
    // if index is even -> it adds one
    //
    // and ideally in a pair wise fashion - the index is supposed to be even,
    // odd, even, odd
    //
    // 0 ^ 1 = 1 (in correct sequence pair of element at index 0 should be at 1)
    // 1 ^ 1 = 0 (pair of element at index 1 should be at 0)
    //
    // 5 ^ 1 = 4 (pair of element at index 5 should be at 4)
    // 4 ^ 1 = 5 ( pair of element at index 4 should be at 5)
    //
    // if it is true - if the element exists at index ^ 1 => then we're on the
    // left half of the single element = eliminate left side
    //
    // if it is not true = the sequence has been shifted => we're on the right
    // side => eliminate right half
    //
    if (v[mid] == v[mid ^ 1]) {
      // we're on the left half
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    // if ((mid % 2 == 0 && v[mid] == v[mid + 1]) ||
    //     (mid % 2 == 1 && v[mid] == v[mid - 1])) {
    //   // we are in left half (before single)
    //   // eliminate left half
    //   low = mid + 1;
    // } else {
    //   // we are in right half (after single)
    //   // eliminate right
    //   high = mid - 1;
    // }
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

  cout << findSingleElement(v);
}
