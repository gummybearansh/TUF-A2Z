// find Mth Root of N
// TC: O(log 2 N) * O(M) - to find pow, could be O(log 2 M) if use Pow function
#include <iostream>

#define ll long long

using namespace std;

// returns 1 if mid^m == n
// returns 2 if mid^m > n
// returns 0 if mid^m < n
ll check(ll mid, ll n, ll m) {
  // overflow can become too big, so just return the first iteration that
  // mid^power crosses n
  ll ans = 1;
  for (int i = 1; i <= m; i++) {
    if (ans > n / mid) { // ans * mid > n?? written better
      return 2;
    }
    ans = ans * mid;
  }
  if (ans == n)
    return 1;
  else
    return 0;
}

int findRoot(ll n, ll m) {
  ll low = 1, high = n;
  while (low <= high) {
    ll mid = low + (high - low) / 2;

    // unsafe
    // ll val = pow(mid, m);

    ll val = check(mid, n, m);

    if (val == 1)
      return mid;
    else if (val == 2)
      high = mid - 1;
    else if (val == 0)
      low = mid + 1;
  }
  return -1;
}

int main() {
  ll n, m;
  cin >> n >> m;
  cout << findRoot(n, m);
}
