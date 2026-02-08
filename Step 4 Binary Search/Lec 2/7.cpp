// LC 1539
// kth Missing positive integer -> in a sorted array, find the 'k'th missing positive integer
// very very good beautiful question
#include <iostream>
using namespace std;

// Optimal TC: O(logN)
// i can find the numbers skipped at each index -> arr[i] - (i + 1) would give me the numbers skipped before i, since i+1 is the actual number that should be there
// i will run a binary search, finding the smallest index where skipped >= k
// after binary search, high points to index where skipped just <k and low points to index where skipped just >= k
// now, high means skipped <k, and low means >=k, so if i can add the k - (missing) numbers to high, i'll get the needed number
int findKthPositive(vector<int> &arr, int k) {
  int n = arr.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    int skipped = arr[mid] - (mid + 1);

    if (skipped >= k) {
      // too many, try to find smaller
      high = mid - 1;
    } else {
      // too few, try to find more
      low = mid + 1;
    }
  }

  // beautiful simplification - see notes
  return low + k;
}

// essentially you're finding the 'k'th element, but if you encounter an element smaller than k in the array, meaning the 'k'th missing is pushed forward by 1
int findKthPositiveBruteSmart(vector<int> &arr, int k) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > k) {
      return k;
    }
    k++;
  }
  return k;
}

// brute -> find k missing numbers in O(n)
int findKthPositiveBrute(vector<int> &arr, int k) {
  int num = 1, idx = 0, count = 0;
  while (idx < arr.size() && num <= INT_MAX) {
    // if num is not present in array, increment count of missing numbers
    if (num != arr[idx]) {
      count++;
      if (count == k)
        return num;
    } else {
      idx++;
    }
    num++;
  }
  while (count < k) {
    num++;
    count++;
  }
  return num;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  cout << findKthPositive(v, k);
}
