// LC410 Split Array Largest Sum
// + Painters Parition (same solution)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  typedef long long ll;

private:
  bool check(int maxSum, vector<int> &nums, int k) {
    // is it possible to make subarrays with max sum k
    ll currSum = 0, count = 1;
    for (int n : nums) {
      if (currSum + n <= maxSum) {
        currSum += n;
      } else {
        currSum = n;
        count++;
      }
    }

    // if i was able to create <= k subarrays (less than because say the max subarray sum we needed was so big that we did it in just 1 or 2 subarrays)
    return count <= k;
  }

public:
  int splitArray(vector<int> &nums, int k) {
    // need to minimise the largest sum
    // monotonic -> if i can make the max subarray sum = x, then i can also make it x+1, x+2 (i'll just add more elements to it)
    // but i also need to make sure tha max subarray sum is x with the subarray count being k - meaning in my check function - i need to track how many subarrays it took me to make the max subarray sum < x -> if it's >k (meaning the subarray sum is too less, i need more elements in each subarray so i can make exactly k)

    // range of BS -> minimum sum => max element
    // maximum sum -> entire array sum
    ll low = *max_element(nums.begin(), nums.end());
    ll high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high) {
      ll mid = low + (high - low) / 2;

      if (check(mid, nums, k)) {
        // it's psosible to create k or fewer subarrays with max subarray sum k
        // so try to find a smaller subarray sum
        high = mid - 1;
      } else {
        // it's not possible, i need to increase my sum
        low = mid + 1;
      }
    }

    // monotonic [F F F T T T] (low points to the first T now)
    return low;
  }
};
