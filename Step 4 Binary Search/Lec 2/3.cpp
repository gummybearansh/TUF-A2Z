#include <iostream>
#include <vector>

using namespace std;

bool check(int k, vector<int> &v, int h) {
  // go over the piles -> find how many hours it will take
  int hours = 0;
  for (int i = 0; i < v.size(); i++) {
    // can't use ceil here directly -> int division value is truncated
    // automatically
    
    hours += ceil((double)v[i] / k);
    // kavi kya kehna chahte hai?
    // (piles[i] + k - 1) / k;
    if (hours > h) {
      cout << hours << '\n';
      return false;
    }
  }
  return hours <= h;
}

int hours(vector<int> &v, int h) {
  int n = v.size();

  // banana eating speed / hour (k)  can be in range 1 -> 1e9
  // try to take that k and find how many hours it will take on n
  // if hours > h -> too slow, increase speed - eliminate left half
  // if hours < h -> fast enough, but try to find minimu -> eliminate right half
  int low = 1, high = 1e9;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (check(mid, v, h)) {
      // this is a valid height -> k might be answer but try to find minimum
      cout << "valid " << mid << '\n';
      ans = mid;
      high = mid - 1;
    } else {
      // too slow -> speed up
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  int n, h;
  cin >> n >> h;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << hours(v, h);
}
