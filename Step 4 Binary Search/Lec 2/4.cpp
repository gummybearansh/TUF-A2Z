#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// need to check if it's possible to get m k adjacent flowers that bloom before
// x days
bool check(int x, vector<int> &bloomDay, int m, int k) {
  int countFlower = 0, countBouquet = 0;
  for (int i = 0; i < bloomDay.size(); i++) {
    if (x >= bloomDay[i]) {
      countFlower++;
      if (countFlower == k) {
        countBouquet++;
        countFlower = 0;
      }
    } else
      countFlower = 0;
  }
  return countBouquet >= m;
}

int minDays(vector<int> &bloomDay, int m, int k) {
  int n = bloomDay.size();

  if (bloomDay.size() < m * k)
    return -1;
  // day range -> 1 to max of bloomDay
  // low is initally in the 'false' range -> few days = less flowers blooming.
  // but by the end -> low will go to the true range (enough days to make m
  // bouquets)
  int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());

  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (check(mid, bloomDay, m, k)) {
      // it's possible, but try to find smaller one
      cout << "possible " << mid << '\n';
      ans = mid;
      high = mid - 1;
    } else {
      // it's not possible, increase days so flowers bloom
      low = mid + 1;
    }
  }
  // return low;
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  cout << minDays(v, m, k);
}
