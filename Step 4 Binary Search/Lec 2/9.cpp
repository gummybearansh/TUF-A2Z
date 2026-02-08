// Allocate books
#include <bits/stdc++.h>
using namespace std;

bool check(int max_pages, vector<int> &pages, int students) {
  int s = 1, n = pages.size(), sum = 0;

  for (int i = 0; i < n; i++) {
    if (sum + pages[i] <= max_pages) {
      sum += pages[i];
    } else {
      // one more student needed
      // start next student with these pages
      sum = pages[i];
      s++;
    }
  }
  // if i can fit fewer means i can definitely fit the required amount
  return s <= students;
}

// need to minimise the "maximum" pages a student gets
int allocate_pages(vector<int> &pages, int students) {
  // binary search on "max" pages -> trying to minimise it
  // range:
  int n = pages.size();
  int low = *max_element(pages.begin(), pages.end());
  // gets sum of array
  int high = accumulate(pages.begin(), pages.end(), 0);

  while (low <= high) {
    int mid = low + (high - low) / 2;

    // if it's possible to get the maxium pages to be 'mid'
    if (check(mid, pages, students)) {
      // try to find if it's possible in fewer
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  // initially was impossible, now points to just the possible value
  return low;
}

int main() {
  int n, students;
  cin >> n >> students;
  vector<int> pages(n);
  for (auto &i : pages)
    cin >> i;

  cout << allocate_pages(pages, students);
}
