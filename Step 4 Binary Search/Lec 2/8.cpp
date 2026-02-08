// Aggressive cows
// given an array with coordinates of stalls [0, 3, 4, 7, 9, 10] and number of cows = 4
// arrange the cows in stalls so that the minimum distance between the cows is maximised, what is this distance?
#include <iostream>
using namespace std;

// put the first cow in the first stall and greedily pick the next stall that satisfies the distance
bool canPlace(int distance, vector<int> &stalls, int cows) {
  // first cow automatically placed at 0 index 
  int cCount = 1, lastStall = stalls[0];
  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - lastStall >= distance) {
      cCount++;
      lastStall = stalls[i];
      // it's possible to place these many cows
      if (cCount >= cows)
        return true;
    }
  }
  return false;
}

// TC: O(n log n);
int aggressiveCowsDistance(vector<int> &stalls, int cows) {
  sort(stalls.begin(), stalls.end());
  // binary search on minimum distance possible
  int n = stalls.size();
  // max distance possible -> last stall - first stall (for 2 cows)
  int low = 1, high = stalls[n - 1] - stalls[0];

  while (low <= high) {
    int mid = low + (high - low) / 2;

    // if it's possible, try bigger
    if (canPlace(mid, stalls, cows)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return high;
}

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  cout << aggressiveCowsDistance(v, c);
}
