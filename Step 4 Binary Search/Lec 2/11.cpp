// Minimise Max distance to Gas Station
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(double maxD, vector<int> &stations, int k) {
    int placed = 0;

    for (int i = 0; i < stations.size() - 1; i++) {//n
      // how many do i need to place between this guy and nex
      // that the dist between them is <= maxD
      double dist = (double)stations[i + 1] - stations[i];

      int needed = (int)(dist / maxD);

      // if last station falls exactly on the next station, we don't count it
      if (fmod(dist, maxD) == 0)
        needed--;

      placed += needed;
      if (placed > k)
        return false;
    }

    // did i place them within the given requirement?
    return placed <= k;
  }
  double minMaxDist(vector<int> &stations, int K) {
    int n = stations.size();
    // range of bs: (0 -> max distance in original)
    double low = 0, high = 0;

    for (int i = 1; i < n; i++) {//n
      high = max(high, (double)stations[i] - stations[i - 1]);
    }

    // precision of answer required
    // while (high - low >= 1e-6) {
    for(int i = 0; i < 100; i++){//1
      double mid = low + (high - low) / 2;

      // is it possible to place K stations such that max dist is mid ?
      if (check(mid, stations, K)) {
        // try to find a smaller dist
        high = mid;
      } else {
        low = mid;
      }
    }

    // monotonic [F F F F T T T T] low points to ans
    return low;
  }
};
